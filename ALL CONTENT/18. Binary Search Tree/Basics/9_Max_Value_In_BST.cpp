#include<iostream>
#include<algorithm>
#include<queue>
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

node* insertIntoBST(node* &root , int d){
    // base case
    if(root == NULL){
        root = new node(d);
        return root;
    }

    if(root->data < d){
        // insertion in right
        root->right = insertIntoBST(root->right,d);
    }
    else{
        // insertion in left
        root->left = insertIntoBST(root->left,d);
    }
    return root;

}
void takeInput(node* &root){
    int data;
    cin>>data;

    while(data != -1){
        insertIntoBST(root,data);
        cin>>data;
    }
}

// --------------------------------------------------------------------------------------

// In BST the max node is the right most node

node* maxNode(node* root){

    node* temp = root;

    // move till we reach right most node
    while(temp->right != NULL){

        temp = temp->right;
    }

    // the right most node will be the max node
    return temp;
}

int main()
{
    node* root = NULL;

    cout<<"Enter data to create BST : "<<endl;
    takeInput(root);
    // 10 8 21 7 27 5 4 3 -1

    node* maxi = maxNode(root);
    cout<<"Min Node is : "<<maxi->data<<endl;

    return 0;
}

