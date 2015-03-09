#include <windows.h>
#include <stdio.h>

int main()
{
	HWND h;
	int x,y,cx,cy;
	char szConsoleTitle[100];
	GetConsoleTitle(szConsoleTitle, 100) ;
	printf("ConsoleTitle:%s\n", szConsoleTitle);
	h=FindWindow(NULL,szConsoleTitle); 
	printf("Console handle:%d\n",h);
	printf("how to redisplay the console window?x,y,cx,cy:");
	scanf("%d%d%d%d",&x,&y,&cx,&cy);
	SetWindowPos(h,HWND_TOP,x,y,cx,cy,SWP_SHOWWINDOW);
	return 0;
}	