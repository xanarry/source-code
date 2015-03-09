#include <iostream>
#include <cstring>

using namespace std;

int main(int argc, char const *argv[])
{
	char str[500];
	cout << "you string is:" << endl;
	gets(str);
	char *temp;
	temp = strtok(str, " ,.:;");//首先获取第一个单词，类似于遍历文件夹
	while(temp != NULL)
	{
		cout << temp << endl;
		temp = strtok(NULL, " ,.:;\'\")(");//再处理后面的字符
	}
	return 0;
}
