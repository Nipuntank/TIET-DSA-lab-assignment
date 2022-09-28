#include<iostream>
using namespace std;
#include"linkedlist.cpp"
Node *midpoint(Node *head)
{
    if(head==NULL)
    {
        return head;
    }
    Node *slow=head;
    Node *fast =head->next->next;
    while(fast!=NULL)
    {
        if(fast->next==NULL)
        {
            slow = slow->next;
            break;
        }
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}
int main()
{
    cout<<"Enter the linked list:";
    Node *head = input();
    print(head);
    Node *mid = midpoint(head);
    cout<<endl<<"Mid point of the linked list : ";
    if(mid!=NULL)
    {
        cout<<mid->data<<" ";
        cout<<endl;
    }


    
    return 0;
}