#include <iostream>
using namespace std;
#include "linkedlist.cpp"
int length(Node *head)
{
    if (head == NULL)
    {
        return 0;
    }
    return 1 + length(head->next);
}
Node *insertion(Node *head, int value, int i)
{
    Node *newnode = new Node(value);
    int len = length(head);
    if (i == 1)
    {
        newnode->next = head;
        head->prev = newnode;
        head = newnode;

        return head;
    }
    if (len == i)
    {
        Node *temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        Node *temp2 = temp->next;
        temp->next = newnode;
        temp2->prev = newnode;
        newnode->prev = temp;
        newnode->next = NULL;
    }
    else
    {
        int c1 = 1;
        Node *temp = head;
        while (temp != NULL && c1 != i)
        {
            temp = temp->next;
            c1++;
        }
        Node *a = temp->next;
        temp->next = newnode;
        a->prev = newnode;
        newnode->prev = temp;
        newnode->next = a;
    }

    return head;
}
Node *deletion(Node *head, int i)
{
    int len = length(head);
    if (i == 1)
    {
        Node *a = head;
        head = head->next;
        head->prev = NULL;
        delete a;
        return head;
    }
    if (i == len)
    {
        Node *temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        Node *temp2 = temp->prev;
        temp2->next = NULL;
        delete temp;
        return head;
    }
    else
    {
        Node *temp = head;
        int count = 1;
        while (count != i && temp->next != NULL)
        {
            temp = temp->next;
            count++;
        }
        Node *a = temp->next;
        delete temp;
        temp->prev->next = a;
    }
    return head;
}
int search(Node *head, int data)
{
    if (head == NULL)
    {
        return 0;
    }
    int count = 1;
    while (head->data != data)
    {
        head = head->next;
        count++;
    }
    return count;
}

int main()
{
    cout << "Enter the linked list:";
    Node *head = input();
    cout << "1.Insertion anywhere in the linked list" << endl;
    cout << "2.Deletion of a specific node" << endl;
    cout << "3.Search for a node" << endl;
    int t;
    char c = 'y';
    while (c == 'y')
    {
        cout << "Enter your choice:";
        cin >> t;
        switch (t)
        {
        case 1:
        {
            int i, value;
            cout << "Enter the value and position:";
            cin >> value >> i;
            head = insertion(head, value, i);
            cout << "After addition of element:";
            print(head);
            break;
        }
        case 2:
        {
            int i;
            cout << "Enter the position to de deleted:";
            cin >> i;
            head = deletion(head, i);
            cout << "After deletion of elements:";
            print(head);
            break;
        }
        case 3:
        {
            int value;
            cout << "Enter the value to search in the linked list:";
            cin >> value;
            cout << "Element present at position:" << search(head, value);
            break;
        }
        }
        cout<<endl<<"Want to Continue y/n:";
        cin >> c;
    }

    return 0;
}