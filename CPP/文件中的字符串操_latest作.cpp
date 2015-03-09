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
		file_name = "data.txt";//�̶��ļ���
	}
	~file(){}

	void read_content();//��ȡ����
	void writeinto_file();//�״�ʹ��ʱд���ļ�����
	bool delete_content();//���ļ���ɾ��ָ�����ַ���
	bool replace_content();//�滻�ļ��е�Ŀ�괮Ϊ�µ��ַ���
	bool copy_content();//�����ַ���
	bool insert_content();//���ļ��в�������
	void show_content();//��ʾ���ݣ�ÿ����ʾ������ʾ���µ�����
	bool save_change(string new_string);//���溯�����������е��ַ���д���ļ�
	bool save_change(string new_string, string new_file);//���غ�������������Ǹ��Ƶ��µ��ļ�����ʹ����
};

void file::writeinto_file()
{
	cout << "����Դ�ַ���: " << endl;
	string content;
	cin >> content;
	save_change(content);
}

void file::read_content()//��ȡ�ļ�
{
	ifstream ifs(file_name.c_str(), ios::in);
	ifs >> file_content;
	ifs.close();
}

bool file::copy_content()//�����ļ�
{
    cout << "��ǰ���ļ������ǣ�\n" << endl;
    cout << file_content << endl;
    cout << "�����븴�Ƶ����:";
    int start, len;
    cin >> start;
    cout << "�������Ƴ���:";
    cin >> len;

    if (start < 0 || start > file_content.length() || len < 0 || start + len > file_content.length())
    {
        cout << "�������벻���ַ�����Χ��" << endl;
        return true;
    }

    string new_file;
    cout << "����������Ҫ���Ƶ����ļ����ļ�����";
    cin >> new_file;
    if (new_file == "data.txt")//�������Դ�ļ�������
    {
        cout << "���������Լ���������" << endl;
        return true;
    }
    else
        save_change(file_content.substr(start, len), new_file);
}

bool file::delete_content()//ɾ������
{
	cout << "������Ҫɾ�������ݣ�";
	string substring;
	cin >> substring;

    if (file_content.find(substring) == string::npos)
    {
        cout << "������ɾ��\"" << substring << "\"! �����������ļ���!" << endl;
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
    cout << "�������㣺";
    int start;
    cin >> start;
    cout << "����������ݣ�";
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
	cout << "������Ҫ�滻���Ӵ���";
	string substring, dest_string;
	cin >> substring;
	cout << "���������滻�������ݣ�";
	cin >> dest_string;

    string new_string = file_content;

    if (substring == dest_string)
        return true;

    if (file_content.find(substring) == string::npos)
    {
        cout << "�޷��ҵ���Ҫ�滻���Ӵ�" << endl;
        return true;
    }

    //ɾ��ԭ�ַ���
    vector<int> v;
	int pos;
	while ((pos = new_string.find(substring)) != string::npos)
	{
		v.push_back(pos);//��¼ÿ��Ŀ���Ӵ������
		new_string.erase(pos, substring.length());
	}

    //�������ַ���
	int times = 0;
	for (int i = 0; i != v.size(); i++)
	{
	    //��ÿ�����������ַ�����û���һ�Σ���Ϊ���ƶ��±꣬��Ϊÿ����һ�κ������ַ����Ľṹ���ˣ��±���ÿ���������ַ����ĳ��ȳ��Բ������
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
	cout << new_string << "�Ѿ����Ƶ�" << new_file << endl;
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

    cout << "����Դ�ַ���" << endl;
	o_file.writeinto_file();
	o_file.read_content();

	while (1) {
    	cout << "\n�ļ�������:";
    	o_file.show_content();
    	cout << "-------------------------------" << endl;

    	cout << "\t1:�滻�ַ���" << endl;
    	cout << "\t2:ɾ���Ӵ�" << endl;
    	cout << "\t3:����������" << endl;
    	cout << "\t4:����Դ�ַ���" << endl;

    	cout << "\t������ѡ��";
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
