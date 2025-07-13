#include<iostream>
#include<algorithm>
#include<queue>
#include<climits>
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

// -----------------------------------------------------------------------------

pair<int,int> predecessorSuccessor(node* root, int key){

    // find key
    node* temp = root;
    int pred = -1;
    int suc = -1;

    while(temp->data != key){
        if(temp->data > key){
            suc = temp->data;
            temp=temp->left;
        }
        else{
            pred = temp->data;
            temp = temp->right;
        }
    }

    // pred and suc

    // 1.pred
    node* leftTree = temp->left;
    while(leftTree != NULL){
        pred = leftTree->data;
        leftTree = leftTree->right;
    }

    // 2. succ
    node* rightTree = temp->right;
    while(rightTree!=NULL){
        suc = rightTree->data;
        rightTree=rightTree->left;
    }

    return {pred,suc};
}

int main(){
    node* root = NULL;

    cout<<"Enter data to create BST : "<<endl;
    takeInput(root);

    pair<int,int> ans = predecessorSuccessor(root,2);
    cout<<"Predecessor :"<< ans.first <<" "<<"Successor : "<<ans.second<<endl;

    return 0;
}