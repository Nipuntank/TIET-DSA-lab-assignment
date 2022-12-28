#include <iostream>
#include <unordered_map>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    Node(int data)
    {
        this->data = data;
        next = NULL;
    }
};
Node *takeInput()
{
    int data;
    cin >> data;
    Node *head = NULL;
    Node *tail = NULL;
    while (data != -1)
    {
        Node *newNode = new Node(data);
        if (head == NULL)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            tail->next = newNode;
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
    cout << endl;
}
void add(Node **root, int ele)
{
    Node *newnode = new Node(ele);
    newnode->next = *root;
    *root = newnode;
}
Node *intersection(Node *h1, Node *h2)
{
    unordered_map<int, bool> map;
    Node *head = NULL;
    while (h1 != NULL)
    {
        map[h1->data] = true;
        h1 = h1->next;
    }
    while (h2 != NULL)
    {
        if (map[h2->data] == true)
        {
            add(&head, h2->data);
        }
        h2 = h2->next;
    }
    return head;
}
Node *Union(Node *h1,Node *h2)
{
    unordered_map<int, bool> map;
    Node *head = NULL;
    while (h1 != NULL)
    {
        map[h1->data] = true;
        add(&head,h1->data);
        h1 = h1->next;
    }
    while (h2 != NULL)
    {
        if (map[h2->data]==false)
        {
            add(&head, h2->data);
        }
        h2 = h2->next;
    }
    return head;
}
int main()
{
    Node *head1 = takeInput();
    Node *head2 = takeInput();
    cout << "LL-1:";
    print(head1);
    cout << "LL-2:";
    print(head2);
    Node *h1 = intersection(head1, head2);
    cout << "Intersection:";
    print(h1);
    Node *h2 = Union(head1, head2);
    cout << "Union:";
    print(h2);
    return 0;
}