#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int main(int argc, char const *argv[])
{
	pair<string, int> a = {"asdf", 123};
	cout << a.first << endl;
	cout << a.second << endl;

	vector<int> s;
	s.push_back(0);
	s.push_back(1);
	s.push_back(2);
	s.push_back(3);
	tuple<string, int, vector<int> > t("array", 10, s);
	cout << get<0>(t) << endl;
	cout << get<1>(t) << endl;
	cout << get<2>(t)[3] << endl;

	std::map<string, int> m;
	m["one"] = 1;
	m["two"] = 2;
	m["three"] = 3;
	m["four"] = 4;
	cout << m.find("one")->first << endl;
	cout << m.find("two")->second << endl;
	for (std::map<string, int>::iterator iter = m.begin(); iter != m.end(); ++iter)
	{
		cout << iter->first << "->" << iter->second << endl;
	}
	return 0;
}

/*
trans_map[key] = value.substr(1);
as trans_map.insert({key, value.substr(1)})?

tuple<string, string> duo("1", "2");

A pair always has two members, which makes it possible for the library to give these
members names (i.e., first and second). No such naming convention is possible for
tuple because there is no limit on the number of members a tuple type can have.
As a result, the members are unnamed. Instead, we access the members of a tuple
through a library function template named get. To use get we must specify an explicit
template argument (¡ì 16.2.2, p. 682), which is the position of the member we want
to access. We pass a tuple object to get, which returns a reference to the specified
member:
Click here to view code image
auto book = get<0>(item); // returns the first member of item
auto cnt = get<1>(item); // returns the second member of item

*/

/*
19
Alice
Chris
Jan
Marsha
Ruben
Bobby
Cindy
Jody
Mike
Shirlet
Buffy
Danny
Keith
Mr._French
Sissy
Carol
Greg
Lori
Peter
*/
