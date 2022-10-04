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
            tail->next=head;
        }
        else
        {
            tail->next= newnode;
            tail = tail->next;
        }
        tail->next=head;
        cin>>data;
    }
    
    
    return head;
}
void print(Node *head)
{
    Node *temp=head;
    do
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    while(temp!=head);
    cout<<endl;
}