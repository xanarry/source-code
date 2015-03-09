#include <iostream>
#include <cstring>
#include <stack>
using namespace std;


template <class T>
void StackClear(stack<T> &s)			//���ջ
{
    while(!s.empty())
        s.pop();
}


/*
�ж϶�ȡ�����ַ��Ƿ��������
*/
int IsOperator(char c)
{
    switch(c)
    {
    case '+':
    case '-':
    case '*':
    case '/':
    case '(':
    case ')':
    case '=':
        return 1;
        break;
    default:
        return 0;
        break;
    }
}


/*
�Ƚ�ǰ����������������ȼ�
(Ϊ���жϷ��㣬����һ���Ⱥš�=����Ϊ���ʽ�Ķ����)
top_optr>=current_optr����1
top_optr<current_optr����-1
top_optr��current_optr�ֱ�Ϊ�������ŷ���0
*/
int Priority(char top_optr, char current_optr)
{
    int pri;
    switch(current_optr)
    {
    case '+':
    case '-':
        if(top_optr == '(' || top_optr == '=')
            pri = -1;
        else
            pri = 1;
        break;

    case '*':
    case '/':
        if(top_optr == '*' || top_optr == '/' || top_optr == ')')
            pri = 1;
        else
            pri = -1;
        break;

    case '(':
        if(top_optr == ')')		//�������Ҳ಻�����ϳ���������
        {
            cout << "���ʽ��ʽ����\n";
            return 0;
        }
        else
            pri = -1;
        break;

    case ')':
        if(top_optr == '(')
            pri = 0;		 //�����������
        else
            pri = 1;
        break;

    case '=':
        if(top_optr == '(')
        {
            cout << "���Ų�ƥ��\n";
            return 0;
        }
        else if(top_optr == '=')
            pri = 0;		//�Ⱥ���ԣ�����0
        else
            pri = 1;
        break;
    }
    return pri;
}


/*
�����������������������������
*/
double calculate(double a, int oper, double b)
{
    switch(oper)
    {
    case '+':
        return a + b;
    case '-':
        return a - b;
    case '*':
        return a * b;
    case '/':
        if (b != 0)
            return a / b;
        else
        {
            cout << "��0������\n";
            return 0;
        }
    }
}


/*
�Զ�λ��������ֵƴ��
*/
double NumberSplicing(char ch[])
{
    int dot = 0; 	//�Ƿ�����С����ı�־
    double temp = 0;	//��ʱƴ�ӵ���ֵ
    static int len = 10;

    for(int n = 0; n < strlen(ch); n++)
    {
        char c = ch[n];
        if(c == '.')
            dot = 1;	//����־��Ϊ1
        else
        {
            c -= '0';		//�Ƚ���Ӧ�������ַ�ת��������
            if(dot == 0)
                temp = temp * 10 + c;
            else
            {
                temp = temp + (double)c / len; //С�����һλ����x�൱�� top_optr/10;
                len *= 10;					  //С����ĵڶ�λ���൱�� x/100;
                //cout<<"����ת���е��ݴ�ֵ��"<<temp<<endl;
            }
        }
    }
    return temp;
}


/*
������ʽ��ֵ��
��ʼ������ջ��һ��������ջ��һ�������ջ��

�������ұ���ÿһ���ַ���������������ѭ�����ԭ�����£�
��1������������ֱ��ѹ������ջ����
��2�������������+-* /��ʱ����������ջΪ�գ���ֱ�ӷŵ�������ջ�������򣬼���3����
��3����������ջ��Ԫ�ص����ȼ��ȵ�ǰ����������ȼ�С����ֱ��ѹ��ջ��������ִ�в��裨4����
��4����������ջ�����������ֲ�����������ջ����������������㣬��������ѹ������ջ�����ظ���2���ͣ�3��
	 ֱ����ǰ�������ѹ�������ջ����
��5�����������š�����ʱ��ֱ��ѹ�������ջ����
��6�����������š�����ʱ�����ε���������ջ�����������������ջ������������֣�ֱ�������Ĳ�����Ϊ�����š�
*/
double CalcExp(char express[])
{
    double a, b;				//����������
    char opera;				//�����
    char c;					//�ַ�����
    char top_optr;					//x������ȡ�����ջջ���������
    stack<char> oper;
    stack<double> data;	//�����ջջ�����������������ջ
    char tempNum[20];		//���λ����Ӧ���ַ�����
    int j = 0;

    int i = 0, flag = 0;		//flag����־�����������λ��

    oper.push('=');			//�Ƚ������(=)���������ջ

    c = express[i++];
    double num = 0;

    while(c != '=' || top_optr != '=')			//ѭ��������ʽ�е�ÿ���ַ�
    {
        if(IsOperator(c))	//���������
        {
            if(flag)		//����������ջ����Ϊ��ȡ������ʱ�����ֲ�û�м�ʱ��������ջ��
            {
                tempNum[j] = 0;
                j = 0;
                num = NumberSplicing(tempNum);	//����������ʱ������ֵƴ�ӵĽ�����ػ���
                //cout << "n----" << num << endl;
                data.push(num);			///////////////////////////////////////////////////////////
                num = 0; 				//��ջ֮�����ĳһ�����������ݴ�ֵ
                flag = 0;				//�ҽ���־��0����ʾ����������ջ
            }

            switch(Priority(top_optr, c))
            {
            case -1:	//��ǰ�����c����ǰһ�����x
                //cout << "o----" << c << endl;
                oper.push(c);		//��ǰ�������ջ/////////////////////////////////
                c = express[i++];		//ȡ���ʽ��һ�ַ�
                break;

            case 0:					//���ţ��Ⱥţ����
                oper.pop();			//�������벿�ֳ�ջ��������
                c = express[i++];		//ȡ���ʽ��һ�ַ�
                break;

            case 1:						//��ǰ�����cС�ڵ���ǰһ�����x
                opera = oper.top();		//��ջ֮ǰȡ��ջ��Ԫ��
                oper.pop();				//�������ջ

                b = data.top();
                data.pop();
                a = data.top();
                data.pop();				//������������ջ
                double t = calculate(a, opera, b);	//������
                data.push(t);		//����������ջ
                break;
            }
        }

        else if(c >= '0' && c <= '9' || c == '.')	//��������������ַ�(����ջ����Ϊ�����Ƕ�λ���֣�
        {
            tempNum[j++] = c;
            flag = 1; 				//���ò���������ʾ������δ��ջ
            c = express[i++];
        }
        else
        {
            cout << "��������\n";
            return 0;
        }

        top_optr = oper.top();		//��ȡ�����ջ����Ԫ��
        //cout<<"ջ���Ĳ�����Ϊ��"<<top_optr<<endl;
    }

    num = data.top();

    StackClear(oper);
    StackClear(data);		//�������ջ
    //cout<<num<<endl;

    return 	num;	//��������ջջ��Ԫ�أ���Ϊ������

}


int main()
{
    char express[100] = "3*2+5*3+(7*(8-2))+5=";
    string a = "3+2*(5+3*5)+2=";//45 true
    string b = "3*-5/3/-5=";//
    string c = "6*(5-2)/-2=";//-9 ture
    string d = "7+3--5=";
    string e = "-3*2+5*-3+(7*(8-2))+5=";
    string f = "4.5+4.5+1-0.25=";
    string g = "1.233+2.1*-3.32=";
    string h = "1+2+3+4=";
    string i = "3+2*(5+5+5+3*5)+2=";//65
    //	cout<"������Ҫ����ı��ʽ����=������:";
    //	cin>>express;
    cout << express << CalcExp(express);
    return 0;
}
