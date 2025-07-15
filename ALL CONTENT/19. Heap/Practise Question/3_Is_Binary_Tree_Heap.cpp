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

// Function to count nodes
int countNodes(node* root){

    // base count
    if(root == NULL){
        return 0;
    }

    int ans = 1 + countNodes(root->left) + countNodes(root->right);

    return ans;

}

// Function to check whether is is a complete binary tree
bool isCBT(node* root, int index, int totalNodes){

    // base case
    if(root == NULL){
        return true;
    }

    if(index >= totalNodes){
        return false;
    }

    bool left = isCBT(root->left, 2*index + 1, totalNodes);
    bool right = isCBT(root->right, 2*index + 2, totalNodes);

    return left && right;
}

// Function to check whether is is a max heap
bool isMaxOrder(node* root){

    // Leaf Node
    if(root->left == NULL && root->right == NULL){
        return true;
    }

    // Only left child exists
    if(root->right == NULL){
        return (root->data > root->left->data);
    }
    // if both child exists
    else{
        bool left = isMaxOrder(root->left);
        bool right = isMaxOrder(root->right);
    }

    return (left && right && root->data > root->left->data && root->data > root->right->data);
}

bool isHeap(node* root){
    int index = 0;
    int totalNodes = countNodes(root);

    if(isCBT(root, index, totalNodes) && isMaxOrder(root)){
        return true;
    }
    else{
        return false;
    }
}

int main()
{
    node* root = new node(10);
    root->left = new node(20);
    root->right = new node(30);
    root->left->left = new node(40);
    root->left->right = new node(50);
    root->right->left = new node(60);
    root->right->right = new node(70);

    if(isHeap(root)){
        cout<<"True"<<endl;
    }
    else{
        cout<<"False"<<endl;
    }
    
    return 0;

}
