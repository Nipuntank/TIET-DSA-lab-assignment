#include <iostream>
using namespace std;
#include "linkedlist.cpp"
int count(Node *head, int key)
{
    int c = 0;
    if (head == NULL)
    {
        return 0;
    }
    while (head->next != NULL)
    {
        if (head->data == key)
        {
            c++;
        }
        head = head->next;
    }

    return c;
}
Node *occurrences(Node *head, int key)
{
    if (head == NULL)
    {
        return head;
    }
    Node *temp = head;
    while (temp->next != NULL)
    {
        if (temp->next->data == key)
        {
            Node *a = temp->next->next;
            delete temp->next;
            temp->next = a;
        }
        else
        {
            temp = temp->next;
        }
    }
    if (head->data == key)
    {
        Node *a = head->next;
        delete head;
        head = a;
        return head;
    }

    return head;
}
int main()
{
    int key;
    Node *head = input();
    cout << "Enter the value:";
    cin >> key;
    cout << endl;
    cout <<"Number of time "<<key<<" is repeated in linked list: "<<count(head, key)<<endl;
    head = occurrences(head, key);
    cout<<"Linked list after deletion all key elements:";
    print(head);
    cout<<endl<<endl;

    return 0;
}