#include <iostream>
#include <stack>
#include <queue>
using namespace std;
void leave(queue<int> &q)
{
    stack<int> s;
    int mid = (q.size() + 1) / 2;
    for (int i = 0; i < mid; i++)
    {
        s.push(q.front());
        q.pop();
    }
    while (!s.empty())
    {
        q.push(s.top());
        s.pop();
    }
    for (int i = 0; i < mid; i++)
    {
        q.push(q.front());
        q.pop();
    }
    for (int i = 0; i < mid; i++)
    {
        s.push(q.front());
        q.pop();
    }
    while (!s.empty())
    {
        q.push(s.top());
        s.pop();
        q.push(q.front());
        q.pop();
    }
}

int main()
{
    queue<int> q;
    int n;
    cout<<"Enter size:";
    cin>>n;
    cout<<"Enter the values:";
    while(n--)
    {
        int val;
        cin>>val;
        q.push(val);
    }
    leave(q);
    int length = q.size();
    for (int i = 0; i < length; i++)
    {
        cout << q.front() << " ";
        q.pop();
    }

    return 0;
}