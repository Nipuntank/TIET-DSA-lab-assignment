#include<iostream>
using namespace std;
#include"linkedlist.cpp"
// Iterative appraoch
Node *reverse(Node *head)
{
    if(head==NULL || head->next==NULL)
    {
        return head;
    }
    Node *current=head;
    Node *prev = NULL;
    while(current!=NULL)
    {
        Node *up = current->next;
        current->next =prev;
        prev =current;
        current = up;

    }
    return prev;

}
Node *reverse_rec(Node *head)
{
    if(head==NULL || head->next==NULL)
    {
        return head;
    }
    Node *ans = reverse_rec(head->next);
    Node *temp = head->next;
    temp->next = head;
    head->next = NULL;

    return ans;

    
}
int main()
{
    cout<<"Enter the linked list:";
    Node *head = input();
    print(head);
    cout<<endl;
    head = reverse(head);
    print(head);
    cout<<endl;
    head = reverse_rec(head);
    print(head);
    
    return 0;
}