#include <stdio.h>
#include <stdlib.h>

#define N 9
#define OVERFLOW 0
#define OK 1


typedef struct LNode
{
	int keyword;
	struct LNode *next;
}LNode, *LinkList;
int key[N] = {4,7,5,9,3,2,6,1,8};
void joseph(LinkList p, int m, int x);
void joseph(LinkList p, int m, int x)
{
	LinkList q;
	int i;
	if(x == 0)//链表为空 
		return;
	q = p;//接收链表头指针 
	m = m%x;
	if(m == 0)
		m = x;
	for (i = 0; i < m; i++)
	{
		p = q;
		q = p->next;
	}
	p->next = q->next;//删除节点 
	i = q->keyword;//获取节点数据 
	printf("%d ", q->keyword);
	free(q);
	joseph(p,i,x-1);
}

int main(int argc, char const *argv[])
{
	int i;
	int m;
	LinkList Lhead,p,q;
	Lhead = (LinkList)malloc(sizeof(LNode));
	if(!Lhead)
		return OVERFLOW;
	Lhead->keyword = key[0];
	Lhead->next = NULL;
	p = Lhead;
	for(i = 1; i < 9; i++)
	{
		if(!(q = (LinkList)malloc(sizeof(LNode))))
			return OVERFLOW;
		q->keyword = key[i];//键数组中的元素传递到循环链表1 
		p->next = q;
		p = q;
	}
	p->next = Lhead;//构建循环链表 
	printf("Please input the first record:\n");
	scanf("%d",&m);
	printf("the output alignment is:\n");
	joseph(p,m,N);//p表示链表头，m表示第一次跳跃的数量，N表示链表节点数量 
	getch();
	return OK;
}
