#include <stdio.h>
#include <math.h>
#include <stdbool.h>
 
int a[9] = {0};
int n = 8, count = 0;
 
//λ�ó�ͻ�㷨
bool Chongtu(int a[], int n)//a[]λ�����飬n�ʺ����
{
    int i = 0, j = 0;
 
    for (i = 2; i <= n; ++i)//i��λ��
    {
        for (j = 1; j <= i-1; ++j)//j��λ��
        {
            if ((a[i] == a[j]) || (abs(a[i]-a[j]) == i-j))//1����һ�У�2���ڶԽ�����
                return false;   //��ͻ
        }
    }
    return true;//����ͻ
}
 
//�˻ʺ����⣺�����㷨���ݹ�棩
void Queens8(int k) //����k���ݹ�ڷŵ�k���ʺ�
{
    int i = 0;
 
    if (k > n)      //k>n��n = 8. ��k>8��ʾ���һ���ʺ�ڷ����
    {
        printf("��%02d�������",++count);
        for (i = 1; i <= n; ++i)
            printf("%d ",a[i]);//��ӡ���
        printf("\n");
    }
    else   //8���ʺ�δȫ���ڷ����       
    {
        for (i = 1; i <= n; ++i)//�ڷŵ�k���ʺ�ʱ��ת��һ�У�
        {       //���δ��ж��˿�ʼ������һֱ���е׶ˣ�ֱ���ҵ�����λ��,���δ�ҵ����Զ������ϲ�ݹ�(����)
            a[k] = i;              
            if (Chongtu(a,k))//����ͻ
                Queens8(k+1);//�ݹ�ڷ���һ���ʺ�
        }
    }
    return;
}
 
//������
int main()
{
    Queens8(1);//����1����ʾ�ڷŵ�1���ʺ�
 
    return 0;
} 