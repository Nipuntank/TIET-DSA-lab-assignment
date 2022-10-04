#include <iostream>
using namespace std;
#include "linkedlist.cpp"
int dec_bin(int n)
{
    int binary[32];
    int i = 0, chk = 0;
    while (n > 0)
    {
        binary[i] = n % 2;
        if (binary[i] == 1)
        {
            chk++;
        }
        n = n / 2;
        i++;
    }
    return chk;
}
Node *even_parity(Node *head)
{
    if (head == NULL)
    {
        return head;
    }
    Node *temp = head;
    int chk = 0;
    while (temp->next != NULL)
    {
        if (dec_bin(temp->next->data) % 2 == 0)
        {
            Node *a = temp->next->next;
            delete temp->next;
            temp->next = a;
            a->prev = temp->next;
        }
        else
        {
            temp = temp->next;
        }
        
    }
    if(dec_bin(head->data)%2==0)
    {
        Node *a = head->next;
        delete head;
        head =a;
    }
    return head;
}
int main()
{
    Node *head = input();
    head = even_parity(head);
    print(head);

    return 0;
}