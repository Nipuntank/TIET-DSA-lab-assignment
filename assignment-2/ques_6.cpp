#include<iostream>
using namespace std;
#include "linkedlist.cpp"
int lenght(Node *head)
{
    if(head==NULL)
    {
        return 0;
    }
    int ans =1+lenght(head->next);
    return ans;
}
Node *rotate_k(Node *head,int k)
{
    int len = lenght(head);
    if(head==NULL || head->next==NULL)
    {
        return head;
    }
    if(len<k)
    {
        return NULL;
    }
    int count=1;
    Node *temp =head;
    Node *tail = head;
    while(count!=len-k && temp->next!=NULL )
    {
        count++;
        temp=temp->next;
    }
    while(tail->next!=NULL)
    {
        tail = tail->next;
    }
    tail->next = head;
    head=temp->next;
    temp->next =NULL;
    return head;


}
int main()
{
    Node *head = input();
    int k;
    cin>>k;
    cout<<endl;
    head = rotate_k(head,k);
    print(head);
    return 0;
}