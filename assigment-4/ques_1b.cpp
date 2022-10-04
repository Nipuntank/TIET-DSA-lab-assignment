#include <iostream>
using namespace std;
class Node
{
public:
    Node *next;
    int data;
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};
class stack
{
    Node *head;
    int size;

public:
    stack()
    {
        head = NULL;
        size = 0;
    }
    int getSize()
    {
        return size;
    }
    bool isEmpty()
    {
        return size == 0;
    }
    void push(int element)
    {
        Node *newnode = new Node(element);
        newnode->next = head;
        head = newnode;
        size++;
    }
    int pop()
    {
        if (head == NULL)
        {
            cout << "Stack is Empty" << endl;
            return 0;
        }
        int ans = head->data;
        head = head->next;
        size--;
        return ans;
    }
    int top()
    {
        if (head == NULL)
        {
            return -1;
        }
        return head->data;
    }
};
int main()
{
    stack st;
    st.push(10);
    st.push(20);
    st.push(30);
    cout << st.getSize() << endl;
    cout << st.top() << endl;
    cout << st.pop() << endl;
    cout << st.pop() << endl;
    cout << st.top() << endl;
    cout << st.pop() << endl;
    cout << st.getSize() << endl;
    cout << st.isEmpty() << endl;
    return 0;
}