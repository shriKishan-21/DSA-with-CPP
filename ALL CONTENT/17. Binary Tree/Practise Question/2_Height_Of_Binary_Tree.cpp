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

int height(node* node){
    // base case
    if(node==NULL){
        return 0;
    }

    int left = height(node->left);
    int right=height(node->right);

    int ans = max(left,right) + 1;

    return ans;
}

int main() {
    node* root = NULL;
    // Build the binary tree
    root = buildTree(root);
    
    // Calculate the height of the binary tree
    int treeHeight = height(root);
    cout << "Height of the binary tree: " << treeHeight << endl;

    return 0;
}

