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


int solve(node* root , int &i , int k){
    // base case
    if(root==NULL){
        return -1;
    }

    // L
    int left = solve(root->left,i,k);

    if(left!=-1){
        return left;
    }

    // N
    i++;
    if(i==k){
        return root->data;
    }

    // R
    return solve(root->right,i,k);

}

int getSize(node* root){
    // base case
    if(root==NULL){
        return 0;
    }

    return 1 + getSize(root->left) + getSize(root->right);
}
int kthLargest(node* root,int k){
    int size = getSize(root);
    k =size-k;
    int i =0;
    int ans = solve(root,i,k);
    return ans;
}

int main(){
    node* root = NULL;

    cout<<"Enter data to create BST : "<<endl;
    takeInput(root);

    cout<<kthLargest(root,2);

    return 0;
}