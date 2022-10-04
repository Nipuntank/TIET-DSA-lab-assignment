#include <iostream>
using namespace std;
#include "linkedlist.cpp"
bool plaidrome(Node *head)
{
    if (head == NULL)
    {
        return true;
    }
    Node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    while (head != temp)
    {
        if (head->data != temp->data)
        {
            return false;
        }
        head = head->next;
        temp = temp->prev;
    }
    return true;
}
int main()
{
    Node *head = input();
    if (plaidrome(head))
    {
        cout << "Yes" << endl;
    }
    else
    {
        cout << "No" << endl;
    }

    return 0;
}