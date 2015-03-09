/*
Description
S 城现有两座监狱，一共关押着N 名罪犯，编号分别为1~N。他们之间的关系自然也极不和谐。很多罪犯之间甚至积怨已久，如果客观条件具备则随时可能爆发冲突。我们用“怨气值”（一个正整数值）来表示某两名罪犯之间的仇恨程度，怨气值越大，则这两名罪犯之间的积怨越多。如果两名怨气值为c 的罪犯被关押在同一监狱，他们俩之间会发生摩擦，并造成影响力为c 的冲突事件。
每年年末，警察局会将本年内监狱中的所有冲突事件按影响力从大到小排成一个列表，然后上报到S 城Z 市长那里。公务繁忙的Z 市长只会去看列表中的第一个事件的影响力，如果影响很坏，他就会考虑撤换警察局长。
在详细考察了N 名罪犯间的矛盾关系后，警察局长觉得压力巨大。他准备将罪犯们在两座监狱内重新分配，以求产生的冲突事件影响力都较小，从而保住自己的乌纱帽。假设只要处于同一监狱内的某两个罪犯间有仇恨，那么他们一定会在每年的某个时候发生摩擦。那么，应如何分配罪犯，才能使Z 市长看到的那个冲突事件的影响力最小？这个最小值是多少？
Input
输入的每行中两个数之间用一个空格隔开。
第一行为两个正整数N 和M，分别表示罪犯的数目以及存在仇恨的罪犯对数。
接下来的M 行每行为三个正整数aj，bj，cj，表示aj 号和bj 号罪犯之间存在仇恨，其怨气值为cj。数据保证1<=aj<bj<N,0<cj<=1,000,000,000 且每对罪犯组合只出现一次。
Output
输出共1 行，为Z 市长看到的那个冲突事件的影响力。如果本年内监狱中未发生任何冲突事件，请输出0。
Sample Input
4 6
1 4 2534
2 3 3512
1 2 28351
1 3 6618
2 4 1805
3 4 12884
Sample Output
3512
*/
/*

#include <iostream>
#include <algorithm>
#include <stdio.h>

using namespace std;

struct Crim
{
	int x;
	int y;
	int hate;
};

Crim cr[1000000];

int main(int argc, char const *argv[])
{
	int n, m, i, j;
	scanf("%d%d", &n, &m);
	for (i = 1; i <= n*2; i++) 
	{
		cr[i] = i;
	}

	for (i = 0; i < m; i++)
	{
		scanf("%d%d%d", &cr[i].x, &cr[i].y, &cr[i].hate);
	}
	return 0;
}
ios::sync_with_stdio(false);

*/






#include <iostream>
#include <algorithm>
#include <stdio.h>
#define MAXN 40010
#define MAXM 100010
using namespace std;
struct criminal
{
	int x,y;
	long long int hate;
};
struct criminal cri[MAXM];
int f[MAXN];
int findset(int a)
{
	if(a == f[a])
		return a;
	f[a] = findset(f[a]);
	return f[a];
}
bool cmp(struct criminal a,struct criminal b)
{
	return a.hate>b.hate;
}
int main()
{
	int m,n;
	int p,q;
	int i;
	scanf("%d%d", &n, &m);
	for(i=0;i<=n*2;i++)
		f[i]=i;
	for(i=0;i<m;i++)
		scanf("%d%d%d", cri[i].x, cri[i].y, cri[i].hate);
	sort(cri,cri+m,cmp);
	for(i=0;i<m;i++)
	{
		p=findset(cri[i].x);
		q=findset(cri[i].y);
		if(p!=q)
		{
			f[p]=findset(cri[i].y+n);
			f[q]=findset(cri[i].x+n);
		}
		else
			break;
	}
	if(i==m)
		printf("0\n");
	else
		printf("%d\n",cri[i].hate);
	return 0;
}
