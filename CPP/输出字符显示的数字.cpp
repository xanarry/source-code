#include <iostream>
#include <string>
using namespace std;

string nums[10] = { //每个字符串表示一个矩阵数字其中每个数字矩阵是7x7的
    "00000000     00     00     00     00     00000000", //0
    "   0      0      0      0      0      0      0   ", //1
    "0000000      0      000000000      0      0000000", //2
    "0000000      0      00000000      0      00000000", //3
    "0     00     00     00000000      0      0      0", //4
    "00000000      0      0000000      0      00000000", //5
    "00000000      0      00000000     00     00000000", //6
    "0000000      0      0      0      0      0      0", //7
    "00000000     00     000000000     00     00000000", //8
    "00000000     00     00000000      0      00000000"  //9
};

int main()
{
    string input;
    const int COW = 7, ROW = 7;
    cin >> input;
    for (int i = 0; i < ROW; i++)
    {
        for (int j = 0; j < input.length(); j++)
            cout << nums[input[j] - 48].substr(COW * i, COW) + "  ";
        cout << endl;
    }
    return 0;
}