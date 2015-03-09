#include<stdio.h>
int main()
{
	int q,w,e,r,t,y,u,i,o;
	int n=1;
	for(q = 0; q < 10; q++)
	{
		for(w = 0; w < 10; w++)
		{
			for(e = 0; e < 10; e++)
			{
				for(r = 0; r < 10; r++)
				{
					for(t = 0; t < 10; t++)
					{
						for(y = 0; y < 10; y++)
						{
							for(u = 0; u < 10; u++)
							{
								for(i = 0; i < 10; i++)
								{
									for(o = 0; o < 10; o++)
									{
										if((q+w+e==r+t+y) && (r+t+y==u+i+o) && (u+i+o==q+r+u) && (q+r+u==w+t+i) && (w+t+i==e+y+o) && (e+y+o==q+t+o) && (q+t+o==u+t+e))
          								{ 									//遍历所有的可能并筛选满足条件的输出 
											printf("第 %d 魔方阵是\n",n);
          									printf("%d %d %d\n",q,w,e);
          									printf("%d %d %d\n",r,t,y);
          									printf("%d %d %d\n",u,i,o);
          									printf("\n");
          									n++;
										} 
									} 
								} 	
							} 
						} 	
					} 	
				} 
			}        
		} 	
	} 	
  	return 0;
}
