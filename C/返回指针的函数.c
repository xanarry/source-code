#include<stdio.h>
int main()
{
	float score[5][4]={{67,87,66,89},{90,87,89,76},{97,78,96,76},{67,78,98,80},{89,98,79,80}};
	float *search(float (*pointer)[4],int n);//����search������һ������ָ��ĺ��������յ������βηֱ�Ϊָ��4��Ԫ�ص�ָ������� 
	int i,m;
	float *p;//����һ��ָ���������search�������ص��е�ַ 
	printf("input student's no:");
	scanf("%d",&m);
	p = search(score,m);
	for(i=0;i<4;i++)
	{
		printf("%.2f ",*(p+i));//p��search�������ص��е�ַ����ѭ�������һ�е�ֵ 
	}
	return 0;
}

float *search(float (*pointer)[4], int n)
{
	return *(pointer+n-1); //����ָ��
}
