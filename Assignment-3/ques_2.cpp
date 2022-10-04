#include<iostream>
using namespace std;
#include "linkedlist1.cpp"
void print_circular(Node *head)
{
    Node *temp=head;
    do{
        cout<<temp->data<<" ";
        temp= temp->next;
    }
    while(temp!=head);
    cout<<temp->data;
}
int main()
{
    Node *head=input();
    print_circular(head);

    return 0;
}