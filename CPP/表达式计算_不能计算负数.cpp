#include <iostream>
#include <string>
#include <stack>
#include <cctype>
#include <cstdlib>
#include <cmath>
#define IN 1
#define OUT 0
using namespace std;

int charNo(char ch)
{
    const string optrs = "+-*/^()=";
    for (int i = 0; optrs[i] != '\0'; i++)
        if (optrs[i] == ch)
            return i;
    return -1;
}

int priority(int stk, int out)
{
    const int priorityMap[7][8] = {
    //   +  -  *  /  ^  (  )  = out/stack
        {0, 0, 1, 1, 1, 1, 0, 0}, // +
        {0, 0, 1, 1, 1, 1, 0, 0}, // -
        {0, 0, 0, 0, 0, 1, 0, 0}, // *
        {0, 0, 0, 0, 0, 1, 0, 0}, // /
        {0, 0, 0, 0, 0, 1, 0, 0}, // ^    
        {1, 1, 1, 1, 1, 1, 0, 0}, // (    
        {1, 1, 1, 1, 1, 1, 0, 0}, // )
    };
    return priorityMap[stk][out];
}

double valueOf(double a, double b, char optr)
{
    switch (optr)
    {
        case '+':
            return a + b;
        case '-':
            return a - b;
        case '*':
            return a * b;
        case '/':
            return a / b;
        case '^':
            return pow(a, b);
        default:
            return 1;
    }
}

double calculate(string expression)
{
    stack<double> numbers;
    stack<char> operators;
    if (expression[expression.length() - 1] != '=')
        expression += "=";
    int s = -1;
    for (int i = 0; i < expression.length(); i++)
    {
        if (isdigit(expression[i]) && s == -1)
            s = i;
        else
        {
            if ((expression[i] == ' ' || charNo(expression[i]) != -1) && s != -1)
            {
                numbers.push(atof(expression.substr(s, i - s).c_str()));
                s = -1;
            }
            if (charNo(expression[i]) != -1)
            {
                if (operators.empty() && expression[i] != ')')
                    operators.push(expression[i]);
                else
                {
                    if (priority(charNo(operators.top()), charNo(expression[i])) == IN)
                        operators.push(expression[i]);
                    else
                    {
                        while (!operators.empty() && priority(charNo(operators.top()), charNo(expression[i])) == OUT)
                        {
                            char topOptr = operators.top();
                            operators.pop();

                            if (topOptr != '(')
                            {
                                double b = numbers.top();
                                numbers.pop();
                                double a = numbers.top();
                                numbers.pop();
                                numbers.push(valueOf(a, b, topOptr));
                            }
                            else
                                break;
                        }
                        if (expression[i] != ')')
                            operators.push(expression[i]);
                        else if (!operators.empty() && operators.top() == '(')
                            operators.pop();
                    }
                }
            }
        }
    }
    return numbers.top();
}

int main(int argc, char const *argv[])
{
    string expression;
    getline(cin, expression);
    cout << calculate(expression) << endl;
    return 0;
}
