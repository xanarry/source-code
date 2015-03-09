#include <stdio.h>
 
int main()
{
	int p;
	enum s{spring,summer,autumn,winter};
	enum s sea;
	scanf("%d",&p);
	sea = (enum s)p;
	switch(sea-1)
	{
		case spring : printf("spring"); break;
		case summer : printf("summer"); break;
		case autumn : printf("autumn"); break;
		case winter : printf("winter"); break;
	}
	return 0;
}
