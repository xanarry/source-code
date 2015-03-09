#include <stdio.h>
int main()
{
	FILE *fp;
	fp = fopen("t.jpg","r");
	if(fp != NULL)
	{
		printf("ptr :%s\n",fp->_ptr);
		printf("cnt :%d\n",fp->_cnt);
		printf("base:%s\n",fp->_base); 
		printf("flag:%d\n",fp->_flag);
		printf("file:%d\n",fp->_file);
		printf("charbuf :%d\n",fp->_charbuf);
		printf("tmpfname:%s\n",fp->_tmpfname);
	}
	else
		printf("failed\n");
	return 0;
}
