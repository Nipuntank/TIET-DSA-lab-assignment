#include <iostream>
using namespace std;
class Circular_Queue
{
    int *data;
    int size;
    int capacity;
    int nextindex;
    int firstindex;

public:
    Circular_Queue(int S)
    {
        data = new int(S);
        firstindex = -1;
        nextindex = -1;
        capacity = S;
        size = 0;
    }
    int getSize()
    {
        return size;
    }
    bool isEmpty()
    {
        if (firstindex == -1)
            return true;
        else
            return false;
    }
    bool isFULL()
    {
        if (firstindex == 0 && nextindex == capacity - 1)
        {
            return true;
        }
        if (firstindex == nextindex + 1)
        {
            return true;
        }
        return false;
    }
    void enqueue(int ele)
    {
        if (isFULL())
        {
            cout << "FULL";
        }
        else
        {
            if (firstindex == -1)
            {
                firstindex = 0;
            }
            size++;
            nextindex = (nextindex + 1) % capacity;
            data[nextindex] = ele;
        }
    }
    int dequeue()
    {
        int val;
        if (isEmpty())
        {
            cout << "Empty";
            return 0;
        }
        else
        {
            val = data[firstindex];
            if (firstindex == nextindex)
            {
                size = 0;
                nextindex = -1;
                firstindex = -1;
            }
            else
            {
                size--;
                firstindex = (firstindex + 1) % capacity;
            }
            return val;
        }
    }
    int peek()
    {
        if (firstindex == -1 && nextindex == -1)
        {
            cout << "Empty" << endl;
            return -1;
        }
        return data[firstindex];
    }
    void display()
    {
        int i;
        if (isEmpty())
        {
            cout << "Empty";
            return;
        }
        else
        {
            cout << endl;
            for (i = firstindex; i != nextindex; i = (i + 1) % capacity)
            {
                cout << data[i] << " ";
            }
            cout << data[i];
            cout << endl;
        }
    }
};
int main()
{
    Circular_Queue q(4);
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.display();
    cout << q.getSize() << endl;

    q.dequeue();
    q.display();
    cout << q.getSize() << endl;

    q.dequeue();
    q.display();
    q.enqueue(50);
    cout << q.getSize() << endl;

    q.dequeue();
    q.display();
    cout << q.getSize() << endl;

    q.dequeue();
    q.display();
    q.enqueue(100);
    cout << q.getSize() << endl;

    q.dequeue();
    q.display();
    cout << q.getSize() << endl;
    q.enqueue(200);
    q.display();
    cout << q.getSize() << endl;

    return 0;
}