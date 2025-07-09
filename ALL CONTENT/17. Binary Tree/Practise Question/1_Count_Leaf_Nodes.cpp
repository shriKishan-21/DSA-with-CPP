#include<iostream>
using namespace std;


class node{

    public:

    int data;
    node* left;
    node* right;

    // constructor
    node(int d){
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }

};

node* buildTree(node* root){
    // creating root node
    cout<<"Enter the data : "<<endl;
    int data;
    cin>>data;
    root = new node(data);

    // check whether data == -1 -- null 
    if(data==-1){
        return NULL;
    }

    // insertion in left
    cout<<"Enter data for insertion in left : "<<endl;
    root->left = buildTree(root->left);

    // insertion in right
    cout<<"Enter data for insertion in right : "<<endl;
    root->right = buildTree(root->right);


    // Here it will take left child till null is given and same for right child
}

// ----------------------------------------------------------------------------------------

void inOrder(node* root , int &count){
    // base case
    if(root == NULL){
        return ;
    }

    // LNR ->
    // L -- Left
    inOrder(root->left,count);
    // 
    if(root->left == NULL && root->right == NULL){
        count++;
    }
    // R -- Right
    inOrder(root->right,count);

}

int noOfLeafNode(node* root){
    int count = 0;
    inOrder(root,count);
    return count;
}

int main(){

    node* root = NULL;
    root = buildTree(root);

    cout<<"No. of leaf nodes : "<<noOfLeafNode(root)<<endl;

    return 0;
}