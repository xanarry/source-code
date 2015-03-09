#include <stdio.h>
#include <stdlib.h>

void error(int e)
{
	if(e == 0)
		printf("input error\n");
	else
		printf("output error\n");
	exit(1);
}

int main(int argc, char const *argv[])
{
	FILE *in, *out;
	int tab;
	int i;
	char ch;
	char file1[10], file2[10];
	printf("input file1's name:");
	scanf("%s",file1);
	printf("input file2's name:");
	scanf("%s",file2);
	in = fopen(file1,"rb");
	if(in == NULL)
	{
		printf("can not open %s",file1);
		exit(0);
	}
	out = fopen(file2,"wb");
	if(out == NULL)
	{
		printf("can not open %s",file2);
		exit(0);
	}
	tab = 0;
	ch = fgetc(in);
	while(!feof(in))
	{
		if(ferror(in))
			error(0);
		if(ch == '\t')
		{
			for(i = tab; i < 8; i++)
			{
				putc(' ',out);
				if(ferror(out))
					error(1);
			}
			tab = 0;
		}
		else
		{
			putc(ch,out);
			if(ferror(out))
				error(1);
		}
		ch = fgetc(in);
	}
	fclose(in);
	fclose(out);
	return 0;
}
