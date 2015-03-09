/**********************************************************
 *author: xiongyang
 *  date: 2014/6/30
 *  note: 不能统计出多行注释的开始和结尾都在一行的代码
 *        列如：1 / * cout << "hello world" << endl; * /
 *
 *        本程序视c c++ java注释方式都一致，即但行使用//
 *        多行使用 / *开始，* /结尾
 *
 *        php则在上面基础上加上单行可是用"#"注释。
 *
 *        python的单行注释用'#',多行注释的起点和终点都使
 *        用‘'''’。
 *
 *        shell脚本这仅限单行‘#’注释，未提供多行注释支持
 *        
 *        使用时会让用户先选择代码类型，然后要求输入代码文
 *        件的路径，即可开始统计
 *********************************************************/

#include <windows.h>//窗口控制
#include <iostream>//基本输入输出
#include <fstream>//读取文件
#include <cstring>//c字符串
#include <conio.h>//选择菜单所需
#include <cstdlib>//错误处理
#include <sstream>//单位转换后转换为字符串
#include <string>//字符串对象
#include <cctype>//字符类型判断
#include <io.h>//遍历文件

using namespace std;

int choose();//获取选择项目
void menu(int slelect);//桌面菜单显示
void traversal(string dir, int type);//遍历文件夹获取文件
string size_convert(long long size);//文件大小单位转换

void cpp(string dir, char * file_name);//处理c/c++文件，传递路径及文件名
void python(string dir, char * file_name);//同上
void shell(string dir, char * file_name);//同上
void php(string dir, char * file_name);//同上
bool shell_singleline(string line);//在处理php文件时要用，所以声明在前

void display(string path, int type_no);//显示综合信息

string type_list[] = {"*.c", "*.cpp", "*.py", "*.sh", "*.php", "*.java"};//代码类型

long file_count = 0;//代码文件数量
long long file_size = 0;//文件总大小


long all_lines = 0;//总行数
long all_empty = 0;//总空行数
long all_single_line_comment = 0;//总单行注释
long all_block_comment = 0;//总代码片段注释


//////主函数///////////
int main(int argc, char const *argv[])
{
	//入口
	int temp = choose();//通过菜单获取需要处理的代码类型

	cout << "输入文件夹路径(E:\\souce code\\Java)" << endl;
	cout << "input path:";
	string path;//获取文件路径
	getline(cin, path);//获取输入的整行。防止输入的路径中有空格而终止运行

//	path = "E:\\souce code\\Java";
	switch(temp)//选择对应的模块统计代码行数
	{
		case 1:
			cout << "code type is:" << type_list[0] << endl;//*.c
			traversal(path, 1);
			break;
		case 2:
			cout << "code type is:" << type_list[1] << endl;//*.cpp
			traversal(path, 2);
			break;
		case 3:
			cout << "code type is:" << type_list[2] << endl;//*.py
			traversal(path, 3);
			break;
		case 4:
			cout << "code type is:" << type_list[3] << endl;//*.sh
			traversal(path, 4);
			break;
		case 5:
			cout << "code type is:" << type_list[4] << endl;//*.php
			traversal(path, 5);
			break;
		case 6:
			cout << "code type is:" << type_list[5] << endl;//*.java
			traversal(path, 6);
			break;
		default:
			break;
	}

	display(path, temp);//输出信息

	system("PAUSE > NUL");//防止运行完后直接退出
	return 0;
}


int choose()//菜单的上下操作
{
	int operate;//操作状态
	int choose = 1;//默认选择的是菜单1
	menu(choose);//输出菜单
	while (1)
	{
		operate = getch();//获取键盘操作
		switch(operate)
		{
			case 72://上键
				if (choose > 1)
				{
					choose--;
					system("cls");//清屏
					menu(choose);//每次操作后更新窗口显示
				}
				break;
			case 80://下键
				if (choose < 6)
				{
					choose++;
					system("cls");
					menu(choose);//每次操作后更新窗口显示
				}
				break;
			case 13://回车确定键
				system("cls");
				return(choose);//返回选择的代码类型
				break;
		}
	}
}

void display(string path, int temp)
{
	cout << "\n\t\t综合信息" << endl;
	cout << "-------------------------------------------------" << endl;
	cout << "\t 目  录  ：" << path << endl;
	cout << "\t代码类型 ：" << type_list[temp - 1] << endl;
	cout << endl;
    cout << "\t 总行数  ：" << all_lines << endl;
    cout << "\t 空行数  ：" << all_empty << endl;
    cout << "\t单行注释 ：" << all_single_line_comment << endl;
    cout << "\t多行注释 ：" << all_block_comment << endl;
    cout << "\t有效行数 ：" << all_lines - all_single_line_comment - all_block_comment - all_empty << endl;
    cout << endl;
    cout << "\t文件总数 ：" << file_count << endl;
	cout << "\t文件大小 ：" << size_convert(file_size) << "(" << file_size << "字节)" << endl;
    cout << "-------------------------------------------------\n" << endl;
}

void menu(int slelect)//输出窗口菜单（接收选择的参数输出不同的信息）
{
	cout << "\t\t请选择代码类型:" << endl;
	cout << "\t------------------------------------" << endl;
	if (slelect == 1)
		cout << "\t\t---> C      code <---" << endl;
	else
		cout << "\t\t     C      code" << endl;

	if (slelect == 2)
		cout << "\t\t---> C++    code <---" << endl;
	else
		cout << "\t\t     C++    code" << endl;

	if (slelect == 3)
		cout << "\t\t---> Python code <---" << endl;
	else
		cout << "\t\t     Python code" << endl;

	if (slelect == 4)
		cout << "\t\t---> shell  code <---" << endl;
	else
		cout << "\t\t     shell  code" << endl;

	if (slelect == 5)
		cout << "\t\t---> PHP    code <---" << endl;
	else
		cout << "\t\t     PHP    code" << endl;

	if (slelect == 6)
		cout << "\t\t---> Java   code <---" << endl;
	else
		cout << "\t\t     Java   code" << endl;
	cout << "\t------------------------------------" << endl;
}

//传递过来的是文件路径和文件类型
void traversal(string t_dir, int type)//遍历指定文件夹中的指定类型的代码文件
{
	//需要将*c,*.cpp做同样的处理
	//type is c or cpp

	string obj_dir = t_dir + "\\";//处理目录作为参数传递

	string dir = t_dir + "\\" + type_list[type - 1];//获取绝对路径
	cout << "dir:" << dir.c_str() << endl;//

	struct _finddata_t find_file;

	long handle = _findfirst(dir.c_str(), &find_file);//获取第一个文件信息
	if (handle == -1)
	{
		system("cls");
		cout << "错误！该目录没有此类文件或者目录不存在" << endl;
		exit(-1);
	}
	//根据文件类型选择处理函数
	switch(type)
	{
		case 1:
		case 2:		
		case 5:
		case 6:
			//传递目录和文件名
			cpp(obj_dir, find_file.name);//c/c++/php/java代码都使用一个函数处理
			break;
		case 3:
			python(obj_dir, find_file.name);
			break;
		case 4:
			shell(obj_dir, find_file.name);
			break;
	}

	file_size += find_file.size;//获取文件大小，并累计
	file_count ++;//计算文件数量

	while (!_findnext(handle, &find_file))//遍历后面的剩下的文件
	{
		/*此处保留为递归子目录
		if (find_file.attrib == _A_SUBDIR && strcmp(find_file.name, "..") != 0)
		{
			string nest_dir = t_dir + "\\" + find_file.name;
			cout << "dir: " << nest_dir << endl;
			traversal(nest_dir.c_str(), type);
		}*/
		
		if (strcmp(find_file.name, "..") != 0)
		{
			cout << find_file.name << endl;
			//根据文件类型选择处理函数
			switch(type)
			{
				case 1:
				case 2:
				case 5:
				case 6:
					cpp(obj_dir, find_file.name);//c/c++/php/java代码都使用一个函数处理
					break;
				case 3:
					python(obj_dir, find_file.name);
					break;
				case 4:
					shell(obj_dir, find_file.name);
					break;
			}

			file_count++;//同上
			file_size += find_file.size;//同上
		}
	}
	_findclose(handle);//关闭文件句柄
}

//单位换算
string size_convert(long long size)//将字节表示的文件大小转为常规文件大小单位表示
{
	string size_units[] = {"Byte", "KB", "MB", "GB", "TB"};
	int index = 0;//表示单位下标
	float temp = 0;
	int postfix = 0;//表示小数
	for (index = 0; size >= 1024; index++)
	{
		temp = size % 1024;//求最后的余数
		size /= 1024;//不断取整,每取一次，单位下标后移
	}
	postfix = int((temp/1024) * 1000);//后缀计算小数的值
	stringstream out;//字符串流对象
	out << size << "." << postfix << size_units[index];//构建输入信息
	return out.str();//返回值
}	  


bool c_singleline(string line, int &, int &);
bool isempty(string line);//是否为空行的函数声明

void cpp(string dir, char *file_name)  
{  
	string path = dir + (string)file_name;//处理文件的绝对路径

	string get_type = path.substr(path.length() - 3);//获取文件类型，判断是不是php文件

    ifstream in(path.c_str(), ios::in);//类型转换并打开文件
    string line;  
    
    int linecount = 0;
    if(!in) 
    {  
        cout <<"没有该文件，或者路径未知错误！" << endl;  
        exit(1);
    }  

    int lines = 0;
	int double_slash_comment = 0;
	int empty = 0;
	int comment = 0;
	int start = 0;
   
    while (getline(in, line))
    {  
    	if (get_type != "php")
    	{
    		if (c_singleline(line, start, comment))//处理单行c/c++
            	double_slash_comment++;
    	}
        else
        {
        	//处理单行php,因为php的单行注释可能是shell脚本形式加的‘#’
        	if (c_singleline(line, start, comment) || shell_singleline(line))
            	double_slash_comment++;
        }

        if (start == 1)
            comment++;//多行

        if (isempty(line))
            empty++;//空行

        lines++;
    }  

   	cout << "-------------------------------------------------" << endl;
    cout << "\t总行 : " << lines << endl;
    cout << "\t空行 : " << empty << endl;
    cout << "\t//   : " << double_slash_comment << endl;
    cout << "\t/*~*/: " << comment << endl;
    cout << "\t有效 : " << lines - double_slash_comment - comment - empty<< endl;
    cout << "-------------------------------------------------\n" << endl;

    all_lines += lines;
    all_empty += empty;
    all_block_comment += comment;
    all_single_line_comment += double_slash_comment;
}  

//参数分别是：行字符串，多行注释开始状态， 多行注释行数变量的引用
bool c_singleline(string line, int &start, int &comment)
{
    int i = 0; 
    for (i = 0; i < line.length(); )//获取第一个非空白字符下标
    {
        if (isspace(line[i]))
            i++;
        else
            break;
    }

    //处理多行注释
    bool oneline = false;//标记'/*'与'*/'是否在同一行
    if (line[i] == '/' && line[i + 1] == '*')//多行的开始
    {
        start = 1;
        oneline = true;
        comment++;
    }

    int k = line.length();
    for (k = line.length() - 1; k >= 0; )
    {
        if (isspace(line[k]))
            k--;
        else 
            break;
    }
    if (line[k] == '/' && line[k - 1] == '*')//多行的结束
    {
        start = 0;
        if (oneline == true)
            comment--;
    }

    ////处理'//'
    if (line[i] == '/' && line[i + 1] == '/')
        return true;
    else
        return false;
}

bool python_singleline(string line, int &);

void python(string dir, char *file_name)
{
	string path = dir + (string)file_name;
	cout << path << endl;
    ifstream in(path.c_str(), ios::in); 
 
    string line;  
    
    int linecount = 0;
    if(!in) 
    {  
        cout <<"no such file" << endl;  
        exit(1);
    }  
   	
   	int lines = 0;
	int pound_comment = 0;
	int block_comment = 0;
	int empty = 0;
	int pstart = 0;

    while (getline(in, line))
    {  
    	//单行
        if (python_singleline(line, pstart))
            pound_comment++;

        //python代码多行注释
        if (pstart == 1)
            block_comment++;
        int i = 0; 
        for (i = 0; i < line.length(); i++)
        {
            if (line[i] == '\'' && line[i + 1] == '\'' && line[i + 2] == '\'')
            {
                if (pstart == 0)
                    pstart = 1;
                else
                    pstart = 0;
                block_comment++;
            }
        }

        //空行
        if (isempty(line))
            empty++;
        lines++;
    }  

    block_comment = block_comment ? block_comment - 1 : 0;
    cout << "-------------------------------------------------" << endl;
	cout << "\t总行 : " << lines << endl;
	cout << "\t空行 : " << empty << endl;
	cout << "\t #   : " << pound_comment << endl;
	cout << "\t ''' : " << block_comment << endl;
	cout << "\t有效 : " << lines - block_comment - pound_comment - empty<< endl;
	cout << "-------------------------------------------------\n" << endl;

	all_lines += lines;
    all_empty += empty;
    all_single_line_comment += pound_comment;
    all_block_comment += block_comment;
}

bool python_singleline(string line, int &pstart)
{
    int i = 0; 
    for (i = 0; i < line.length(); )
    {
        if (isspace(line[i]))
            i++;
        else
            break;
    }
    if (line[i] == '#')
        return true;
    else
        return false;
}

//shell脚本暂时不提提供多行注释
void shell(string dir, char *file_name)  
{  
	string path = dir + (string)file_name;
	cout << path << endl;
    ifstream in(path.c_str(), ios::in);  
    string line;  
    
    int linecount = 0;
    if(!in) 
    {  
        cout <<"no such file" << endl;  
        exit(1);
    }  

    int lines = 0;
    int pound_comment = 0;
    int empty = 0;

    bool flag = false;// “/*标记起点”

    while (getline(in, line))
    {
    	if (shell_singleline(line))
    		pound_comment++;
    }  

    all_lines += lines;
    all_empty += empty;
    all_single_line_comment += pound_comment;

    cout << "-------------------------------------------------" << endl;
    cout << "\t总行 : " << lines << endl;
    cout << "\t空行 : " << empty << endl;
    cout << "\t #   : " << pound_comment << endl;
    cout << "\t有效 : " << lines - pound_comment - empty<< endl;
    cout << "-------------------------------------------------\n" << endl;
}  

//shell单行处理
bool shell_singleline(string line)
{
    int i = 0; 
    for (i = 0; i < line.length(); )
    {
        if (isspace(line[i]))
            i++;
        else
            break;
    }
    if (line[i] == '#')
        return true;
    else
        return false;
}


//判读空行是所用代码类型判读空行的通用函数
bool isempty(string line)
{
    if (line.length() == 0)//长度为0
        return true;

    int i = 0;
    for (i = 0; i < line.length(); )//遍历字符串
    {
        if (isspace(line[i]))
            i++;
        else
            break;
    }
    if (i == line.length())//如果没有遍历都到有效字符
        return true;
    return false;
}
