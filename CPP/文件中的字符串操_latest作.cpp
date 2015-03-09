#include <iostream>
#include <string>
#include <fstream>
#include <stdlib.h>
#include <vector>

using namespace std;

class file
{
private:
	string file_name;
	string file_content;

public:
	file()
	{
		file_name = "data.txt";//固定文件名
	}
	~file(){}

	void read_content();//读取内容
	void writeinto_file();//首次使用时写入文件内容
	bool delete_content();//从文件中删除指定的字符串
	bool replace_content();//替换文件中的目标串为新的字符串
	bool copy_content();//复制字符串
	bool insert_content();//想文件中插入内容
	void show_content();//显示内容，每次显示都会显示最新的内容
	bool save_change(string new_string);//保存函数，将参数中的字符串写入文件
	bool save_change(string new_string, string new_file);//重载函数，如果复制是复制到新的文件，就使用它
};

void file::writeinto_file()
{
	cout << "输入源字符串: " << endl;
	string content;
	cin >> content;
	save_change(content);
}

void file::read_content()//读取文件
{
	ifstream ifs(file_name.c_str(), ios::in);
	ifs >> file_content;
	ifs.close();
}

bool file::copy_content()//复制文件
{
    cout << "当前的文件内容是：\n" << endl;
    cout << file_content << endl;
    cout << "请输入复制的起点:";
    int start, len;
    cin >> start;
    cout << "请数复制长度:";
    cin >> len;

    if (start < 0 || start > file_content.length() || len < 0 || start + len > file_content.length())
    {
        cout << "您的输入不在字符串范围内" << endl;
        return true;
    }

    string new_file;
    cout << "输入您即将要复制到新文件的文件名：";
    cin >> new_file;
    if (new_file == "data.txt")//如果输入源文件的名字
    {
        cout << "您不能想自己复制内容" << endl;
        return true;
    }
    else
        save_change(file_content.substr(start, len), new_file);
}

bool file::delete_content()//删除内容
{
	cout << "输入您要删除的内容：";
	string substring;
	cin >> substring;

    if (file_content.find(substring) == string::npos)
    {
        cout << "您不用删除\"" << substring << "\"! 它根本不在文件中!" << endl;
        return true;
    }

    string new_string = file_content;
    int pos;
    while ((pos = new_string.find(substring)) != string::npos)
	{
		new_string.erase(pos, substring.length());
	}

    save_change(new_string);
	return true;
}

bool file::insert_content()
{
    cout << "输入插入点：";
    int start;
    cin >> start;
    cout << "输入插入内容：";
    string dest;
    cin >> dest;

    if (start < 0)
        start = 0;
    if (start > file_content.length())
        start = file_content.length();

    string new_string = file_content;
    new_string.insert(start, dest);

    save_change(new_string);
	return true;
}

bool file::replace_content()
{
	cout << "输入您要替换的子串：";
	string substring, dest_string;
	cin >> substring;
	cout << "输入用于替换的新内容：";
	cin >> dest_string;

    string new_string = file_content;

    if (substring == dest_string)
        return true;

    if (file_content.find(substring) == string::npos)
    {
        cout << "无法找到您要替换的子串" << endl;
        return true;
    }

    //删除原字符串
    vector<int> v;
	int pos;
	while ((pos = new_string.find(substring)) != string::npos)
	{
		v.push_back(pos);//记录每个目标子串的起点
		new_string.erase(pos, substring.length());
	}

    //插入新字符串
	int times = 0;
	for (int i = 0; i != v.size(); i++)
	{
	    //向每个起点添加新字符串，没添加一次，人为的移动下标，因为每插入一次后，整个字符串的结构变了，下标在每次增加新字符串的长度乘以插入次数
		new_string.insert(v[i] + times * dest_string.length(), dest_string);
		times++;
	}

	save_change(new_string);
	return true;
}

bool file::save_change(string new_string)
{
    ofstream ofs(file_name.c_str(), ios::out);
	ofs << new_string;
	ofs.close();
	return true;
}

bool file::save_change(string new_string, string new_file)
{
    ofstream ofs(new_file.c_str(), ios::out);
	ofs << new_string;
	ofs.close();
	cout << new_string << "已经复制到" << new_file << endl;
	return true;
}

void file::show_content()
{
	read_content();
	cout << file_content << endl;
}

int main(int argc, char const *argv[])
{
	file o_file;

    cout << "创建源字符串" << endl;
	o_file.writeinto_file();
	o_file.read_content();

	while (1) {
    	cout << "\n文件内容是:";
    	o_file.show_content();
    	cout << "-------------------------------" << endl;

    	cout << "\t1:替换字符串" << endl;
    	cout << "\t2:删除子串" << endl;
    	cout << "\t3:插入新内容" << endl;
    	cout << "\t4:复制源字符串" << endl;

    	cout << "\t请输入选择：";
    	int choose;
    	cin >> choose;
    	switch (choose)
    	{
    	case 1:
        	o_file.replace_content();
        	o_file.read_content();
        	o_file.show_content();
        	break;

    	case 2:
        	o_file.delete_content();
        	o_file.read_content();
        	o_file.show_content();
        	break;

    	case 3:
        	o_file.insert_content();
        	o_file.read_content();
        	o_file.show_content();
        break;

    	case 4:
        	o_file.copy_content();
        	o_file.read_content();
        	break;
    	}
	}
	return 0;
}
