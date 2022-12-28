#include <iostream>
using namespace std;
class TreeNode
{
public:
    int data;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }
    ~TreeNode()
    {
        delete left;
        delete right;
    }
};
int find(int *in, int inS, int inE, int ele)
{
    for (int i = inS; i <= inE; i++)
    {
        if (in[i] == ele)
        {
            return i;
        }
    }
    return -1;
}
TreeNode *solve(int *pre, int *ino, int inS, int inE, int preS, int preE)
{
    if (inS > inE)
    {
        return NULL;
    }
    int rootData = pre[preS];
    int pos = find(ino, inS, inE, rootData);
    int linS = inS;
    int linE = pos - 1;
    int lpreS = preS + 1;
    int lpreE = linE - linS + lpreS;
    int rinS = pos + 1;
    int rinE = inE;
    int rpreS = lpreE + 1;
    int rpreE = preE;
    TreeNode *root = new TreeNode(rootData);
    root->left = solve(pre, ino, linS, linE, lpreS, lpreE);
    root->right = solve(pre, ino, rinS, rinE, rpreS, rpreE);
    return root;
}
TreeNode*buildTree(int *pre, int preLength, int *ino, int inLength)
{
    TreeNode*ans = solve(pre, ino, 0, inLength - 1, 0, preLength - 1);
    return ans;
}
void print(TreeNode *root)
    {
        if (root == NULL)
        {
            return;
        }
        cout << root->data << " -> ";
        if (root->left != NULL)
        {
            cout << "L:" << root->left->data << ",";
        }
        if (root->right != NULL)
        {
            cout << "R:" << root->right->data << ",";
        }
        cout << endl;
        print(root->left);
        print(root->right);
    }
int main()
{
    int n;
    cin>>n;
    int inorder[n],preorder[n];
    cout<<"Inorder:";
    for(int i=0;i<n;i++)
    {
        cin>>inorder[i];
    }
    cout<<"PreOrder:";
    for(int i=0;i<n;i++)
    {
        cin>>preorder[i];
    }
    TreeNode*root =  buildTree(preorder,n,inorder,n);
    print(root);

    return 0;
}