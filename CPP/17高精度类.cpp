#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <algorithm>
using namespace std;
const int MAXN = 1000;//数字位数，最多可存储1000位的整数。 

struct bign
{
    int len, s[MAXN];//len表示当前数字的长度（多少位），s用来存储这个数，倒着存。 
    bign ()//构造函数，倒着存的理由是方便进位。 
    {
        memset(s, 0, sizeof(s));//数组s置0 
        len = 1;//0是1位数 
    }
    bign (int num) { *this = num; }//bign的构造函数，用赋值符号处理 
    bign (const char *num) { *this = num; }//用字符串构造bign，也交给赋值符号处理 
    bign operator = (const int num)//=的重载函数，用数字给bign赋值 
    {
        char s[MAXN];
        sprintf(s, "%d", num);//将num这个数字输出到字符串s 
        *this = s;//用s给bign赋值，交给27行的，用字符串赋值处理 
        return *this;//返回赋值后的结果 
    }
   
    bign operator = (const char *num)//=的重载函数，用字符串给bign赋值 
    {
    	memset(s, 0, sizeof(s));//将s置0 
        len = 1;
        for(int i = 0; num[i] == '0'; num++) ;//去除s的前导0 
        len = strlen(num);//求字符串长度 
        for(int i = 0; i < len; i++) s[i] = num[len-i-1] - '0';//倒序存储 
        if(len==0)  len=1;//因为去除了前导，如果去除完前导，len是0，len置1 
        return *this;
    }
    void clean()//清理bign前面的0，比如减法计算完结果是00123，执行完这个函数，就变成123 
    {
    	if(len==0)  len=1;
        while(len > 1 && !s[len-1]) len--;
    }
    string str() const//将bign转换成字符串的函数 
    {
		string res(len,'0');
		for(int i=0;i<len;i++)
			res[i]+=s[len-i-1];
		return res;
    }
   friend bign operator + (const bign &a,const bign &b)
    {
        bign c;
        c.len = 0;
        for(int i = 0, g = 0; g || i < max(a.len, b.len); i++)
        {
            int x = g;
            if(i < a.len) x += a.s[i];
            if(i < b.len) x += b.s[i];
            c.s[c.len++] = x % 10;
            g = x / 10;
        }
        return c;
    }
    bign operator += (const bign &b)
    {
        *this = *this + b;
        return *this;
    }
    friend bign operator * (const bign &a,const bign &b)
    {
        bign c;
        c.len = a.len + b.len;
        for(int i = 0; i < a.len; i++)
          for(int j = 0; j < b.len; j++)
            c.s[i+j] += a.s[i] * b.s[j];
        for(int i = 0; i < c.len; i++)
        {
            c.s[i+1] += c.s[i]/10;
            c.s[i] %= 10;
        }
        c.clean();
        return c;
    }
    friend bign operator - (const bign &a,const bign &b)
    {
        bign c;
        c.len = 0;
        for(int i = 0, g = 0; i < a.len; i++)
        {
            int x = a.s[i] - g;
            if(i < b.len) x -= b.s[i];
            if(x >= 0) g = 0;
            else
            {
                g = 1;
                x += 10;
            }
            c.s[c.len++] = x;
        }
        c.clean();
        return c;
    }
    friend bign operator / (const bign &a,const bign &b)//前置 乘法，减法，>=
    {
        bign c, f = 0, t = b;
        for(int i = a.len-1; i >= 0; i--)
        {
		    f = f*10;
            f.s[0] = a.s[i];
            while(f >= b)
            {
                f = f-b;
                c.s[i]++;
            }
        }
        c.len = a.len;
        c.clean();
        return c;
    }
    bign operator % (const bign &b)//前置，减法，乘法，除法
    {
        bign r = *this / b;
        r = *this - r*b;
        return r;
    }
    friend bool operator < (const bign &a,const bign &b)
    {
        if(a.len != b.len) return a.len < b.len;
        for(int i = a.len-1; i >= 0; i--)
        {
            if(a.s[i] != b.s[i]) return a.s[i] < b.s[i];
        }
        return false;
    }
    friend bool operator > (const bign &a,const bign &b)
    {
        return b<a;
    }
        friend bool operator <= (const bign &a,const bign &b)
    {
        return !(b<a);
    }
    friend bool operator >= (const bign &a,const bign &b)
    {
        return !(a<b);
    }
    friend bool operator == (const bign &a,const bign &b)
    {
        return !(a < b) && !(b < a);
    }
    friend bool operator != (const bign &a,const bign &b)
    {
        return (a < b)||(b < a);
    }
};
istream& operator >> (istream &in, bign &x)
{
    string s;
    in >> s;
    x = s.c_str();
    return in;
}
ostream& operator << (ostream &out, const bign &x)
{
    out << x.str();
    return out;
}
int main()
{
    bign a,b;
    a=760;
    b = 12;
    cout << a << endl;
    cout << b << endl;
    cin >> a >> b;
	return 0;
}
