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
class BST
{
    TreeNode *root;

public:
    BST()
    {
        root = NULL;
    }
    ~BST()
    {
        delete root;
    }

private:
    bool search(TreeNode *root, int data)
    {
        if (root == NULL)
        {
            return false;
        }
        if (root->data == data)
        {
            return true;
        }
        if (data < root->data)
        {
            return search(root->left, data);
        }
        else
        {
            return search(root->right, data);
        }
    }

public:
    bool search(int data)
    {
        return search(root, data);
    }

private:
    TreeNode *insertion(TreeNode *root, int data)
    {
        if (search(data))
        {
            return root; // If found in the Tree then return
        }
        if (root == NULL)
        {
            TreeNode *newNode = new TreeNode(data);
            return newNode;
        }
        if (data < root->data)
        {
            root->left = insertion(root->left, data);
        }
        else
        {
            root->right = insertion(root->right, data);
        }
        return root;
    }

public:
    void insert(int data)
    {
        this->root = insertion(root, data);
    }

private:
    TreeNode *deletion(TreeNode *root, int data)
    {
        if (root == NULL)
        {
            return NULL;
        }
        if (data < root->data)
        {
            root->left = deletion(root->left, data);
        }
        else if (root->data < data)
        {
            root->right = deletion(root->right, data);
        }
        else
        {
            if (root->right == NULL && root->left == NULL)
            {
                delete root;
                return NULL;
            }
            else if (root->right == NULL)
            {
                TreeNode *temp = root->left;
                root->left = NULL;
                delete root;
                return temp;
            }
            else if (root->left == NULL)
            {
                TreeNode *temp = root->right;
                root->right = NULL;
                delete root;
                return temp;
            }
            else
            {
                TreeNode *minNode = root->right;
                while (minNode->left != NULL)
                {
                    minNode = minNode->left;
                }
                int rightMin = minNode->data;
                root->data = rightMin;
                root->right = deletion(root->right, rightMin);
            }
        }
        return root;
    }

public:
    void remove(int data)
    {
        this->root = deletion(root, data);
    }

private:
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

public:
    void printTree()
    {
        print(root);
    }

private:
    void InOrder(TreeNode *root)
    {
        if (root == NULL)
        {
            return;
        }
        InOrder(root->left);
        cout << root->data << " ";
        InOrder(root->right);
    }
    void PreOrder(TreeNode *root)
    {
        if (root == NULL)
        {
            return;
        }
        cout << root->data << " ";
        PreOrder(root->left);
        PreOrder(root->right);
    }
    void PostOrder(TreeNode *root)
    {
        if (root == NULL)
        {
            return;
        }
        PostOrder(root->left);
        PostOrder(root->right);
        cout << root->data << " ";
    }

public:
    void InOrder()
    {
        InOrder(root);
    }
    void PreOrder()
    {
        PreOrder(root);
    }
    void PostOrder()
    {
        PostOrder(root);
    }
    private:
    int MaxDepth(TreeNode *root)
    {
        int count=0;
        if(root==NULL)
        {
            count=0;
            return count;
        }
        int lh = MaxDepth(root->left);
        int rh = MaxDepth(root->right);
        return max(lh,rh)+1;
    }
    int MinDepth(TreeNode *root)
    {
        int count=0;
        if(root==NULL)
        {
            count=0;
            return count;
        }
        int lh = MinDepth(root->left);
        int rh = MinDepth(root->right);
        return min(lh,rh)+1;
    }
    public:
    int MaxDepth()
    {
        return MaxDepth(root);
    }
    int MinDepth()
    {
        return MinDepth(root);
    }
};

int main()
{
    BST *tree = new BST();
    tree->insert(10);
    tree->insert(4);
    tree->insert(1);
    tree->insert(2);
    tree->insert(3);
    tree->insert(20);
    tree->insert(15);
    tree->insert(14);
    tree->printTree();
    tree->InOrder();
    cout<<tree->MinDepth();

    return 0;
}