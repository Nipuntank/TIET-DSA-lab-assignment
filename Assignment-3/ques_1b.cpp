#include <iostream>
using namespace std;
#include "linkedlist1.cpp"
int length(Node *head)
{
    int count = 1;
    Node *temp = head;
    do
    {
        /* code */
        temp = temp->next;
        count++;
    } while (temp->next != head);
    return count;
}
Node *insertion(Node *head, int value, int i)
{
    int len = length(head);
    Node *newnode = new Node(value);
    if (i == 1)
    {
        Node *temp = head;
        while (temp->next != head)
        {
            temp = temp->next;
        }
        temp->next = newnode;
        newnode->next = head;
        head = newnode;
        return head;
    }
    else if (i == len)
    {
        Node *temp = head;
        while (temp->next != head)
        {
            temp = temp->next;
        }
        temp->next = newnode;
        newnode->next = head;
        return head;
    }
    else
    {
        int c1 = 1;
        Node *temp = head;
        while (temp->next != head && c1 != i - 1)
        {
            c1++;
            temp = temp->next;
        }
        Node *a = temp->next;
        temp->next = newnode;
        newnode->next = a;
    }
    return head;
}
Node *deletion(Node *head, int i)
{
    int len = length(head);
    if (i == 1)
    {
        Node *temp = head;
        while (temp->next != head)
        {
            temp = temp->next;
        }
        Node *a = head;
        temp->next = a->next;
        head = head->next;
        return head;
    }
    if (i == len)
    {
        Node *temp = head;
        while (temp->next->next != head)
        {
            temp = temp->next;
        }
        temp->next = head;
    }
    else
    {
        int c1=1;
        Node *temp=head;
        while(temp->next!=NULL && c1!=i-1)
        {
            temp = temp->next;
            c1++;
        }
        Node *a = temp->next->next;
        delete temp->next;
        temp->next=a;
    }

    return head;
}
void search(Node *head, int ele)
{
    int count = 0, chk = 0;
    while (head->next != head)
    {
        if (head->data == ele)
        {
            chk = 1;
            count++;
            break;
        }
        count++;
        head = head->next;
    }
    if (chk == 0)
    {
        cout << "Not Found!" << endl;
        return;
    }
    else
    {
        cout << "Found at:" << count<<endl;
    }
}
int main()
{
    cout << "Enter your linked list:";
    Node *head = input();
    print(head);
    char c = 'y';
    int t;
    cout << "1.Insertion"<<endl;
    cout << "2.Deletion"<<endl;
    cout << "3.Searching"<<endl;
    while (c == 'y')
    {
        cout << "Enter your choice from above:";
        cin >> t;
        switch (t)
        {
        case 1:
        {
            int ele, i;
            cout << "Enter the element and in which position to be added:";
            cin >> ele >> i;
            head = insertion(head, ele, i);
            cout << "After addition:";
            print(head);
            break;
        }
        case 2:
        {
            int i;
            cout << "Enter the position to be deleted:";
            cin >> i;
            head = deletion(head, i);
            cout << "After Deletion:";
            print(head);
            break;
        }
        case 3:
        {
            int val;
            cout << "Enter the element to be searched:";
            cin >> val;
            search(head, val);
            break;
        }
        default:
        {
            cout << " OOPS ! Enter from the above choices only:" << endl;
            break;
        }
        }
        cout << "Want to Continue y/n:";
        cin >> c;
    }

    return 0;
}