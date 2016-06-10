/**
 * Author:      xanarry
 * DateTime:    2016/6/10
 * Description: this is a simple shell support std IO redirection and multiply commands execute
 */
#include <stdio.h> 
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <wait.h>

struct CMD
{
    char program[128]; //execute program
    char strArgv[128][128]; //argvs
    char *argv[128]; //pointers of argvs, point to strArgvs, passed to execl system call
    char strRedirection[3][128]; //redirection files, 0(stdin), 1(stdou), 2(stderr, not implement)
    char *redirection[128];
};

int copystr(char src[], char dest[], int start, int end)
{
    /*copy str from src to dest between [start, end)*/
    int i = 0;
    for (; start < strlen(src) && start < end; start++, i++)
        dest[i] = src[start];
    dest[i] = '\0';
    return i;
}

char *trim(char *src)
{
    /*del prefix and suffix black space*/
    short start = 0;
    while (src[start] == ' ') //del prefix blank space
        start++;
    src += start;

    for (int i = strlen(src) - 1; i >= 0; i--)
    {
        if (src[i] != ' ')
        {
            src[++i] = '\0'; //del suffix blank space
            break;
        }
    }
    return src;
}

int parseCmdLine(char cmdLine[], char argv[][128])
{
    int i = 0; /*string index*/
    int t = 0; /*array index*/
    int start = 0; /*last start position*/
    char tempBuf[512];

    while (cmdLine[i])
    {
        if (cmdLine[i] == ' ' || cmdLine[i] == '<' || cmdLine[i] == '>')
        {
            copystr(cmdLine, tempBuf, start, i);
            if (strlen(tempBuf) > 0)
                strcpy(argv[t++], tempBuf);
            if (cmdLine[i] == '<')
                strcpy(argv[t++], "<");
            else if (cmdLine[i] == '>')
                strcpy(argv[t++], ">");
            start = i + 1;
        }
        i++;
    }

    if (start < strlen(cmdLine))
        copystr(cmdLine, argv[t++], start, strlen(cmdLine));
    return t;
}


void inputCommandLine(char cmdLineBuf[])
{
    /*just like getline func*/
    int i = 0;
    while ((cmdLineBuf[i++] = getchar()) != '\n');//get whole line
    cmdLineBuf[--i] = '\0';//get rid of last \n
}

int splitCommandLine(char *cmdLine, char cmdLineGrop[][128], int *relation) /*such as ls a && ls b || touch /bin/t.txt*/
{
    /*split multiply command lines like this:
       cmd1 && cmd2 || cmd3 && cmd4 || cmd5*/
    int cmdcnt = 0;
    int boolcnt = 0;
    int i = 0;
    int start = 0;

    while (i < strlen(cmdLine))
    {
        if (i + 1 < strlen(cmdLine) && cmdLine[i] == '&' && cmdLine[i + 1] == '&')
        {
            relation[boolcnt++] = 1;
            copystr(cmdLine, cmdLineGrop[cmdcnt++], start, i);
            start = i + 2;
        }
        else if (i + 1 < strlen(cmdLine) && cmdLine[i] == '|' && cmdLine[i + 1] == '|')
        {
            relation[boolcnt++] = 0;
            copystr(cmdLine, cmdLineGrop[cmdcnt++], start, i);
            start = i + 2;
        }
        i++;
    }
    copystr(cmdLine, cmdLineGrop[cmdcnt++], start, i);
    return cmdcnt;
}

struct CMD newCmd()
{
    /*init a new cmd struct*/
    struct CMD cmd;
    strcpy(cmd.program, "");
    memset(cmd.argv, 0, sizeof(cmd.argv));
    memset(cmd.redirection, 0, sizeof(cmd.redirection));
    return cmd;
}


void showCmd(struct CMD cmd)
{
    /*
    this func is used to show a cmd detail to make debug easer
    not use in real environment
    */
    printf("exe: %s\n", cmd.program);
    if (cmd.redirection[0] != NULL)
        printf("stdin: %s\n", cmd.redirection[0]);
    if (cmd.redirection[1] != NULL)
        printf("stdout: %s\n", cmd.redirection[1]);
    printf("argv: ");
    for (int i = 0; cmd.argv[i]; i++)
        printf("%s ", cmd.argv[i]);
    printf("\n");
}

int main()
{
    char cmdLine[4096];
    char cmdLineGrop[128][128];
    struct CMD cmds[128];
    int relation[128]; //save relation between two command, "&&" and "||" but no "|", no pipe
    char lastDir[128];

    while (1)
    {
        char cwd[128]; //current work directory
        getcwd(cwd, sizeof(cwd));
        printf(":%s$> ", cwd);
        inputCommandLine(cmdLine); //input a command line
        if (strcmp(trim(cmdLine), "bye") == 0)
            break;

        /*split multiply command to single comman set*/
        int cmdcnt = splitCommandLine(cmdLine, cmdLineGrop, relation);

        /*for each single command structed it and saved in a struct type*/
        for (int li = 0; li < cmdcnt; li++)
        {  
            cmds[li] = newCmd();
            /*parsing earch single command line here*/
            int argcnt = parseCmdLine(cmdLineGrop[li], cmds[li].strArgv);
            strcpy(cmds[li].program, cmds[li].strArgv[0]);//executable name
            int argvCnt = 0;
            for (int i = 0; i < argcnt; i++)
            {
                if (strcmp(cmds[li].strArgv[i], "<") == 0) /*stdin rediretion*/
                    cmds[li].redirection[0] = cmds[li].strArgv[++i];
                else if (strcmp(cmds[li].strArgv[i], ">") == 0) /*stdout rediretion*/
                    cmds[li].redirection[1] = cmds[li].strArgv[++i];
                else if (strlen(cmds[li].strArgv[i]) != 0) /*nomal parameters*/
                    cmds[li].argv[argvCnt++] = cmds[li].strArgv[i];
            }
            cmds[li].argv[argvCnt] = (char *) NULL;
        }

        /*
        for (int i = 0; i < cmdcnt; i++) //this is used to check cmdLine parse result
        {
            puts("====================================");
            showCmd(cmds[i]);
            puts("====================================");
            if (i != cmdcnt - 1)
            {
                if (relation[i - 1] == 1) puts("&&");
                else puts("||");
            }
        }
        */
        
        for (int i = 0; i < cmdcnt; )
        {
            if (strcmp(cmds[i].program, "cd") == 0) //cd need a system call to implement
            {
                if (strlen(cmds[i].strArgv[1]) > 0)
                {
                    if (strcmp(cmds[i].strArgv[1], "_") == 0)
                        chdir(lastDir);
                    else
                    {
                        getcwd(lastDir, sizeof(lastDir)); /*remeber last directory*/
                        puts(lastDir);
                        chdir(cmds[i].strArgv[1]);
                    }
                }
                i++;
                continue;
            }

            int pid = fork();
            if (pid < 0)
            {
                perror("fork");
                exit(-1);
            }
            else if (pid == 0)//child process
            {
                if (cmds[i].redirection[0]) /*redirect stdin*/
                {
                    if (access(cmds[i].redirection[0], F_OK) != -1) // file exists
                        freopen(cmds[i].redirection[0], "r", stdin);
                    else // file doesn't exist
                    {
                        perror(cmds[i].redirection[0]);
                        exit(-1);
                    }
                }
                    
                if (cmds[i].redirection[1]) /*redirect stdout*/
                    freopen(cmds[i].redirection[1], "w", stdout);

                if (execvp(cmds[i].program, cmds[i].argv) < 0) /*execute cmd*/
                {
                    perror(cmds[i].program);
                    exit(-1);
                }
                return 0;
            }
            else //parent process
            {
                int status;
                wait4(pid, &status, 0, NULL);
                if (status == 0)//last cmd execute successful
                {
                    /*check the next cmd*/
                    if (relation[i] == 1) /*[1 -> &&] and no nothing, continue to execute next cmd*/
                        i++;
                    else /*[0 -> ||] execute a cmd successfully, stop to continue*/
                        break;
                }
                else //error occured in executing last cmd
                    while (relation[i++] != 0);/*check and skip to the next valid cmd*/
            }
        }
    }
    return 0;
}

/*
ls   -abl   -a   -es   -esf 

wc -w <in> /dev/null

wc -w<in>out && cat out

rm out && ./add < in > out && cat out

ls -al && cat<1.in>2.out     &&   wc -w < 1.in > out.txt ||      ls   -l   -a  -h  
     ls   -l   -a  -h  || touch test.txt

cat > input && wc -wc input > out && cat out

asdfa || wc -w < in>out && cat out

ps && ls a || ls a || ls a || ls -a 

ps || ls a || ls a || ls -a 
*/