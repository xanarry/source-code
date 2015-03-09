#include <fstream>
#include <iostream>
#include <cstdlib>
#include <cctype>

using namespace std; 

bool singleline(string line, int &);
bool isempty(string line);

int lines = 0;
int pound_comment = 0;
int block_comment = 0;
int empty = 0;
int start = 0;

int main(int argc, char const *argv[])
{
	
    ifstream in("1.py", ios::in);  
    string line;  
    
    int linecount = 0;
    if(!in) 
    {  
        cout <<"no such file" << endl;  
        exit(1);
    }  
   
    while (getline(in, line))
    {  
        if (singleline(line, start))
            pound_comment++;

        if (start == 1)
            block_comment++;
        int i = 0; 
        for (i = 0; i < line.length(); i++)
        {
            if (line[i] == '\'' && line[i + 1] == '\'' && line[i + 2] == '\'')
            {
                if (start == 0)
                    start = 1;
                else
                    start = 0;
                block_comment++;
            }
        }
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
	return 0;
}

bool singleline(string line, int &start)
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

bool isempty(string line)
{
    if (line.length() == 0)
        return true;

    int i = 0;
    for (i = 0; i < line.length(); )
    {
        if (isspace(line[i]))
            i++;
        else
            break;
    }
    if (i == line.length())
        return true;
    return false;
}


