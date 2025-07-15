#include<iostream>
#include<stack>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;

class node{

    public:

    int data;
    node* left;
    node* right;

    node(int d){
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};

void inorder(node* root , vector<int> &in){
    // base case
    if(root==NULL){
        return;
    }

    // LNR
    inorder(root->left , in);
    in.push_back(root->data);
    inorder(root->right , in);
}

node* fillPreorder(node* root , vector<int> &in , int &i){
    // base case
    if(root==NULL){
        return NULL;
    }

    // NLR
    root->data = in[i++];
    root->left = fillPreorder(root->left , in , i);
    root->right = fillPreorder(root->right , in , i);

    return root;
}

node* buildTree(node* root){
    // steep 1 : convert BST to inorder traversal
    vector<int> in;
    inorder(root,in);

    // step 2 : fill BST according to preorder
    int index = 0;
    fillPreorder(root,in,index);

    return root;
}

void print(node* root){
    if(root==NULL){
        return;
    }

    print(root->left);
    cout<<root->data<<" ";
    print(root->right);
}

int main()
{
    node* root = new node(4);
    root->left = new node(2);
    root->right = new node(6);
    root->left->left = new node(1);
    root->left->right = new node(3);
    root->right->left = new node(5);
    root->right->right = new node(7);
    root = buildTree(root);

    print(root);

    return 0;

}
