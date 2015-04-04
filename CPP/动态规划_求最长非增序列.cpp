/*第一问求最长非增序列，第二问求最长上升序列。其中用到一个Dilworth定理。 
即最小划分链=最长子链，不上升子序列的最小划分数＝最长上升子序列的长度。 
*/
#include <iostream>
#include <vector>

using namespace std;

const int MAX = 128;

int N, f1[MAX], f2[MAX], ans1, ans2;
vector<int> pVec;

int main()
{
	cin >> N;
	int nTmp;
	for(int i = 0; i < N; i++)
	{
		cin >> nTmp;
		pVec.push_back(nTmp);
	}
	for(int i = 0; i < pVec.size(); i++)
	{ f1[i] = f2[i] = 1; }
	for(int i = 1; i < pVec.size(); i++)
	{
		int max1 = 0, max2 = 0;
		for(int j = 0; j < i; j++)
		{
			if(pVec[j] >= pVec[i] && f1[j] > max1)
			{ max1 = f1[j]; }
			if(pVec[j] < pVec[i] && f2[j] > max2)
			{ max2 = f2[j]; }
		}
		f1[i] = max1 + 1;
		f2[i] = max2 + 1;
	}
	ans1 = 0; ans2 = 0;
	for(int i = 0; i < pVec.size(); i++)
	{
		if(f1[i] > ans1) { ans1 = f1[i]; }
		if(f2[i] > ans2) { ans2 = f2[i]; }
	}
	cout << ans1 << " " << ans2 << endl;
	return 0;
}