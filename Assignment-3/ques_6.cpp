#include <iostream>
using namespace std;
#include "linkedlist1.cpp"
int length(Node *head)
{
    int count = 1;
    Node *temp = head;
    do
    {
        /* code */
        count++;
        temp = temp->next;
    } while (temp->next != head);
    return count;
}
void split(Node *head)
{
    int len = length(head);
    if (head == NULL || head->next == NULL)
    {
        return;
    }
    int mid = (len + 1) / 2;
    Node *temp = head;
    while (mid!=1)
    {
        temp = temp->next;
        mid--;
    }
    Node *h1 = temp->next;
    temp->next = head;
    Node *t1 = h1;
    while (t1->next != head)
    {
        t1 = t1->next;
    }
    t1->next = h1;
    cout << "1st linked list: ";
    print(head);
    cout << "2nd linked list: ";
    print(h1);
}
int main()
{
    Node *head = input();
    print(head);
    split(head);

    return 0;
}