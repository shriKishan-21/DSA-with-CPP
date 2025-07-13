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

void inOrder(node* root){
    // base case
    if(root == NULL){
        return ;
    }

    // LNR ->
    // L -- Left
    inOrder(root->left);
    // N -- Node
    cout<<root->data<<" ";
    // R -- Right
    inOrder(root->right);

}

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


// -----------------------------------------------------------

node* minVal(node* root){

    node* temp = root;

    // move till we reach left most node
    while(temp->left != NULL){

        temp = temp->left;
    }

    // the left most node will be the min node
    return temp;
}

node* deleteFromBST(node* root , int val){

    // base case
    if(root == NULL){
        return NULL;
    }

    if(root->data == val){
        // 0 child
        if(root->left == NULL && root->right == NULL){
            delete root;
            return NULL;
        }
        // 1 child
        if(root->left != NULL && root->right == NULL){
            node* temp = root->left;
            delete root;
            return temp;
        }
        if(root->left == NULL && root->right != NULL){
            node* temp = root->right;
            delete root;
            return temp;
        }
        // 2 child
        if(root->left != NULL && root->right != NULL){
            int mini = minVal(root->right)->data;
            root->data = mini;
            root->right = deleteFromBST(root->right,mini);
            return root;
        }
    }
    else if(root->data > val){
        root->left = deleteFromBST(root->left,val);
        return root;
    }
    else{
        root->right = deleteFromBST(root->right,val);
        return root;
    }
}    
int main()
{
    node* root = NULL;

    cout<<"Enter data to create BST : "<<endl;
    takeInput(root);

    // 10 8 21 7 27 5 4 3 -1

    int val;
    cin>>val;

    root = deleteFromBST(root,val);

    inOrder(root);

    return 0;
}