#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};
Node *input()
{
    int data;
    cin >> data;
    Node *head = NULL;
    Node *tail = NULL;
    while (data != -1)
    {
        Node *newnode = new Node(data);
        if (head == NULL)
        {
            head = newnode;
            tail = newnode;
        }
        else
        {
            tail->next = newnode;
            tail = tail->next;
        }
        cin >> data;
    }
    return head;
}
void print(Node *head)
{
    while (head != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }
    cout<<endl;
}
class Pair
{
    public:
    Node *head;
    Node *tail;
};
Pair reverse(Node *head)
{
    if (head == NULL || head->next == NULL)
    {
        Pair ans;
        ans.head = head;
        ans.tail = head;
        return ans;
    }
    Pair smallans = reverse(head->next);

    smallans.tail->next= head;
    head->next = NULL;
    Pair ans;
    ans.head = smallans.head;
    ans.tail = head;
    return ans;
}
Node *kreverse(Node *head, int k)
{
    if (head == NULL || k == 0)
    {
        return head;
    }
    int c1 = 1;
    Node *head1 = head;
    Node *tail1 = head;
    while (c1 < k && tail1->next != NULL)
    {
        tail1 = tail1->next;
        c1++;
    }
    Node *head2 = tail1->next;
    tail1->next = NULL;
    Pair smallans = reverse(head1);
    head2 = kreverse(head2, k);
    smallans.tail->next = head2;
    return smallans.head;
}

int main()
{
    Node *head = input();
    int k;
    cin >> k;
    head = kreverse(head, k);
    print(head);
    return 0;
}