#include <iostream>
#include <algorithm>
#include <queue>
#include <climits>
using namespace std;

class node
{

public:
    int data;
    node *left;
    node *right;

    node(int d)
    {
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};

node *insertIntoBST(node *&root, int d)
{
    // base case
    if (root == NULL)
    {
        root = new node(d);
        return root;
    }

    if (root->data < d)
    {
        // insertion in right
        root->right = insertIntoBST(root->right, d);
    }
    else
    {
        // insertion in left
        root->left = insertIntoBST(root->left, d);
    }
    return root;
}
void takeInput(node *&root)
{
    int data;
    cin >> data;

    while (data != -1)
    {
        insertIntoBST(root, data);
        cin >> data;
    }
}

// -----------------------------------------------------------------------------

// Approach 1 -- Recursive
node *LCAinBST(node *root, node *p, node *q)
{
    // base case
    if (root == NULL)
    {
        return NULL;
    }

    // 1
    if (root->data < p->data && root->data < q->data)
    {
        return LCAinBST(root->right, p, q);
    }

    // 2
    if (root->data < p->data && root->data < q->data)
    {
        return LCAinBST(root->left, p, q);
    }

    // 3
    return root;
}

/*
TIME COMPLEXITY : O(N)
SPACE COMPLEXIty : O(N)
*/

// Approach 2 -- Iterative
node *LCAinBST2(node *root, node *p, node *q)
{

    while (root != NULL)
    {
        // 1
        if (root->data < p->data && root->data < q->data)
        {
            root = root->right;
        }
        
        // 2
        else if (root->data < p->data && root->data < q->data)
        {
            root = root->left;
        }
        // 3
        else{

            return root;
        }
    }
}

/*
TIME COMPLEXITY : O(N)
SPACE COMPLEXIty : O(1)
*/

int main(){
    node* root = NULL;

    cout<<"Enter data to create BST : "<<endl;
    takeInput(root);

    node* p = new node(5);
    node* q = new node(10);
    
    cout<<LCAinBST(root,p,q)<<endl;
    cout<<LCAinBST2(root,p,q)<<endl;

    return 0;
}