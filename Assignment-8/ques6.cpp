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
TreeNode *buildTree(int *post, int *in, int inS, int inE, int poS, int poE)
{
    if (poS > poE)
    {
        return NULL;
    }
    int rootData = post[poE];
    int index = -1;
    for (int i = inS; i <= inE; i++)
    {
        if (in[i] == rootData)
        {
            index = i;
            break;
        }
    }
    int linS = inS;
    int linE = index - 1;
    int lpoS = poS;
    int lpoE = linE - linS + lpoS;
    int rinS = index + 1;
    int rinE = inE;
    int rpoS = lpoE + 1;
    int rpoE = poE - 1;
    TreeNode *root = new TreeNode(rootData);
    root->left = buildTree(post, in, linS, linE, lpoS, lpoE);
    root->right = buildTree(post, in, rinS, rinE, rpoS, rpoE);
    return root;
}
TreeNode*buildTree(int *post, int postlength, int *ino, int inlength)
{
    TreeNode*ans = buildTree(post, ino, 0, inlength-1, 0, postlength-1);
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
    cout<<"Enter the size of the array:";
    cin>>n;
    int inorder[n],postorder[n];
    cout<<"Inorder:";
    for(int i=0;i<n;i++)
    {
        cin>>inorder[i];
    }
    cout<<"PreOrder:";
    for(int i=0;i<n;i++)
    {
        cin>>postorder[i];
    }
    TreeNode*root =  buildTree(postorder,n,inorder,n);
    print(root);

    return 0;
}