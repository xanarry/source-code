#include <iostream>   
#include <windows.h>
#include <conio.h>   
#include <string>
#include <time.h>
#include <stdio.h>

using namespace std;   
char C;
int I,J,N,SCORE;
string S;//60 X 20
enum Dir{Up,Down,Left,Right};
Dir D;   
bool OOXX;

DWORD WINAPI Fun(LPVOID lpParamter)   
{      
     
    while(1){
	    C=getch();
	    if(C==32){OOXX=true;}else{OOXX=false;
	    switch(C){
	    	case 72:
			    if(D!=Down){D=Up;} 
		    	break;
	    	case 80:
			    if(D!=Up){D=Down;}
				break;
	    	case 75:
			    if(D!=Right){D=Left;}
				break;
	    	case 77:
			    if(D!=Left){D=Right;}
				break;
	    }
		} 
	    Beep((DWORD)0,(DWORD)50);
	}
}    




void B(int a,int b)
{
	if(a==0){Beep((DWORD)0,(DWORD)(b*100));return;} 
	float r,s[7]={261.6,293.7,329.6,349.2,392,440,493.9};
	if(a>=1 && a<=7){r=0.5;}
	else if(a>=11 && a<=77){a%=10;r=1;}
	else if(a>=111 && a<=777){a%=10;r=2;} 	
	b*=100;
	Beep((DWORD)s[a-1]*r,(DWORD)b);
}

void LoadGame(int &N,int &SCORE)
{
	FILE *data1;
	data1 = fopen("C:/Windows/System32/Snake.txt","r");
    if(data1!=NULL){fscanf(data1,"%d%d",&N,&SCORE);}else{N=1;SCORE=2;} 
    fclose(data1);
}

void SaveGame(int N, int SCORE)
{
	FILE *data2;
	data2 = fopen("C:/Windows/System32/Snake.txt","w");
	fprintf(data2,"%d %d %d",N,SCORE);
	fclose(data2);
}


inline void show(string s,int n){
	system("cls");
	int i;
	string temp;
	cout<<"\t\t第 "<<N<<" 关   Score = "<<SCORE<<"    还需 "<<5*N-n<<" 过关"<<endl;
	for(i=0;i<20;i++){
		temp.clear();
		temp+=s;
		s.erase(0,60);
		temp.erase(60,temp.length()-60);
		cout<<temp<<endl;
	}	
}

inline void rand(int &x,int &y){
    SYSTEMTIME time; 
	GetLocalTime( &time ); 
	x=(time.wMilliseconds%30)*2;
    y=(time.wMilliseconds/10%20);
}

inline void loadmaze(string &s){
	S.clear();
	s+="                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                ";
}


void welcome(){
	
	
	
	cout<<"                                                            "<<endl;
	cout<<"     ######   ##   ##      ##      ##  ##   ######          "<<endl;
	cout<<"     ##       ###  ##     ####     ## ##    ##              "<<endl;
	cout<<"     ######   ## # ##    ##  ##    ####     ######          "<<endl;
	cout<<"         ##   ##  ###   ########   ## ##    ##              "<<endl;
	cout<<"     ######   ##   ##  ##      ##  ##  ##   ######          "<<endl;
	cout<<"                                                            "<<endl;
	cout<<"                                                            "<<endl;
	cout<<"                                                            "<<endl;
	cout<<"                            * Designed by M_oenen           "<<endl;
	cout<<"                                                            "<<endl;
	cout<<"                            * QQ 1182032752                 "<<endl;
	cout<<"                                                            "<<endl;
	cout<<"                            * I'm single♂now!!!           "<<endl;
	cout<<"                                                            "<<endl;
	cout<<"                            * 按下↑↓←→键控制蛇，别咬到自己就行"<<endl<<endl<<endl<<endl;
	
	
	cout<<"\t\t<< 按空格键继续 >>";
	
	while(OOXX==false){} 
	system("cls");
}

struct body{
	int i,j;
	body *next,*prev;
};

void win(){
	system("cls");
	cout<<"\n\n\n\n\n\n\n\t\t\t恭 喜 过 关\n\n\t\t";
	B(11,4);B(33,4);B(55,4);B(111,10);B(0,2);
	cout<<"<< 按空格键继续 >>";
	
	while(OOXX==false){} 
}

void lost(){
	B(0,16);
	system("cls");
	cout<<"\n\n\n\n\n\n\n\t\t咬 到 自 己 了 ！ ！ ！\n\n\t\t";
	
    B(66,4);B(0,2);B(55,4);B(0,2);B(44,4);B(0,2);B(33,10);B(0,2);	
    
	cout<<"<< 按空格键继续 >>";
	
	while(OOXX==false){} 
}

int main(){        
    
	HANDLE hThread = CreateThread(NULL, 0, Fun, NULL, 0, NULL); 
  
    
    welcome();
    
    LoadGame(N,SCORE);
    SaveGame(N,SCORE);
    
    int i,j,x,y,speed,n;
    bool eat;
    body *s,*head,*tail,*t;
    
START:;	
	
	system("cls");
	cout<<"\n\n\n\n\n\n\n\t\t\t第    "<<N<<"    关！\n\n\t\t\tSCORE = "<<SCORE<<endl;
	B(333,2);B(333,2);B(111,3);B(111,1);B(333,2);B(333,2);B(555,3);B(0,1);
	B(333,2);B(333,2);B(111,3);B(111,1);B(333,2);B(333,2);B(555,3);B(0,1);
	system("cls");
	
	if(N<=30){speed = 250-5*N;}else{speed = 100;} 
    D=Up;
    n=0;
    i=10;
	j=30;
	head = new body;
	s = new body;
	tail = new body;
	t = new body;
	head->i = i;
	head->j = j;
	head->next = s;
	head->prev = NULL;
	s->next = tail;
	s->prev = head;
	s->i = 11;
	s->j = 30;
	tail->next = NULL;
	tail->prev = s;
	tail->i=12;
	tail->j=30;
	eat = false;
	
	
	
	rand(x,y);
	while(1){
	    loadmaze(S);
		
		tail->i = head->i;
	    tail->j = head->j;
		s = tail->prev;
		head->next->prev = tail;
		tail->next = head->next;
		tail->prev = head;
		head->next = tail;
		tail = s;
		tail->next = NULL;
		
		
		switch(D){
			default:
			case Up:
				if(head->i==0){head->i=19;}else{head->i--;} 
				break;
			case Down:
				if(head->i==19){head->i=0;}else{head->i++;} 
				break;
			case Left:
				if(head->j==0){head->j=58;}else{head->j-=2;} 
				break;
			case Right:
				if(head->j==58){head->j=0;}else{head->j+=2;} 
				break;
		}
	    
		S[(head->i)*60+head->j]='O';
		
		
		
		S[y*60+x]='.';
		if(head->i==y&&head->j==x){ 
		    SCORE++;
		    eat = true;
		    n++;
			s = new body;
			tail->next = s;
		    s->prev = tail;
		    tail = s;
		    tail->next = NULL;
			tail->i=tail->prev->i;
		    tail->j=tail->prev->j;
		    S[head->i*60+head->j]='O';
		}
		
		for(s = head;s->next!=NULL;s = s->next){
			if(s->next->i== head->i && s->next->j == head->j){S[head->i*60+head->j]='X';show(S,n);lost(); goto START;} 
			S[(s->next->i)*60+s->next->j]='o';
		}
		
		if(eat){do{rand(x,y);}while(S[y*60+x]!=' ');} 
		
		if(n==5*N){break;} 
		
		
		show(S,n);
		if(eat){Beep((DWORD)1000,(DWORD)(speed));eat = false;}else{Beep((DWORD)0,(DWORD)(speed));} 
		SaveGame(N,SCORE);
	}
	
	
	
	N++;
	SaveGame(N,SCORE);
	win();
goto START;	
	CloseHandle(hThread); 
	return 0;   
}
