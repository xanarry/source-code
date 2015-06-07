#include <iostream>
#include <string>
using namespace std;

string conv(int decimal, int base);

int main(void)
{
    cout << conv(50, 2) << endl;
    cout << conv(50, 16) << endl;
    return 0;
}
//函数参数为十进制数和目标进制数
string conv(int decimal, int base)
{
    if(decimal == 0) 
        return "0";

    char NUMS[] = "0123456789ABCDEF";
    string result = "";
    do{
        result.push_back(NUMS[decimal % base]);
        decimal /= base; 
    }while(decimal != 0); 

    return string(result.rbegin(), result.rend());
}
