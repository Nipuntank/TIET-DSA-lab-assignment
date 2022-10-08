#include<iostream>
using namespace std;
class Node
{
    public:
    int data;
    Node *next;
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};
class queue_ll
{
    Node *head;
    Node *tail;
    int size;
public:
    queue_ll()
    {
        // Implement the Constructor
        head=NULL;
        tail=NULL;
        size=0;
        
    }

    /*----------------- Public Functions of Stack -----------------*/

    int getSize()
    {
        // Implement the getSize() function
        return size;
    }

    bool isEmpty()
    {
        // Implement the isEmpty() function
        return getSize() == 0;
    }

    void enqueue(int data)
    {
        // Implement the enqueue() function
        Node *newnode = new Node(data);
        if (head == NULL)
        {
            head = newnode;
            tail = newnode;
            size++;
            return;
        }
        tail->next = newnode;
        tail = tail->next;
        size++;
    }

    int dequeue()
    {
        // Implement the dequeue() function
        if (head == NULL)
        {
            return -1;
        }
        int ans = head->data;
        head = head->next;
        size--;
        return ans;
        
    }

    int front()
    {
        // Implement the front() function
        if (head == NULL)
        {
            return -1;
        }
        return head->data;
    }
};
int main()
{
    
    return 0;
}