#include <stdio.h>
#include <malloc.h>

struct stu
{
    int num;
    struct stu *next;
};//

void main()
{
    int nin;
    int nout;
    struct stu *create();
    struct stu *insert(struct stu *head,int nin);
    struct stu *del(struct stu *head,int num);
    void print(struct stu *head);
    
    struct stu *head,*p,*p1;
    printf("please input info to node, '0' to quit:\n");
    head=create();//
    p=head;//
    print(p);//
  	printf("please input what you wanna insert:\n");
    scanf("%d",&nin);
    p=insert(head,nin);
    print(p);
    printf("please input the del num:\n");
    scanf("%d",&nout);
    p=del(head,nout);
    print(p);
}

struct stu * create()
{
    int n;
    struct stu *head,*p1,*p2;
    p1 = NULL;
    p2 = NULL;
    head=NULL;
    while(1)
    {
        p1=(struct stu*)malloc(sizeof(struct stu));
        p1->next = NULL;
        scanf("%d",&p1->num);
        if(p1->num == 0)
        	break;
        if(head == NULL)
			head=p1;
        else
        {
            p2->next=p1;
        }
        p2=p1;  
    }
    return head;
};
//难点在插入操作的实现上
struct stu *insert(struct stu *head,int nin)
{
    struct stu *p1,*p;
    struct stu *new_node;
    new_node = (struct stu *)malloc(sizeof(struct stu));
    new_node->num = nin;
    new_node->next = NULL;
    p=head;
    if(head == NULL)
    {
    	head = new_node;
    }
    else
    {
    	while(p != NULL)
    	{
    		p1 = p;
    		p = p->next;
    	}
    	p1->next = new_node;
    }
    return head;
};
//删除操作难度次之

struct stu *del(struct stu *head,int num)
{
    struct stu *p, *pre;
	p = head;
	while(p && (p->num != num))
	{
		pre = p;
		p = p->next;
		
	}
	if(p)
	{
		if(p == head)
			head = p->next;
		else
			pre->next = p->next;
	}
	return head;	
};

void print(struct stu *head)
{
    struct stu *p;
    p=head;
    printf("node is:\n");
    while(p)
    {
        printf("%d\n",p->num);
        p=p->next;
    }
}
