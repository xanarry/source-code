#include <iostream>
using namespace std;

int *f()  
{  
    int a[3] = {9,2,3};  
    cout << a << "-->" << *a << endl;
    cout << a + 1 << "-->" << *(a + 1) << endl;
    cout << a + 2 << "-->" << *(a + 2) << endl;
    cout << endl;
    return a;  //ϵͳ���ں������غ��ͷŵ���ʱ������ڴ�
}  

int main(int argc, char const *argv[])
{
	int *p = f();
	cout << p << "-->" << *p << endl;
	cout << p + 1 << "-->" << *(p + 1) << endl;
	cout << p + 2 << "-->" << *(p + 2) << endl;
	return 0;
}