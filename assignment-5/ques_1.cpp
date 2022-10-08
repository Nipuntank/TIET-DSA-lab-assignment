#include <iostream>
using namespace std;
class queue
{
    int *data;
    int nextindex;
    int firstindex;
    int size;
    int capacity;

public:
    queue(int s)
    {
        data = new int[s];
        nextindex = 0;
        firstindex = -1;
        size = 0;
        capacity = s;
    }
    bool isEmpty()
    {
        return size == 0;
    }
    int size_q()
    {
        return size;
    }
    void push(int ele)
    {
        if (size==capacity)
        {
            cout << "Full";
            return ;
        }
        data[nextindex] = ele;
        nextindex = (nextindex + 1) % capacity;
        if (firstindex == -1)
        {
            firstindex = 0;
        }
        size++;
    }
    int pop()
    {
        if (isEmpty())
        {
            cout << "empty";
            return 0;
        }
        int ans = data[firstindex];
        firstindex = (firstindex + 1) % capacity;
        size--;
        return ans;
    }
    int front()
    {
        if (isEmpty())
        {
            cout << "empty";
            return 0;
        }
        return data[nextindex];
    }
};
int main()
{
    queue q(5);

    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    q.push(50);
    q.push(60);

    cout << q.front() << endl;
    cout << q.pop() << endl;
    cout << q.pop() << endl;
    cout << q.pop() << endl;
    cout << q.size_q() << endl;
    cout << q.isEmpty() << endl;

    return 0;
}