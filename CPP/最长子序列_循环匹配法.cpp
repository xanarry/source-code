#include <iostream>
#include <sstream>
#include <string>
using namespace std;

struct INDEX
{
	int a;
	int b;
};

INDEX *str_search(string a, string b, INDEX *start);
string *get_lcs_list(string a, string b, int &list_len);
string *lcs(string a, string b, int &count);

int main(int argc, char const *argv[])
{
	string a, b;
	cout << "input string a:";
	cin >> a;
	cout << "input string b:";
	cin >> b;

	int count;
	string *lcss = get_lcs_list(a, b, count);
	for (int i = 0; i < count; i++)
		cout << "lcs:" << i + 1 << ": " << lcss[i] << " len:" << lcss[i].length() << endl;
	return 0;
}

string *get_lcs_list(string a, string b, int &list_len)
{
	int a_count, b_count;
	
	string *list_a = lcs(a, b, a_count);
	string *list_b = lcs(b, a, b_count);
	int total = b_count + a_count;
	string temp[total];
	string *lcs = new string[total];

	int t = 0;
	for (int i = 0; i < a_count; i++)
		temp[t++] = list_a[i];
	for (int i = 0; i < b_count; i++)
		temp[t++] = list_b[i];

	int max = 0;
	for (int i = 0; i < t; i++)
		if (temp[i].length() > max)
			max = temp[i].length();

	int tt = 0;

	for (int i = 0; i < t; i++)
	{
		if (temp[i].length() == max)
		{
			if (tt == 0)
				lcs[tt++] = temp[i];
			else
			{
				bool in = false;
				for (int j = 0; j < tt; j++)
				{
					if (lcs[j] == temp[i])
					{
						in = true;
						break;
					}
				}
				if (!in)
					lcs[tt++] = temp[i];
			}
		}
	}	

	list_len = tt;
	return lcs;
}

string *lcs(string a, string b, int &count)
{
	string *lcss = new string[a.length()];
	INDEX *start = new INDEX();
	count = 0;
	for (int i = 0; i < a.length() && i < b.length(); i++)
	{
		start->a = i;
		start->b = 0;
		stringstream ss;
		while (start->a < a.length() && start->b < b.length())
		{
			start = str_search(a, b, start);
			if (start->a < a.length() && start->b < b.length())
			{
				ss << a[start->a];
				start->a++;
				start->b++;
			}
		}
		if (count == 0)
			lcss[count++] = ss.str();
		else
		{
			if (ss.str().length() > lcss[count - 1].length())
				lcss[count - 1] = ss.str();
			else if(ss.str().length() == lcss[count - 1].length())
				lcss[count++] = ss.str();
		}
	//	cout << ss.str() << " len:" << ss.str().length() << endl;
	}

	return lcss;
}

INDEX *str_search(string a, string b, INDEX *start)
{
	INDEX *temp = new INDEX();
	int i, j;
	for (i = start->a; i < a.length(); i++)
	{
		for (j = start->b; j < b.length(); j++)
		{
			if (a[i] == b[j])
			{
				temp->a = i;
				temp->b = j;
				return temp;
			}
		}
	}

	temp->a = a.length();
	temp->b = b.length();
	return temp;
}

/*
BDCABA
ABCBDAB
lcs: BCBA, BDAB

BCBA
BDAB
lcs: BB, BA

ACCGGTCGAGTGCGCGGAAGCCGGCCGAA
GTCGTTCGGAATGCCGTTGCTCTGTAAA
lcs:1: GTCGTCGGAAGCCGGCCGAA

ABCDEF
ABCDEF
lcs:ABCDEF

LJDFGHSLKDFJGSDFGFDREWTSDFGDSFSDKJHHIUNDSFKJHIUHKSHDFKHQWEUIHFNASKDHFKASDFG
SJDFIUWERIUGNDKHFIQRHJQRKJHFSAKJHIGHKSDHFKXZVBKJKDFSGKDSFGKAHSDIFHIWEAFSAFF
lcs:1: SFKJHIHKSHDFKHWEFAFF len:20

Thismethodiscalledwheninformationaboutanimagewhichwaspreviouslyrequestedusinganasynchronousinterfacebecomesavailable.AsynchronousinterfacesaremethodcallssuchasgetWidth(ImageObserver)anddrawImage(img,x,y,ImageObserver)whichtakeanImageObserverobjectasanargument.Thosemethodsregisterthecallerasinterestedeitherininformationabouttheoverallimageitself(inthecaseofgetWidth(ImageObserver))oraboutanoutputversionofanimage(inthecaseofthedrawImage(img,x,y,[w,h,]ImageObserver)call).
Thismethodshouldreturntrueiffurtherupdatesareneededorfalseiftherequiredinformationhasbeenacquired.Theimagewhichwasbeingtrackedispassedinusingtheimgargument.Variousconstantsarecombinedtoformtheinfoflagsargumentwhichindicateswhatinformationabouttheimageisnowavailable.Theinterpretationofthex,y,width,andheightargumentsdependsonthecontentsoftheinfoflagsargument.
lcs:1: lerasinterestedeitherininformationabouttheoveralmet.
lcs:2: hichindicateswhatinformationabouttheimageisnowavall.

*/