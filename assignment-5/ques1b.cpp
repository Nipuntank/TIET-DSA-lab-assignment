#include <iostream>
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
        head = NULL;
        tail = NULL;
        size = 0;
    }
    bool isEmpty()
    {
        return size == 0;
    }
    int getsize()
    {
        return size;
    }
    int peek()
    {
        if (head == NULL)
        {
            return -1;
        }
        return head->data;
    }
    void enqueue(int ele)
    {
        Node *newnode = new Node(ele);
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
        if (head == NULL)
        {
            cout << "Empty";
            return 0;
        }
        int val = head->data;
        head = head->next;
        size--;
        return val;
    }
    void display()
    {
        Node *temp = head;
        while (temp->next != NULL)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};
int main()
{
    int t;
    cin >> t;
    queue_ll q;
    while (t--)
    {
        int choice, input;
        cin >> choice;
        switch (choice)
        {
        case 1:
            cin >> input;
            q.enqueue(input);
            break;
        case 2:
            cout << q.dequeue() << "\n";
            break;
        case 3:
            cout << q.peek() << "\n";
            break;
        case 4:
            cout << q.getsize() << "\n";
            break;
        default:
            cout << ((q.isEmpty()) ? "true\n" : "false\n");
            break;
        }
    }
    return 0;
}