#include <iostream>
#include <stack>
#include <math.h>
using namespace std;
int postfix_eval(string post)
{
    stack<int> s;
    for (int i = 0; i < post.length(); i++)
    {
        if (post[i] >= '0' && post[i] <= '9')
        {
            s.push(post[i] - '0');
        }
        else
        {
            int op2 = s.top();
            s.pop();
            int op1 = s.top();
            s.pop();

            switch (post[i])
            {
            case '+':
            {
                s.push(op1 + op2);
                break;
            }
            case '-':
            {
                s.push(op1 - op2);
                break;
            }
            case '*':
            {
                s.push(op1 * op2);
                break;
            }
            case '/':
            {
                s.push(op1 / op2);
                break;
            }
            case '^':
            {
                s.push(op1 ^ op2);
                break;
            }
            }
        }
    }
    return s.top();
}

int main()
{
    string str;
    cin>>str;
    int x = postfix_eval(str);
    cout<<x;

    return 0;
}