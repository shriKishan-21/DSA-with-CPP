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

// function for inorder traveersal
void inorder(node* root , vector<int> &in){
    // base case
    if(root==NULL){
        return;
    }

    // LNR
    inorder(root->left,in);
    in.push_back(root->data);
    inorder(root->right,in);

}


node* inorderToBST(int start , int end , vector<int> &inorderVal){

    // base case
    if(start>end){
        return NULL;
    }

    int mid = (start+end)/2;

    node* root = new node(inorderVal[mid]); 

    root->left = inorderToBST(start,mid-1,inorderVal);
    root->right = inorderToBST(mid+1,end,inorderVal);

    return root;
}

node* balancedBST(node* root){
    // arr to store inorder traversal
    vector<int> inorderVal;
    inorder(root,inorderVal);

    return inorderToBST(0,inorderVal.size()-1,inorderVal);


}

// to print BST
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

    // 10 6 12 2 8 11 15 -1

    node* ans = balancedBST(root);

    // print ans
    cout<<"Balanced BST : "<<endl;
    inorder(ans);


    return 0;
}