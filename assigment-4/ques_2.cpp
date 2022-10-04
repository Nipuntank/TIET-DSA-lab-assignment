#include <iostream>
#include <stack>
using namespace std;
void reverse(string *str)
{
    int len = str->length();
    stack<int> s;
    for(int i=0;i<len;i++)
    {
        s.push(str[i]);
    }
    for(int i=0;i<len;i++)
    {
        str[i]=s.top();
        s.pop();
    }
}
int main()
{
    stack <char> s;
    string str;
    int len = str.length();
    cout << "Enter the string:";
    cin>>str;
    cout<<str;
    
    
    return 0;
}