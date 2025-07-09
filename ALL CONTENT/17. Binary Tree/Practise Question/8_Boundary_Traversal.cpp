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

// function to traverse left side
void traverseLeft(node* root , vector<int> &ans){
    // base case -- if root is null and if root is a leaf node
    if((root==NULL) || (root->left==NULL && root->right==NULL)){
        return;
    }

    // push root in ans
    ans.push_back(root->data);

    // check for right or left node
    if(root->left){
        traverseLeft(root->left,ans);
    }
    else{
        traverseLeft(root->right,ans);
    }
}

// function to traverse and print all leaf node from left to right
void traverseLeaf(node* root , vector<int> &ans){
    // base case
    if(root==NULL){
        return ;
    }

    // if leaf node is reach -- store it in ans
    if(root->left==NULL && root->left==NULL){
        ans.push_back(root->data);
        return ;
    }

    // if not nodve to left side to search then right
    traverseLeaf(root->left,ans);
    traverseLeaf(root->right,ans);

}

// function to traverse right side
void traverseRight(node* root , vector<int> &ans){
    // base case -- if root is null and if root is a leaf node
    if((root==NULL) || (root->left==NULL && root->right==NULL)){
        return;
    }

    if(root->right){
        traverseRight(root->right,ans);
    }
    else{
        traverseRight(root->left,ans);
    }

    // while returning
    ans.push_back(root->data);
    
}

vector<int> boundary(node* root){
    // array to store ans
    vector<int> ans;

    if(root==NULL){
        return ans;
    }

    // push root in ans
    ans.push_back(root->data);

    // 1. print left side
    traverseLeft(root->left,ans);

    // 2. print all leaf node
    // (a) print first left side leaf node
    traverseLeaf(root->left,ans);
    // (b) print right side leaf node
    traverseLeaf(root->right,ans);

    // 3. print left side in reverse order
    traverseRight(root->right,ans);

    return ans;

}

int main(){

    node* root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);
    root->left->right = new node(5);
    root->right->left = new node(6);
    root->right->right = new node(7);

    vector<int> ans = boundary(root);

    for(auto i : ans){
        cout << i << " ";
    }

    return 0;
}
