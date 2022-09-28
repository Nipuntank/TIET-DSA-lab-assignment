#include <iostream>
using namespace std;
#include "linkedlist.cpp"
class Pair
{
public:
    Node *head;
    Node *tail;
};
Pair reverseLinkedList(Node *head,int m) {
    // Write your code here
    int count=0;
    if(head==NULL || head->next==NULL)
    {
        Pair ans;
        ans.head = head;
        ans.tail = head;
        return ans;
    }
    Node *current = head;
    Node *prev = NULL;
    while(current!=NULL && count!=m)
    {
        Node *up = current->next;
        current->next = prev;
        prev = current;
        current = up;
        count++;
        
    }
    Pair ans;
    ans.head = prev;
    ans.tail=head;
    return ans;
}
Node *reverse_m(Node *head, int m, int n)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }
    int c1 = 1;
    int c2 = 1;
    Node *h1 = head;
    while (h1->next != NULL && c1 != m-1)
    {
        c1++;
        h1 = h1->next;
    }
    Node *h2 = head;
    while (h2->next != NULL && c2!= n)
    {
        c2++;
        h2 = h2->next;
    }
    Node *h3 = h2->next;
    h2->next=NULL;
    Pair smallans =reverseLinkedList(h1->next,n);
    h1->next=smallans.head;
    smallans.tail->next = h3;
    return head;
}
int main()
{
    Node *head = input();
    int m, n;
    cin >> m >> n;
    head = reverse_m(head, m, n);
    print(head);

    return 0;
}