#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <algorithm>
using namespace std;
const int MAXN = 1000;//����λ�������ɴ洢1000λ�������� 

struct bign
{
    int len, s[MAXN];//len��ʾ��ǰ���ֵĳ��ȣ�����λ����s�����洢����������Ŵ档 
    bign ()//���캯�������Ŵ�������Ƿ����λ�� 
    {
        memset(s, 0, sizeof(s));//����s��0 
        len = 1;//0��1λ�� 
    }
    bign (int num) { *this = num; }//bign�Ĺ��캯�����ø�ֵ���Ŵ��� 
    bign (const char *num) { *this = num; }//���ַ�������bign��Ҳ������ֵ���Ŵ��� 
    bign operator = (const int num)//=�����غ����������ָ�bign��ֵ 
    {
        char s[MAXN];
        sprintf(s, "%d", num);//��num�������������ַ���s 
        *this = s;//��s��bign��ֵ������27�еģ����ַ�����ֵ���� 
        return *this;//���ظ�ֵ��Ľ�� 
    }
   
    bign operator = (const char *num)//=�����غ��������ַ�����bign��ֵ 
    {
    	memset(s, 0, sizeof(s));//��s��0 
        len = 1;
        for(int i = 0; num[i] == '0'; num++) ;//ȥ��s��ǰ��0 
        len = strlen(num);//���ַ������� 
        for(int i = 0; i < len; i++) s[i] = num[len-i-1] - '0';//����洢 
        if(len==0)  len=1;//��Ϊȥ����ǰ�������ȥ����ǰ����len��0��len��1 
        return *this;
    }
    void clean()//����bignǰ���0�������������������00123��ִ��������������ͱ��123 
    {
    	if(len==0)  len=1;
        while(len > 1 && !s[len-1]) len--;
    }
    string str() const//��bignת�����ַ����ĺ��� 
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
    friend bign operator / (const bign &a,const bign &b)//ǰ�� �˷���������>=
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
    bign operator % (const bign &b)//ǰ�ã��������˷�������
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
