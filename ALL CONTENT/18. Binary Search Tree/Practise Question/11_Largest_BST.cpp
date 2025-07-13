#include <iostream>
#include <algorithm>
#include<stack>
#include <queue>
#include<algorithm>
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

// Class to store 4 info
class info{
    public:
    int maxi;
    int mini;
    bool isBST;
    int size;
};

info solve(node* root , int &ans){
    // base case
    if(root==NULL){
        return {INT_MIN,INT_MAX,true,0};
    }

    // left and right calls
    info left = solve(root->left,ans);
    info right = solve(root->right,ans);

    // store current node
    info currNode;

    // update the 4 information
    currNode.size = left.size + right.size + 1;
    currNode.maxi = max(root->data,right.maxi);
    currNode.mini = min(root->data,left.mini);

    if(left.isBST && right.isBST && left.maxi < root->data && right.mini <root->data){
        currNode.isBST = true;
    }
    else{
        currNode.isBST = false;
    }

    // answer update
    if(currNode.isBST){
        ans = max(ans,currNode.size);
    }

    return currNode;
}

int largestBST(node* root){
    int maxSize = 0;
    info temp = solve(root,maxSize);
    return maxSize;
}


// -----------------------------------------------------------------------------
void inorder(node* root){
    // base case
    if(root==NULL){
        return;
    }

    // LNR
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}


int main(){
    node* root = NULL;

    cout<<"Enter data to create BST : "<<endl;
    takeInput(root);

    // 1 2 4 7 3 5 6 -1

    cout<<largestBST(root)<<endl;


    return 0;
}