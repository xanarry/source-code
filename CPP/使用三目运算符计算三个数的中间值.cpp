#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
	int a, b, c;
	cin >> a >> b >> c;
	int mid = ( a>c ? ( c>b ? c : (a>b ? b : a) ) : (b>a ? (b>c ? c : b) : a) );
	cout << mid << endl;
	return 0;
}