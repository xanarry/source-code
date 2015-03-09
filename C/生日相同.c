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
    for(j=1;j<=31;j++)  //对每一天进行查找 
    {
	  find=0;  //生日为这天的人初始化为0 
      for(k=0;k<n;k++)//对所有人查找 
      {
      	if((stu[k].month==i)&&(stu[k].day==j))//如果生日是这天 
      	{
		  find++; /
		  /到的人数+1 
      	  if(find==1)//如果此时找到的人数为1 
      	    temp=k;//记下这个人的角标 
      	  else if(find==2)//如果此时找到的人数为2
      	    printf("%d %d %s %s",i,j,stu[temp].name,stu[k].name);//输出月，日和前两个人的学号 
      	  else
      	    printf(" %s",stu[k].name);//否则，输出学号 
      	}
      }
      if(find>=2)//如果生日相同的人大于两个  
        printf("\n");//输出一个换行 
    }
  return 0;
}
