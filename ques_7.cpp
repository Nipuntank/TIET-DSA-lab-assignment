#include <iostream>
using namespace std;
#include <stack>
int getMin(stack<int> &input, int n)
{
    stack<int> extra;
    while (!input.empty())
    {
        if (extra.empty())
        {
            extra.push(input.top());
        }
        if (!input.empty() && input.top() < extra.top())
        {
            extra.pop();
            extra.push(input.top());
        }
        input.pop();
    }
    return extra.top();
}
int main()
{
    stack<int> input;
    int size;
    cout<<"Enter the size:";
    cin >> size;
    for (int i = 0, val; i < size; i++)
    {
        cin >> val;
        input.push(val);
    }
    cout << getMin(input, size);

    return 0;
}