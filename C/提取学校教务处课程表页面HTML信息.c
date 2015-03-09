#include <stdio.h>
#include <string.h>

void getValid(char *dest, char *src);

int main()
{
    char get[200], dest[200];
    FILE *fpin = fopen("syllabus.tmp","r");
    FILE *fpout = fopen("getOnce.txt", "w");
    while (!feof(fpin))
    {
    	fscanf(fpin, "%s\n", get);
    	if (strlen(get) >= 15 && strstr(get, "align") && strcmp(get+(strlen(get) - 4), "FONT"))
    	{
    		getValid(dest, get+15);
    		fprintf(fpout, "%s\n", dest);
    	}
    }

    fclose(fpout);
    fclose(fpin);
    fpout = fopen("___syllabus.dat", "w");
    fpin = fopen("getOnce.txt", "r");

    int count = 0;
    int t = 0;
    char temp[8][100];

    while (!feof(fpin))
    {
        fscanf(fpin, "%s", get);
        if (count < 8)
        {
            strcpy(temp[count], get);
            count++;
        }
        else
        {
            count = 0;
            char convertTemp[100];
            int i;
            for (i = 0; i < strlen(temp[7]) - 4; i++)
            {
                convertTemp[i] = temp[7][i];
            }
            convertTemp[i] = '\0';
            fprintf(fpout, "%-25s    %-18s    %-4s    %-20s\n", temp[0], temp[5], temp[6], convertTemp);
            strcpy(temp[count], get);
            count++;
        }
    }
    fclose(fpout);
}

void getValid(char *dest, char *src)
{
	int i = 0;
	int t = 0;
	for (i = 0; *(src + i) != '<' && *(src + i) != '>'; i++)
		dest[i] = *(src + i);
	dest[i] = '\0';
}
