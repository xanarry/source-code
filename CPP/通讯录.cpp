#include <iostream>
#include <cstring>
#include <cstdio>
#include <windows.h>
#include <cctype>
#include <conio.h>

using namespace std;

struct info
{
    char n[15];
    char s;
    int a;
    char p[15];
    char e[15];
    char t[15]; 
};

class contact
{
public:
    contact(char n[15] = "null", char s = 'F', int a = 19, char p[15] = "null", char e[15] = "example@za.com", char t[15] = "schoolmate");
    ~contact();
    contact(const contact &a);
    bool operator>(contact a);
    int static count;
    void display();
    friend bool writetofile(contact *, int);
    friend void BubleSort(contact *a, int len);
private:
    char name[15];
    char sex;
    int age;
    char phonenumber[15];
    char email[15];
    char type[15];
};

int contact::count = 0;

contact::contact(char n[15], char s, int a, char p[15], char e[15], char t[15])
{
    strcpy(name, n);
    sex = s;
    age = a;
    strcpy(phonenumber, p);
    strcpy(email, e);
    strcpy(type, t);
    count++;
}

contact::contact(const contact &a)
{
    strcpy(name, a.name);
    sex = a.sex;
    age = a.age;
    strcpy(phonenumber, a.phonenumber);
    strcpy(email, a.email);
    strcpy(type, a.type);
}

contact::~contact(){}

void contact::display()
{
    cout << "name : " << name << endl;
    cout << "sex  : " << sex << endl;
    cout << "age  : " << age << endl;
    cout << "phone: " << phonenumber << endl;
    cout << "email: " << email << endl;
    cout << "type : " << type << endl;
    cout << "-----------------------------\n" << endl;
}

bool contact::operator>(contact a)
{
    return string(name) > string(a.name);
}

bool writetofile(contact *temp, int len)
{
    FILE *fp = fopen("contact.txt", "a+");
    if (fp == NULL)
    {
        cout << "file error!";
        return 0;
    }

    info t;
    for (int i = 0; i < len; ++i)
    {
        strcpy(t.n, temp[i].name);;
        t.s = temp[i].sex;
        t.a = temp[i].age;
        strcpy(t.p, temp[i].phonenumber);
        strcpy(t.e, temp[i].email);
        strcpy(t.t, temp[i].type);
        fwrite(&t, sizeof(t), 1, fp);
    }
    fclose(fp);
}

void login();
void checkfirst();
void menu();
contact find_by_name();
contact find_by_phonenumber();
void display_all();
void inputinfo();
void modify();
void deleteone();

char _typearray[][15] = {"family", "schoolmate", "colleague", "friend", "other"};
char password[9];



int main()
{
    checkfirst();
    login();
    menu();
    system("PAUSE > nul");
    return 0;
}



void menu()
{
    system("cls");
    printf("\t1: 输入联系人信息\n");
    printf("\t2: 按姓名查找信息\n");
    printf("\t3: 按电话查找信息\n");
    printf("\t4: 显示所有联系人\n");
    printf("\t5: 修  改  信  息\n");
    printf("\t6: 删  除  信  息\n"); 
    printf("\t7: 退          出\n");
    printf("\t------------------\n");

    printf("\tplease input your choice: ");

    int choose;
    cin >> choose;

    switch(choose)
    {
        case 1:
            inputinfo(); 
            break;
        case 2:
            find_by_name(); 
            break;
        case 3:
            find_by_phonenumber(); 
            break;
        case 4:
            display_all(); 
            break;
        case 5:
            modify(); 
            break;
        case 6:
            deleteone(); 
            break;
        case 7:
            exit(0);
            break;
        default:
            system("cls"); 
            cout << "\tInput error! please check" << endl;
            menu();
    }
}


void checkfirst()                 
{
    FILE *fp, *fp1;
    char pwd[9], pwd1[9], ch;
    int i;
    if((fp=fopen("config.dat","rb"))==NULL)
    {
        cout << "to initialize, please input password for this system fist" << endl;  
        do
        {
            cout << "your password,(max length is 8):";
            for(i=0; i<8 && ((pwd[i]=getch())!=13); i++)
            {
               putchar('*');    
            } 
            
            cout << "\nconfirm your password:";
            for(i=0; i < 8 && ((pwd1[i] = getch()) != 13); i++)
            {
               putch('*');    
            } 
            
            pwd[i]=pwd1[i]='\0';
              
            if(strcmp(pwd,pwd1)!=0)
            {
               cout << "seems has some error, is your password right" << endl;
            }
            else
                break; 
        }while(1);
          
        if((fp1=fopen("config.dat","wb"))==NULL)
        {
            cout << "initialize failed " << endl;
            cout << "any key exit" << endl; 
            getchar();
            exit(1);
        }
        else
        {
            i=0;
            while(pwd[i])
            {
                putw(pwd[i],fp1);
                i++;
            }
            
            fclose(fp1);
            cout << "\nplease open it again" << endl;
            getchar();
            exit(1);
        }
    }
    else
    {
        i=0;
        while(!feof(fp) && i<8)
        {
            pwd[i++]=getw(fp);  
        }   
        
        pwd[i]='\0';
        
        if(i>=8)
        {
            i++;    
        }
        
        while(pwd[i]!=-1 && i>=0)
        {
            i--;    
        }
        pwd[i]='\0';
        strcpy(password,pwd);
    }
}

void login()                                         
{
    int i, n=3;
    char pwd[9];
    
    do
    {
        cout << "inut password:";
        for(i=0; i<8 && ((pwd[i]=getch())!=13); i++)
        {
            putch('*');
        }
        pwd[i]='\0';
        if(strcmp(pwd,password)!=0)
        {
            cout << "\ncheck you password and input again";
            system("cls");
            n--;
        }
        else
        {
            menu();
        }
    }while(n>0);
      
    if(n==0)
    {
        cout << "a crecte password is necessary" << endl;
        getch();
        exit(1);
    }
    else
    {
        cout << "\nwelcome to use" << endl;
        Sleep(1000);
        system("cls");
    }
}

void BubleSort(contact *a, int len)
{
    contact temp;
    for (int i = 0; i < len - 1; i++)
    {
        for (int j = 0; j < len - 1 - i; j++)
        {
            if (a[j] > a[j + 1])
            {
                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }
}

contact find_by_name()
{
    system("cls");
    cout << "find contact:" << endl;
    cout << "please input whitch name you wanna find: ";

    char _name[15];
    cin >> _name;

    info t;
    bool isfind = false;

    FILE *fp = fopen("contact.txt", "r");
    if (fp == NULL)
    {
        cout << "file error!" << endl;
        menu();
    }

    while( fread(&t, sizeof(info), 1, fp) )
    {
        if (strcmp(t.n, _name) == 0)
        {
            isfind = true;
            break;
        }
    }

    rewind(fp);
    fclose(fp);

    cout << "this is the search result" << endl;
    cout << "-----------------------------" << endl;
    if (isfind == true)
    {
        cout << "name : " << t.n << endl;
        cout << "sex  : " << t.s << endl;
        cout << "age  : " << t.a << endl;
        cout << "phone: " << t.p << endl;
        cout << "email: " << t.e << endl;
        cout << "type : " << t.t << endl;
    }
    else
        cout << "can't find anything" << endl;
    cout << "-----------------------------" << endl;

    cout << "press any key to return" << endl;
    getchar();
    getchar();
    system("cls");
    menu();
}

contact find_by_phonenumber()
{
    system("cls");
    cout << "find contact:" << endl;
    cout << "please input whitch phonenumber you wanna find: ";

    char _phonenumber[15];
    cin >> _phonenumber;
    
    info t;
    bool isfind = false;

    FILE *fp = fopen("contact.txt", "r");
    while( fread(&t, sizeof(info), 1, fp) )
    {
        if (strcmp(t.p, _phonenumber) == 0)
        {
            isfind = true;
            break;
        }
    }

    cout << "this is the search result" << endl;

    cout << "-----------------------------" << endl;
    if (isfind == true)
    {
        cout << "name : " << t.n << endl;
        cout << "sex  : " << t.s << endl;
        cout << "age  : " << t.a << endl;
        cout << "phone: " << t.p << endl;
        cout << "email: " << t.e << endl;
        cout << "type : " << t.t << endl;
    }
    else
        cout << "can't find anything" << endl;
    cout << "-----------------------------" << endl;

    cout << "press any key to return" << endl;
    getchar();
    getchar();
    system("cls");
    menu();
}

void inputinfo()
{
    system("cls");
    cout << "now you can input contact information" << endl;
    cout << "when name is equal to \"null\" to break\n" << endl;

    contact *new_contact = new contact[1000];
    contact temp;

    char name[15], email[15], phonenumber[15];
    char sex;
    int age;
    int type;
    int count = 0;

    while (1)
    {
        cout << "input name first: ";
        cin >> name;
        if (strcmp(name, "null") == 0)
        {
            break;
        }
        cout << "input sex: ";
        cin >> sex;
        cout << "input age: ";
        cin >> age;
        cout << "input phonenumber: ";
        cin >> phonenumber;
        cout << "input email: ";
        cin >> email;
        cout << "1:family, 2:schoolmate, 3:colleague, 4:friend, 5:other" << endl;
        cout << "choose a type: ";
        cin >> type;
        new_contact[count] = contact(name, sex, age, phonenumber, email, _typearray[type - 1]);
        count ++;
    }

    writetofile(new_contact, count);

    system("cls");
    cout << "\toperate seccessful" << endl;
    cout << "returning" << endl;
    Sleep(2000); 
    system("cls");
    menu();
}

void display_all()
{
    system("cls");
    info t;
    int count = 0;
    contact contact_list[1000];
    FILE *fp = fopen("contact.txt", "r");
    if (fp == NULL)
    {
        cout << "file error" << endl;
        system("cls");
        menu();
    }

    rewind(fp);
    while( fread(&t, sizeof(info), 1, fp) )
    {
        contact_list[count] = contact(t.n, t.s, t.a, t.p, t.e, t.t);
        count++;

    }

    fclose(fp);
    BubleSort(contact_list, count);

    for (int i = 0; i < count; ++i)
    {
        contact_list[i].display();

    }   

    cout << "you total has-> " << count << " <-contacts" << endl;
    cout << "\npress any key to return";
    getchar();
    getchar();
    system("cls");
    menu();
}

void modify()
{
    system("cls");
    cout << "find contact:" << endl;
    cout << "please input whitch name or phonenumber you wanna modify: ";
    char input[15];
    cin >> input;

    info t[1000];
    int count = 0;
    int index;
    bool isfind = false;
    FILE *fp = fopen("contact.txt", "r");
    if (fp == NULL)
    {
        cout << "file error! modify failed" << endl;
        system("cls");
        menu();
    }

    while( fread(&t[count], sizeof(info), 1, fp) )
    {
        count++;
    }

    rewind(fp);
    fclose(fp);

    for (int i = 0; i < count; ++i)
    {
        if ( (strcmp(t[i].n, input) == 0) || (strcmp(t[i].p, input) == 0) )
        {
            isfind = true;
            index = i;
            break;
        }
    }

    if (isfind == true)
    {   
        cout << "\t-----------------------------" << endl;
        cout << "\tname : " << t[index].n << endl;
        cout << "\tsex  : " << t[index].s << endl;
        cout << "\tage  : " << t[index].a << endl;
        cout << "\tphone: " << t[index].p << endl;
        cout << "\temail: " << t[index].e << endl;
        cout << "\ttype : " << t[index].t << endl;
        cout << "\t-----------------------------" << endl;
        cout << "we find this！you sure you wanna to modify this(y or n):" << endl;

        char choose;
        cin >> choose;

        if (toupper(choose) == 'Y')
        {
            cout << "\twhitch item you wanna change" << endl;
            cout << "\tname : 1" << endl;
            cout << "\tsex  : 2" << endl;
            cout << "\tage  : 3" << endl;
            cout << "\tphone: 4" << endl;
            cout << "\temail: 5" << endl;
            cout << "\ttype : 6" << endl;
            cout << "\t-------------" << endl;
            cout << "\tinput a number: ";

            int temp;
            cin >> temp;

            switch(temp)
            {
                case 1:
                    cout << "input a new name: ";
                    char name[15];
                    cin >> name;
                    strcpy(t[index].n, name); 
                    break;
                case 2:
                    cout << "input a new sex: ";
                    char sex;
                    cin >> sex;
                    t[index].s = sex; 
                    break;
                case 3:
                    cout << "input a new age: ";
                    int age;
                    cin >> age;
                    t[index].a = age; 
                    break;
                case 4:
                    cout << "input a new phonenumber: ";
                    char phonenumber[15];
                    cin >> phonenumber;
                    strcpy(t[index].p, phonenumber);
                    break;
                case 5:
                    cout << "input a new email: ";
                    char email[15];
                    cin >> email;
                    strcpy(t[index].e, email); 
                    break;
                case 6:
                    cout << "1:family, 2:schoolmate, 3:colleague, 4:friend, 5:other" << endl;
                    cout << "input a new type: ";
                    int type;
                    cin >> type;
                    strcpy(t[index].t, _typearray[type - 1]);
                    break;
                default:
                    cout << "that means you'll exit your operation";
                    cout << "returning" << endl;
                    Sleep(1500);
                    system("cls");
                    fclose(fp);
                    menu();
            }

            FILE *fp = fopen("contact.txt", "w+");
            if (fp == NULL)
            {
                cout << "file error! modify failed" << endl;
                system("cls");
                menu();
            }

            for (int i = 0; i < count; ++i)
            {
                fwrite(&t[i], sizeof(info), 1, fp);
            }
            cout << "operate seccessful" << endl;
            fclose(fp);
        }

        if (toupper(choose) == 'N')
        {
            cout << "press any key to return to menu" << endl;
            getchar();
            getchar();
            system("cls");
            fclose(fp);
            menu();
        }
    }
    else
        cout << "can't find anything" << endl;
    cout << "-----------------------------" << endl;

    cout << "press any key to return" << endl;
    getchar();
    getchar();
    system("cls");
    fclose(fp);
    menu();
}


void deleteone()
{
    system("cls");
    cout << "find contact:" << endl;
    cout << "please input whitch name or phonenumber you wanna delete: ";
    char input[15];
    cin >> input;

    info t[1000];
    int count = 0;
    int index;
    bool isfind = false;
    FILE *fp = fopen("contact.txt", "r");
    while( fread(&t[count], sizeof(info), 1, fp) )
    {
        count++;
    }

    fclose(fp);
    rewind(fp);

    for (int i = 0; i < count; ++i)
    {
        if ( (strcmp(t[i].n, input) == 0) || (strcmp(t[i].p, input) == 0) )
        {
            isfind = true;
            index = i;
            break;
        }
    }

    if (isfind == true)
    {   
        cout << "-----------------------------" << endl;
        cout << "name : " << t[index].n << endl;
        cout << "sex  : " << t[index].s << endl;
        cout << "age  : " << t[index].a << endl;
        cout << "phone: " << t[index].p << endl;
        cout << "email: " << t[index].e << endl;
        cout << "type : " << t[index].t << endl;
        cout << "-----------------------------" << endl;
        cout << "we find this！you sure you wanna to delete this(y or n):" << endl;

        char choose;
        cin >> choose;

        if (toupper(choose) == 'Y')
        {
            FILE *fp = fopen("contact.txt", "w+");
            if (fp == NULL)
            {
                cout << "file error! modify failed" << endl;
                system("cls");
                menu();
            }

            for (int i = 0; i < count; ++i)
            {
                if (i != index)
                {
                    fwrite(&t[i], sizeof(info), 1, fp);
                }
            }

            cout << "operate seccessful" << endl;
            fclose(fp);
        }
        if (toupper(choose) == 'N')
        {
            cout << "press any key to return to menu" << endl;
            getchar();
            getchar();
            system("cls");
            fclose(fp);
            menu();
        }
    }
    else
        cout << "can't find anything" << endl;
    cout << "-----------------------------" << endl;

    cout << "press any key to return" << endl;
    getchar();
    getchar();

    system("cls");
    fclose(fp);
    menu();
}
