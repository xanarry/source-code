#include <iostream>

using namespace std;

struct node  //链表结点定义
{
       char stuName[10];
       int month;
       int day;
       node *next;
};

void insert(node *L, char name[],int m,int d)
{
    //插入一个结点
     node *p = L->next;
     node *pre = L;
     node *s = new node;

     strcpy(s->stuName,name);
     s->month = m;
     s->day = d;

     while(p)
     {
        if( (m > p->month) || (m == p->month && d >= p->day) )
        {
            pre = p; 
            p = p->next;
        }
        else break;
     }
     s->next = p;
     pre->next = s;   
}

void display(node *L)
{//遍历链表输出生日相同的学生
    node *p = L->next;
    
    while(p!=NULL)
    {
        node *q = p->next;
        if(q &&q->month == p->month && q->day == p->day)
        {    
            cout<<p->month<<" "<<p->day<<" "<<p->stuName<<" "<<q->stuName<<" ";
            q = q->next;
            while(q && q->month == p->month && q->day == p->day) 
            {   
                cout<<q->stuName<<" "; q = q->next;
            }
            cout<<endl;
            p = q;
        }
        else p = p->next;
    }                  
}

int main()
{
    int n;   
    cin>>n;
    char name[10];
    int m,d; 
    node *L=new node;  //建立带头结点空单链表 
    L->next = NULL;
    
    while(n--)
    {
        cin>>name>>m>>d;
        insert(L,name,m,d);
    }  
    
    display(L);
    
    return 0;
}
