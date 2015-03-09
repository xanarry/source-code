#include <iostream>
#include <string>
#include <cstring>
#include <cstdlib>
#include <sstream>
#include <io.h>

using namespace std;

long file_count = 0;
long long file_size= 0;

void traversl_dir(string t_dir)
{
	string dir = t_dir + "\\*.*";
	struct _finddata_t find_file;
	long handle = _findfirst(dir.c_str(), &find_file);
	if (handle == -1)
	{
		cout << "visit error" << endl;
		exit(1);
	}

	cout << find_file.name << endl;

	while (!_findnext(handle, &find_file))
	{
		if (find_file.attrib == _A_SUBDIR && strcmp(find_file.name, "..") != 0)
		{
			string nest_dir = t_dir + "\\" + find_file.name;
			cout << "dir: " << nest_dir << endl;
			traversl_dir(nest_dir.c_str());
		}
		else if (strcmp(find_file.name, "..") != 0)
		{
			cout << "\tfile: " << find_file.name << endl;
			file_count++;
			file_size += find_file.size;
		}
		
	}
	 _findclose(handle);
	 cout << dir << endl;
}

string size_convert(long long size)
{
	string size_units[] = {"Byte", "KB", "MB", "GB", "TB"};
	int index = 0;
	float temp = 0;
	int postfix = 0;
	for (index = 0; size >= 1024; index++)
	{
		temp = size % 1024;
		size /= 1024;
	}
	postfix = int((temp/1024) * 1000);
	stringstream out;
	out << size << "." << postfix << size_units[index];
	return out.str();
}	

int main(int argc, char const *argv[])
{
	string dir;
	cout << "input a ivalid path:";
//	cin >> dir;
	dir = "c:";
	traversl_dir(dir);
	cout << "file_count = " << file_count << endl;
	cout << "file_size  = " << file_size  << "Byte" << endl;
	cout << "it is arond " << size_convert(file_size) << endl;
	return 0;
}
