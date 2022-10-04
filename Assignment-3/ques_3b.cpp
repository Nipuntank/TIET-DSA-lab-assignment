#include<iostream>
using namespace std;
#include "linkedlist1.cpp"
int length(Node *head)
{
    int count=1;
    Node *temp=head;
    while(temp->next!=head)
    {
        temp = temp->next;
        count++;
    }
    return count;
    
}
int main()
{
    Node *head = input();
    int a=length(head);
    cout<<a<<endl;
    return 0;
}