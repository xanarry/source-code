#include <iostream>
#include <windows.h>
#include <conio.h>
#include <time.h>
#include <stdio.h>

using namespace std;

void B(int a,int b)
{
	if(a==0){Beep((DWORD)0,(DWORD)(b*100));return;} 
	float r,s[7]={261.6,293.7,329.6,349.2,392,440,493.9};
	if(a>=1 && a<=7)
		r=0.5;
	else if(a>=11 && a<=77)
	{
		a%=10;
		r=1;
	}
	else if(a>=111 && a<=777)
	{
		a%=10;
		r=2;
	} 	
	b*=100;
	Beep((DWORD)s[a-1]*r,(DWORD)b);
}

void LoadGame(double &score)
{
	FILE *data1;
	data1 = fopen("donttouchwhite.txt","r");
    if(data1!=NULL){fscanf(data1,"%lf",&score);}else{score=9999999;} 
    fclose(data1);
}

void SaveGame(double score)
{
	FILE *data2;
	data2 = fopen("donttouchwhite.txt","w");
	fprintf(data2,"%lf",score);
	fclose(data2);
}


void b1()
{
	cout<<"###############"<<endl;
	cout<<"###############"<<endl;
	cout<<"###############"<<endl;
	cout<<"###############"<<endl;
	cout<<"###############"<<endl;
	cout<<"###############"<<endl;
}
void b2()
{
	cout<<"                ###############"<<endl;
	cout<<"                ###############"<<endl;
	cout<<"                ###############"<<endl;
	cout<<"                ###############"<<endl;
	cout<<"                ###############"<<endl;
	cout<<"                ###############"<<endl;
}
void b3()
{
	cout<<"                                ###############"<<endl;
	cout<<"                                ###############"<<endl;
	cout<<"                                ###############"<<endl;
	cout<<"                                ###############"<<endl;
	cout<<"                                ###############"<<endl;
	cout<<"                                ###############"<<endl;
}
void b4()
{
	cout<<"                                                ###############"<<endl;
	cout<<"                                                ###############"<<endl;
	cout<<"                                                ###############"<<endl;
	cout<<"                                                ###############"<<endl;
	cout<<"                                                ###############"<<endl;
	cout<<"                                                ###############"<<endl;
}


int show(int &a,int &b,int &c,int &d,int x,int t)
{
	system("cls");
	int i;
	if(t<94)
	{ 
		switch(d)
		{
		    case 1:
		    	b1();
			    break;
			case 2:
		    	b2();
			    break;
			case 3:
		    	b3();
			    break;
			case 4:
		    	b4();
			    break;
		} 
	
		switch(c)
		{
		    case 1:
		    	b1();
			    break;
			case 2:
		    	b2();
			    break;
			case 3:
		    	b3();
			    break;
			case 4:
		    	b4();
			    break;
		} 

		switch(b)
		{
		    case 1:
		    	b1();
			    break;
			case 2:
		    	b2();
			    break;
			case 3:
		    	b3();
			    break;
			case 4:
		    	b4();
			    break;
		} 

		switch(a)
		{
		    case 1:
		    	b1();
			    break;
			case 2:
		    	b2();
			    break;
			case 3:
		    	b3();
			    break;
			case 4:
		    	b4();
			    break;
		} 
	}
	
	else
	{
		cout<<endl<<endl<<endl<<endl<<endl<<endl;
		if(t<96)
		{ 
			switch(c)
			{
			    case 1:
			    	b1();
				    break;
				case 2:
			    	b2();
				    break;
				case 3:
			    	b3();
				    break;
				case 4:
			    	b4();
				    break;
			} 
		}
		else
		{
			cout<<endl<<endl<<endl<<endl<<endl<<endl;
		} 

		if(t<98)
		{ 
			switch(b)
			{
			    case 1:
			    	b1();
				    break;
				case 2:
			    	b2();
				    break;
				case 3:
			    	b3();
				    break;
				case 4:
			    	b4();
				    break;
			} 
		}
		else
		{
			cout<<endl<<endl<<endl<<endl<<endl<<endl;
		} 
		if(t<100)
		{ 
			switch(a)
			{
			    case 1:
			    	b1();
				    break;
				case 2:
		 	   	b2();
				    break;
				case 3:
			    	b3();
				    break;
				case 4:
			    	b4();
				    break;
			} 
		}
		else
		{
			cout<<"............................................................"<<endl<<"............................................................"<<endl<<"............................................................"<<endl<<"............................................................"<<endl<<"............................................................"<<endl;
		} 
	} 
	
	i=a;
	a=b;b=c;c=d;d=x;
	
	cout<<endl<<" 1111111111111   2222222222222   3333333333333   4444444444444"<<endl;
		
	return i;
}

 
void win(double score,double max)
{
	system("cls");
    cout<<"                                                            "<<endl;
	cout<<"        ######  ######  ######  ######  ######              "<<endl;
	cout<<"        ##      ##      ##  ##  ##  ##  ##                  "<<endl;
	cout<<"        ######  ##      ##  ##  ######  ######              "<<endl;
	cout<<"            ##  ##      ##  ##  ## ##   ##                  "<<endl;
	cout<<"        ######  ######  ######  ##  ##  ######              "<<endl;
	cout<<"                                                            "<<endl;
	cout<<"                   【 "<<score<<" 秒】                            "<<endl;
	cout<<"                                                            "<<endl;
	cout<<"                                                            "<<endl;
	cout<<"           #####   ######  ######  ######                   "<<endl;
	cout<<"           ##  ##  ##      ##        ##                     "<<endl;
	cout<<"           #####   ######  ######    ##                     "<<endl;
	cout<<"           ##  ##  ##          ##    ##                     "<<endl;
	cout<<"           #####   ######  ######    ##                     "<<endl;
	cout<<"                                                            "<<endl;
	cout<<"                   （ "<<max<<" 秒）                                "<<endl;
	cout<<"                                                            "<<endl;
	cout<<"                                 Designed by Moenen         "<<endl;
	cout<<"                                     QQ 1182032752          "<<endl<<endl<<"\t\t\t\t";
	
	B(333,2);B(333,2);B(111,3);B(111,1);B(333,2);B(333,2);B(555,3);B(0,1);
	B(333,2);B(333,2);B(111,3);B(111,1);B(333,2);B(333,2);B(555,3);B(0,1);
	
	system("PAUSE");
}


void fail()
{
	
	system("cls");
	
	cout<<"                                                                 "<<endl;
	cout<<"       ###                                 ###                   "<<endl;
	cout<<"         ###                             ###                     "<<endl;
	cout<<"           ###                         ###                       "<<endl;
	cout<<"             ###                     ###                         "<<endl;
	cout<<"               ###                 ###                           "<<endl;
	cout<<"                 ###             ###                             "<<endl;
	cout<<"                   ###         ###                               "<<endl;
	cout<<"                     ###     ###                                 "<<endl;
	cout<<"                       ### ###                                   "<<endl;
	cout<<"                         ###                                     "<<endl;
	cout<<"                       ### ###                                   "<<endl;
	cout<<"                     ###     ###                                 "<<endl;
	cout<<"                   ###         ###                               "<<endl;
	cout<<"                 ###             ###                             "<<endl;
	cout<<"               ###                 ###                           "<<endl;
	cout<<"             ###                     ###                         "<<endl;
	cout<<"           ###                         ###                       "<<endl;
	cout<<"         ###                             ###                     "<<endl;
	cout<<"       ###                                 ###                   "<<endl<<endl;
	
	Beep((DWORD)1000,(DWORD)500);
	
}



void welcome()
{
	 
	cout<<"                                                            "<<endl;
	cout<<"          #####                                                      "<<endl;
	cout<<"          ##  ##                  #    ##                            "<<endl;
	cout<<"          ##   ##  #####  #####  #   ######                          "<<endl;
	cout<<"          ##   ##  ## ##  ##  #        ##                            "<<endl;
	cout<<"          ##   ##  ## ##  ##  #        ##                            "<<endl;
	cout<<"          ######   #####  ##  #        ####                          "<<endl<<endl;
	cout<<"                                      ##                    "<<endl;
	cout<<"           ##                         ##                    "<<endl;
	cout<<"         ######  #####  ##  #  #####  #####                 "<<endl;
	cout<<"           ##    ## ##  ##  #  ##     ##  #                 "<<endl;
	cout<<"           ##    ## ##  ##  #  ##     ##  #                 "<<endl;
	cout<<"           ####  #####  #####  #####  ##  #                 "<<endl;
	cout<<"                                                            "<<endl;
	cout<<"                   ##     ##                        "<<endl;
	cout<<"                   ##           ##    ######        "<<endl;
	cout<<"          ## # ##  #####  ##  ######  ##   #        "<<endl;
	cout<<"          ## # ##  ##  #  ##    ##    ######        "<<endl;
	cout<<"          ## # ##  ##  #  ##    ##    ##            "<<endl;
	cout<<"           #####   ##  #  ##    ####  ######        "<<endl<<endl;
	cout<<"  游戏规则：按下 1、2、3、4 数字键来搞定最下面的块儿，越快越好丫！"<<endl<<endl;
	cout<<"\t\t";
	
	system("PAUSE");
}


int main()
{
    
    welcome();

	int i,a,b,c,d,x,min,sec,mmsec,t,p,f;
	double score,max;
	char ch;
    SYSTEMTIME time; 
    clock_t start, end;
    
    LoadGame(max);
    
S:;	
	
	
	GetLocalTime( &time ); 
    i=time.wMilliseconds;
	a=(i%4)+1;
	f=a;
	b=(i/10%4)+1;
	c=(i/100%4)+1;
	d=(a+b+c)%4+1;
	
/////////////////////////////////////////////////////////////////////////
		t=0;
		GetLocalTime( &time ); 
	    x = (time.wMilliseconds/100 % 4) + 1;
    	p = show(a,b,c,d,x,t);
	    
		j:;
		cout<<endl<<"按下数字键"<<f<<"后开始计时";
		ch = getch();
	    switch(ch)
	    {
	    	case 49:
	    		if(p!=1){fail();goto S;} 
				break;
			case 50:
				if(p!=2){fail();goto S;} 
			    break;
			case 51:
				if(p!=3){fail();goto S;} 
			    break;
			case 52:
				if(p!=4){fail();goto S;} 
			    break;
			default:
				goto j;
	    }
	    Beep(700,70);
		t++;
	    
	
	
//////////////////////////////////////	
	
	start = clock();
	for(t=2;t<100;t++)
	{
	    
		GetLocalTime( &time ); 
	    x = (time.wMilliseconds/100 % 4) + 1;
    	p = show(a,b,c,d,x,t);
	    
		J:;
		ch = getch();
	    switch(ch)
	    {
	    	case 49:
	    		if(p!=1){fail();goto S;} 
			    break;
			case 50:
				if(p!=2){fail();goto S;} 
			    break;
			case 51:
				if(p!=3){fail();goto S;} 
			    break;
			case 52:
				if(p!=4){fail();goto S;} 
			    break;
			default:
				goto J;
	    }
	    Beep(700,70);
		t++;
	}
	end = clock();
	
	score = (double)(end - start) / ((clock_t)1000);
	if(score<max)
	{
		SaveGame(score);
		max=score;
	} 
	win(score,max);
	
	
goto S;	
	
	return 0;
}
