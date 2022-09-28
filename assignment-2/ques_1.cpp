#include <iostream>
using namespace std;
#include "linkedlist.cpp"
Node *insertion_begn(Node *head, int data)
{
    Node *newnode = new Node(data);
    if (head == NULL)
    {
        return head;
    }
    newnode->next = head;
    head = newnode;
    return head;
}
Node *insertion_end(Node *head, int data)
{
    Node *newnode = new Node(data);
    if (head == NULL)
    {
        return head;
    }
    Node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newnode;
    newnode->next = NULL;
    return head;
}
Node *insertion_speci(Node *head, int data, int a, int b)
{
    Node *newnode = new Node(data);
    if (head == NULL)
    {
        return head;
    }
    Node *t1 = head;
    Node *t2 = head;
    while (t1 != NULL)
    {
        if (t1->next->data >= a)
        {
            t1 = t1->next;
            break;
        }

        t1 = t1->next;
    }
    while (t2 != NULL)
    {
        if (t2->next->data >= b)
        {
            t2 = t2->next;
            break;
        }

        t2 = t2->next;
    }
    if (t1 != NULL && t2 != NULL)
    {
        t1->next = NULL;
        t1->next = newnode;
        newnode->next = t2;
    }
    return head;
}
Node *deletion_beg(Node *head)
{
    if(head==NULL)
    {
        return head;
    }
    Node *temp =head->next;
    delete head;
    head = temp;
    return head;
}
Node *deletion_end(Node *head)
{
    if(head==NULL)
    {
        return head;
    }
    if(head->next==NULL)
    {
        delete head;
        return NULL;
    }
    Node *temp =head;
    while(temp->next->next!=NULL)
    {
        temp = temp->next;
    }
    delete temp->next;
    temp->next =NULL;
    return head;
}
Node *deletion_spec(Node *head,int value)
{
    if(head==NULL)
    {
        return head;
    }
    Node *temp=head;
    while(temp->next->data!=value)
    {
        temp = temp->next;
    }
    Node *a = temp->next->next;
    delete temp->next;
    temp->next = a;

    return head;
}
int search(Node *head,int value)
{
    if(head==NULL)
    {
        return 0;
    }
    int count=1;
    while(head!=NULL && head->data!=value)
    {
        head = head->next;
        count++;
    }
    return count;
}
int main()
{
    int t;
    cout << "Enter the values:";
    Node *head = input();
    cout<<"Liked list:";
    print(head);
    cout<<"1.Insertion at the beginning."<<endl;
    cout<<"2.Insertion at the end."<<endl;
    cout<<"3.Insertion in between"<<endl;
    cout<<"4.Deletion from the beginning."<<endl;
    cout<<"5.Deletion from the end."<<endl;
    cout<<"6.Deletion of a specific node"<<endl;
    cout<<"7.Search for a node and display its position from head."<<endl;
    cout<<"8.Display all the node values."<<endl;

    char c ='y';
    while(c!='n')
    {
         cout<<endl<<"Enter your choice:"<<endl;
         cin>>t;
        switch(t)
        {
            case 1:
            {
                int data;
                cout<<"Enter the data to be added:";
                cin>>data;
                head =insertion_begn(head,data);
                print(head);
                break;
            }
            case 2:
            {
                int data;
                cout<<"Enter the data to be added:";
                cin>>data;
                head =insertion_end(head,data);
                print(head);
                break;
            }
            case 3:
            {
                int data,a,b;
                cout<<"Enter the data to be added:";
                cin>>data;
                cout<<"Enter the data in which node value u have to Enter:";
                cin>>a>>b;
                head =insertion_speci(head,data,a,b);
                print(head);
                break;

            }
            case 4:
            {
                head =deletion_beg(head);
                print(head);
                break;
            }
            case 5:
            {
                head =deletion_end(head);
                print(head);
                break;
            }
            case 6:
            {
                int value;
                cout<<"Enter the value to be delete:";
                cin>>value;
                head =deletion_end(head);
                print(head);
                break;
            }
            case 7:
            {
                int value;
                cout<<"Enter the node to be search:";
                cin>>value;
                cout<<search(head,value);
                break;
            }
            case 8:
            {
                cout<<"All node value:";
                print(head);
                break;
            }
        }
        cout<<endl<<"Enter y(YES) or n(NO) to continue:";
        cin>>c;
    }

    return 0;
}