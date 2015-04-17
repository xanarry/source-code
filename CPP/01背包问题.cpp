/*
一切都要从一则故事说起。

话说有一哥们去森林里玩发现了一堆宝石，他数了数，一共有n个。 但他身上能装宝石的就只有一个背包，
背包的容量为C。这哥们把n个宝石排成一排并编上号： 0,1,2,…,n-1。第i个宝石对应的体积和价值分别
为V[i]和W[i] 。排好后这哥们开始思考： 背包总共也就只能装下体积为C的东西，那我要装下哪些宝石
才能让我获得最大的利益呢？

OK，如果是你，你会怎么做？你斩钉截铁的说：动态规划啊！恭喜你，答对了。 那么让我们来看看，
动态规划中最最最重要的两个概念： 状态和状态转移方程在这个问题中分别是什么。

我们要怎样去定义状态呢？这个状态总不能是凭空想象或是从天上掉下来的吧。 为了方便说明，
让我们先实例化上面的问题。一般遇到n，你就果断地给n赋予一个很小的数， 比如n=3。然后设背
包容量C=10，三个宝石的体积为5，4，3，对应的价值为20，10，12。 对于这个例子，我想智商大
于0的人都知道正解应该是把体积为5和3的宝石装到背包里， 此时对应的价值是20+12=32。接下来，
我们把第三个宝石拿走， 同时背包容量减去第三个宝石的体积（因为它是装入背包的宝石之一）， 
于是问题的各参数变为：n=2，C=7，体积｛5，4｝，价值｛20，10｝。好了， 现在这个问题的解是什
么？我想智商等于0的也解得出了：把体积为5的宝石放入背包 （然后剩下体积2，装不下第二个宝石，
只能眼睁睁看着它溜走），此时价值为20。 这样一来，我们发现，n=3时，放入背包的是0号和2号宝
石；当n=2时， 我们放入的是0号宝石。这并不是一个偶然，没错， 这就是传说中的“全局最优解包含
局部最优解”（n=2是n=3情况的一个局部子问题）。 绕了那么大的圈子，你可能要问，这都哪跟哪啊？
说好的状态呢？说好的状态转移方程呢？ 别急，它们已经呼之欲出了。

我们再把上面的例子理一下。当n=2时，我们要求的是前2个宝石， 装到体积为7的背包里能达到的最
大价值；当n=3时，我们要求的是前3个宝石， 装到体积为10的背包里能达到的最大价值。有没有发现
它们其实是一个句式！OK， 让我们形式化地表示一下它们， 定义d(i,j)为前i个宝石装到剩余体积为j
的背包里能达到的最大价值。 那么上面两句话即为：d(2, 7)和d(3, 10)。这样看着真是爽多了， 而
这两个看着很爽的符号就是我们要找的状态了。 即状态d(i,j)表示前i个宝石装到剩余体积为j的背包
里能达到的最大价值。 上面那么多的文字，用一句话概括就是：根据子问题定义状态！你找到子问题， 
状态也就浮出水面了。而我们最终要求解的最大价值即为d(n, C)：前n个宝石 （0,1,2…,n-1）装入剩
余容量为C的背包中的最大价值。状态好不容易找到了， 状态转移方程呢？顾名思义，状态转移方程就
是描述状态是怎么转移的方程（好废话！）。 那么回到例子，d(2, 7)和d(3, 10)是怎么转移的？来，
我们来说说2号宝石 （记住宝石编号是从0开始的）。从d(2, 7)到d(3, 10)就隔了这个2号宝石。 它有
两种情况，装或者不装入背包。如果装入，在面对前2个宝石时， 背包就只剩下体积7来装它们，而相应
的要加上2号宝石的价值12， d(3, 10)=d(2, 10-3)+12=d(2, 7)+12；如果不装入，体积仍为10，价值自
然不变了， d(3, 10)=d(2, 10)。记住，d(3, 10)表示的是前3个宝石装入到剩余体积为10 的背包里能
达到的最大价值，既然是最大价值，就有d(3, 10)=max{ d(2, 10), d(2, 7)+12 }。好了，这条方程描
述了状态d(i, j)的一些关系， 没错，它就是状态转移方程了。
把它形式化一下：d(i, j)=max{ d(i-1, j), d(i-1,j-V[i-1]) + W[i-1] }。
注意讨论前i个宝石装入背包的时候， 其实是在考查第i-1个宝石装不装入背包（因为宝石是从0开始编号的）。
至此， 状态和状态转移方程都已经有了。接下来，直接上代码。
*/

#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
#define MAXN 1000
#define MAXC 100000

int V[MAXN], W[MAXN];
int d[MAXN][MAXC];

int main(){
    int n, C;
    while(cin >> n >> C)
    {
        for(int i=0; i<n; ++i)   
            scanf("%d %d", &V[i], &W[i]);
        //v{3 2 1}, c{20, 10, 12}
        for(int i=0; i<=n; ++i)//分别是装0个石头到n个石头
        {
            for(int j=0; j<=C; ++j)//构造从0到最大容量的数字
            {
                if (i == 0)//如果是第0个，直接赋值0
                    d[i][j] = 0;
                else
                    d[i][j] = d[i - 1][j];
                
                if(i>0 && j>=V[i-1])//直到找到一个能装下石头的容量
                    d[i][j] = max(d[i][j], d[i-1][j-V[i-1]]+W[i-1]);//选择最大价值
            }
        }
        for (int i = 0; i <= n; i++)
        {
            for (int j = 0; j <= C; j++)
                cout << d[i][j] << " ";
            cout << endl;
        }

        printf("%d\n", d[n][C]);//最终求解的最大价值
    }
    return 0;
}