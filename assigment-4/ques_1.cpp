#include <iostream>
using namespace std;
class stack
{
    int *data;
    int nextindex;
    int capacity;

public:
    stack(int totalsize)
    {
        data = new int(totalsize);
        nextindex = 0;
        capacity = totalsize;
    }
    int size()
    {
        return nextindex - 1;
    }
    bool isEmpty()
    {
        return nextindex = 0;
    }
    void push(int ele)
    {
        if (nextindex == capacity)
        {
            cout << "stack is FULL";
            return;
        }
        data[nextindex] = ele;
        nextindex++;
    }
    bool isFull()
    {
        return nextindex == capacity;
    }
    void display()
    {
        int si = size();
        for (int i = 0; i < si; i++)
        {
            cout << data[i] << " ";
        }
        cout << endl;
    }
    int pop()
    {
        if(isEmpty())
        {
            cout<<"Stack is Empty"<<endl;
            return -1;
        }
        nextindex--;
        return data[nextindex-1];
    }
    int top()
    {
        return data[nextindex-1];
    }
};
int main()
{
    stack s(10);
    cout << "1.push" << endl;
    cout << "2.pop" << endl;
    cout << "3.isEmpty" << endl;
    cout << "4.isFull" << endl;
    cout << "5.display" << endl;
    cout << "6.peek" << endl;
    int n;
    cout << "Enter your Choice:" << endl;
    char c = 'y';
    while (c != 'n')
    {
         cin >> n;
        switch (n)
        {
        case 1:
        {
            int ele;
            cout<<"Enter element to be added:";
            cin>>ele;
            s.push(ele);
            break;
        }
        case 2:
        {
            cout << s.pop() << endl;
            break;
        }
        case 3:
        {
            if (s.isEmpty())
            {
                cout << "Stack is Empty";
            }
            else
            {
                cout << "Stack is not Empty";
            }
            break;
        }
        case 4:
        {
            if (s.isFull())
            {
                cout << "Stack is Full";
            }
            else
            {
                cout << "Stack is not Full";
            }
            break;
        }
        case 5:
        {
            s.display();
            break;
        }
        case 6:
        {
            cout << s.top() << endl;
            break;
        }
        }
        cout<<"Enter 'y' to Continue:";
        cin >> c;
    }

    return 0;
}