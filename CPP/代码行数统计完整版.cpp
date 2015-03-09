/**********************************************************
 *author: xiongyang
 *  date: 2014/6/30
 *  note: ����ͳ�Ƴ�����ע�͵Ŀ�ʼ�ͽ�β����һ�еĴ���
 *        ���磺1 / * cout << "hello world" << endl; * /
 *
 *        ��������c c++ javaע�ͷ�ʽ��һ�£�������ʹ��//
 *        ����ʹ�� / *��ʼ��* /��β
 *
 *        php������������ϼ��ϵ��п�����"#"ע�͡�
 *
 *        python�ĵ���ע����'#',����ע�͵������յ㶼ʹ
 *        �á�'''����
 *
 *        shell�ű�����޵��С�#��ע�ͣ�δ�ṩ����ע��֧��
 *        
 *        ʹ��ʱ�����û���ѡ��������ͣ�Ȼ��Ҫ�����������
 *        ����·�������ɿ�ʼͳ��
 *********************************************************/

#include <windows.h>//���ڿ���
#include <iostream>//�����������
#include <fstream>//��ȡ�ļ�
#include <cstring>//c�ַ���
#include <conio.h>//ѡ��˵�����
#include <cstdlib>//������
#include <sstream>//��λת����ת��Ϊ�ַ���
#include <string>//�ַ�������
#include <cctype>//�ַ������ж�
#include <io.h>//�����ļ�

using namespace std;

int choose();//��ȡѡ����Ŀ
void menu(int slelect);//����˵���ʾ
void traversal(string dir, int type);//�����ļ��л�ȡ�ļ�
string size_convert(long long size);//�ļ���С��λת��

void cpp(string dir, char * file_name);//����c/c++�ļ�������·�����ļ���
void python(string dir, char * file_name);//ͬ��
void shell(string dir, char * file_name);//ͬ��
void php(string dir, char * file_name);//ͬ��
bool shell_singleline(string line);//�ڴ���php�ļ�ʱҪ�ã�����������ǰ

void display(string path, int type_no);//��ʾ�ۺ���Ϣ

string type_list[] = {"*.c", "*.cpp", "*.py", "*.sh", "*.php", "*.java"};//��������

long file_count = 0;//�����ļ�����
long long file_size = 0;//�ļ��ܴ�С


long all_lines = 0;//������
long all_empty = 0;//�ܿ�����
long all_single_line_comment = 0;//�ܵ���ע��
long all_block_comment = 0;//�ܴ���Ƭ��ע��


//////������///////////
int main(int argc, char const *argv[])
{
	//���
	int temp = choose();//ͨ���˵���ȡ��Ҫ����Ĵ�������

	cout << "�����ļ���·��(E:\\souce code\\Java)" << endl;
	cout << "input path:";
	string path;//��ȡ�ļ�·��
	getline(cin, path);//��ȡ��������С���ֹ�����·�����пո����ֹ����

//	path = "E:\\souce code\\Java";
	switch(temp)//ѡ���Ӧ��ģ��ͳ�ƴ�������
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

	display(path, temp);//�����Ϣ

	system("PAUSE > NUL");//��ֹ�������ֱ���˳�
	return 0;
}


int choose()//�˵������²���
{
	int operate;//����״̬
	int choose = 1;//Ĭ��ѡ����ǲ˵�1
	menu(choose);//����˵�
	while (1)
	{
		operate = getch();//��ȡ���̲���
		switch(operate)
		{
			case 72://�ϼ�
				if (choose > 1)
				{
					choose--;
					system("cls");//����
					menu(choose);//ÿ�β�������´�����ʾ
				}
				break;
			case 80://�¼�
				if (choose < 6)
				{
					choose++;
					system("cls");
					menu(choose);//ÿ�β�������´�����ʾ
				}
				break;
			case 13://�س�ȷ����
				system("cls");
				return(choose);//����ѡ��Ĵ�������
				break;
		}
	}
}

void display(string path, int temp)
{
	cout << "\n\t\t�ۺ���Ϣ" << endl;
	cout << "-------------------------------------------------" << endl;
	cout << "\t Ŀ  ¼  ��" << path << endl;
	cout << "\t�������� ��" << type_list[temp - 1] << endl;
	cout << endl;
    cout << "\t ������  ��" << all_lines << endl;
    cout << "\t ������  ��" << all_empty << endl;
    cout << "\t����ע�� ��" << all_single_line_comment << endl;
    cout << "\t����ע�� ��" << all_block_comment << endl;
    cout << "\t��Ч���� ��" << all_lines - all_single_line_comment - all_block_comment - all_empty << endl;
    cout << endl;
    cout << "\t�ļ����� ��" << file_count << endl;
	cout << "\t�ļ���С ��" << size_convert(file_size) << "(" << file_size << "�ֽ�)" << endl;
    cout << "-------------------------------------------------\n" << endl;
}

void menu(int slelect)//������ڲ˵�������ѡ��Ĳ��������ͬ����Ϣ��
{
	cout << "\t\t��ѡ���������:" << endl;
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

//���ݹ��������ļ�·�����ļ�����
void traversal(string t_dir, int type)//����ָ���ļ����е�ָ�����͵Ĵ����ļ�
{
	//��Ҫ��*c,*.cpp��ͬ���Ĵ���
	//type is c or cpp

	string obj_dir = t_dir + "\\";//����Ŀ¼��Ϊ��������

	string dir = t_dir + "\\" + type_list[type - 1];//��ȡ����·��
	cout << "dir:" << dir.c_str() << endl;//

	struct _finddata_t find_file;

	long handle = _findfirst(dir.c_str(), &find_file);//��ȡ��һ���ļ���Ϣ
	if (handle == -1)
	{
		system("cls");
		cout << "���󣡸�Ŀ¼û�д����ļ�����Ŀ¼������" << endl;
		exit(-1);
	}
	//�����ļ�����ѡ������
	switch(type)
	{
		case 1:
		case 2:		
		case 5:
		case 6:
			//����Ŀ¼���ļ���
			cpp(obj_dir, find_file.name);//c/c++/php/java���붼ʹ��һ����������
			break;
		case 3:
			python(obj_dir, find_file.name);
			break;
		case 4:
			shell(obj_dir, find_file.name);
			break;
	}

	file_size += find_file.size;//��ȡ�ļ���С�����ۼ�
	file_count ++;//�����ļ�����

	while (!_findnext(handle, &find_file))//���������ʣ�µ��ļ�
	{
		/*�˴�����Ϊ�ݹ���Ŀ¼
		if (find_file.attrib == _A_SUBDIR && strcmp(find_file.name, "..") != 0)
		{
			string nest_dir = t_dir + "\\" + find_file.name;
			cout << "dir: " << nest_dir << endl;
			traversal(nest_dir.c_str(), type);
		}*/
		
		if (strcmp(find_file.name, "..") != 0)
		{
			cout << find_file.name << endl;
			//�����ļ�����ѡ������
			switch(type)
			{
				case 1:
				case 2:
				case 5:
				case 6:
					cpp(obj_dir, find_file.name);//c/c++/php/java���붼ʹ��һ����������
					break;
				case 3:
					python(obj_dir, find_file.name);
					break;
				case 4:
					shell(obj_dir, find_file.name);
					break;
			}

			file_count++;//ͬ��
			file_size += find_file.size;//ͬ��
		}
	}
	_findclose(handle);//�ر��ļ����
}

//��λ����
string size_convert(long long size)//���ֽڱ�ʾ���ļ���СתΪ�����ļ���С��λ��ʾ
{
	string size_units[] = {"Byte", "KB", "MB", "GB", "TB"};
	int index = 0;//��ʾ��λ�±�
	float temp = 0;
	int postfix = 0;//��ʾС��
	for (index = 0; size >= 1024; index++)
	{
		temp = size % 1024;//����������
		size /= 1024;//����ȡ��,ÿȡһ�Σ���λ�±����
	}
	postfix = int((temp/1024) * 1000);//��׺����С����ֵ
	stringstream out;//�ַ���������
	out << size << "." << postfix << size_units[index];//����������Ϣ
	return out.str();//����ֵ
}	  


bool c_singleline(string line, int &, int &);
bool isempty(string line);//�Ƿ�Ϊ���еĺ�������

void cpp(string dir, char *file_name)  
{  
	string path = dir + (string)file_name;//�����ļ��ľ���·��

	string get_type = path.substr(path.length() - 3);//��ȡ�ļ����ͣ��ж��ǲ���php�ļ�

    ifstream in(path.c_str(), ios::in);//����ת�������ļ�
    string line;  
    
    int linecount = 0;
    if(!in) 
    {  
        cout <<"û�и��ļ�������·��δ֪����" << endl;  
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
    		if (c_singleline(line, start, comment))//������c/c++
            	double_slash_comment++;
    	}
        else
        {
        	//������php,��Ϊphp�ĵ���ע�Ϳ�����shell�ű���ʽ�ӵġ�#��
        	if (c_singleline(line, start, comment) || shell_singleline(line))
            	double_slash_comment++;
        }

        if (start == 1)
            comment++;//����

        if (isempty(line))
            empty++;//����

        lines++;
    }  

   	cout << "-------------------------------------------------" << endl;
    cout << "\t���� : " << lines << endl;
    cout << "\t���� : " << empty << endl;
    cout << "\t//   : " << double_slash_comment << endl;
    cout << "\t/*~*/: " << comment << endl;
    cout << "\t��Ч : " << lines - double_slash_comment - comment - empty<< endl;
    cout << "-------------------------------------------------\n" << endl;

    all_lines += lines;
    all_empty += empty;
    all_block_comment += comment;
    all_single_line_comment += double_slash_comment;
}  

//�����ֱ��ǣ����ַ���������ע�Ϳ�ʼ״̬�� ����ע����������������
bool c_singleline(string line, int &start, int &comment)
{
    int i = 0; 
    for (i = 0; i < line.length(); )//��ȡ��һ���ǿհ��ַ��±�
    {
        if (isspace(line[i]))
            i++;
        else
            break;
    }

    //�������ע��
    bool oneline = false;//���'/*'��'*/'�Ƿ���ͬһ��
    if (line[i] == '/' && line[i + 1] == '*')//���еĿ�ʼ
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
    if (line[k] == '/' && line[k - 1] == '*')//���еĽ���
    {
        start = 0;
        if (oneline == true)
            comment--;
    }

    ////����'//'
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
    	//����
        if (python_singleline(line, pstart))
            pound_comment++;

        //python�������ע��
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

        //����
        if (isempty(line))
            empty++;
        lines++;
    }  

    block_comment = block_comment ? block_comment - 1 : 0;
    cout << "-------------------------------------------------" << endl;
	cout << "\t���� : " << lines << endl;
	cout << "\t���� : " << empty << endl;
	cout << "\t #   : " << pound_comment << endl;
	cout << "\t ''' : " << block_comment << endl;
	cout << "\t��Ч : " << lines - block_comment - pound_comment - empty<< endl;
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

//shell�ű���ʱ�����ṩ����ע��
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

    bool flag = false;// ��/*�����㡱

    while (getline(in, line))
    {
    	if (shell_singleline(line))
    		pound_comment++;
    }  

    all_lines += lines;
    all_empty += empty;
    all_single_line_comment += pound_comment;

    cout << "-------------------------------------------------" << endl;
    cout << "\t���� : " << lines << endl;
    cout << "\t���� : " << empty << endl;
    cout << "\t #   : " << pound_comment << endl;
    cout << "\t��Ч : " << lines - pound_comment - empty<< endl;
    cout << "-------------------------------------------------\n" << endl;
}  

//shell���д���
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


//�ж����������ô��������ж����е�ͨ�ú���
bool isempty(string line)
{
    if (line.length() == 0)//����Ϊ0
        return true;

    int i = 0;
    for (i = 0; i < line.length(); )//�����ַ���
    {
        if (isspace(line[i]))
            i++;
        else
            break;
    }
    if (i == line.length())//���û�б���������Ч�ַ�
        return true;
    return false;
}
