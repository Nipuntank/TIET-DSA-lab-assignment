#include <iostream>
#include <stack>
#include<string>
using namespace std;
void reverse(string &str)
{
    stack<int> s;
    for(char c:str)
    {
        s.push(c);
    }
    for(int i=0;i<str.length();i++)
    {
        str[i]=s.top();
        s.pop();
    }
}
int main()
{
    stack <char> s;
    string str;
    cout << "Enter the string:";
    getline(cin,str);
    cout<<str<<endl;
    reverse(str);
    cout<<str;
    
    
    
    return 0;
}