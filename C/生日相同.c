#include <stdio.h>
#include <string.h>

struct Student
{
  char name[100];
  int month;
  int day;
};
typedef struct Student student;
student stu[1001];
int main()
{
  int n,i,j,k,temp,find;
  scanf("%d", &n);
  for (i = 0; i < n; i++)
    {
      scanf("%s ", &stu[i].name);
      scanf("%d ", &stu[i].month);
      scanf("%d", &stu[i].day);
    }
  for(i=1;i<=12;i++)
    for(j=1;j<=31;j++)  //��ÿһ����в��� 
    {
	  find=0;  //����Ϊ������˳�ʼ��Ϊ0 
      for(k=0;k<n;k++)//�������˲��� 
      {
      	if((stu[k].month==i)&&(stu[k].day==j))//������������� 
      	{
		  find++; /
		  /��������+1 
      	  if(find==1)//�����ʱ�ҵ�������Ϊ1 
      	    temp=k;//��������˵ĽǱ� 
      	  else if(find==2)//�����ʱ�ҵ�������Ϊ2
      	    printf("%d %d %s %s",i,j,stu[temp].name,stu[k].name);//����£��պ�ǰ�����˵�ѧ�� 
      	  else
      	    printf(" %s",stu[k].name);//�������ѧ�� 
      	}
      }
      if(find>=2)//���������ͬ���˴�������  
        printf("\n");//���һ������ 
    }
  return 0;
}
