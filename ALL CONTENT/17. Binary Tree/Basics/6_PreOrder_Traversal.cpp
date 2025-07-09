#include<iostream>
#include<queue>
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


void preOrder(node* root){
    // base case
    if(root == NULL){
        return ;
    }

    // NLR ->
    // N -- Node
    cout<<root->data<<" ";
    // L -- Left
    preOrder(root->left);
    // R -- Right
    preOrder(root->right);

}

int main()
{
    node* n1;

    buildTree(n1);

    return 0;
}