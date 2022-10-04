#include <iostream>
using namespace std;
#include "linkedlist.cpp"
int length(Node *head)
{
    if(head==NULL)
    {
        return 0;
    }
    return 1+length(head->next);
}
int main()
{
    Node *head = input();
    int a=length(head);
    cout<<a<<endl;
    return 0;
}