#include <iostream>
#include <stack>
using namespace std;
bool balance(string str)
{
    stack<char> s;
    for (int i = 0; str[i] != '\0'; i++)
    {
        if (str[i] == '(' || str[i] == '[' || str[i] == '{')
        {
            s.push(str[i]);
        }
        if (s.empty() && (str[i] == ')' || str[i] == ']' || str[i] == '}'))
        {
            return false;
        }

        if (str[i] == ')')
        {
            if (s.top() == '(')
            {
                s.pop();
            }
            else
                return false;
        }
        if (str[i] == '}')
        {
            if (s.top() == '{')
            {
                s.pop();
            }
            else
                return false;
        }
        if (str[i] == ']')
        {
            if (s.top() == '[')
            {
                s.pop();
            }
            else
                return false;
        }
    }
    return s.empty() == 1;
}

int main()
{
    string str;
    cin >> str;
    cout << balance(str);

    return 0;
}