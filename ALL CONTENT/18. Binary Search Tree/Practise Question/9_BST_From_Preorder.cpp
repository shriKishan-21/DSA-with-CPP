#include <iostream>
#include <algorithm>
#include<stack>
#include <queue>
#include<algorithm>
#include <climits>
using namespace std;

class node
{

public:
    int data;
    node *left;
    node *right;

    node(int d)
    {
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};

// -----------------------------------------------------------------------------

node* solve(vector<int> &preOrder , int mini , int maxi , int &i){
    if(i>=preOrder.size()){
        return NULL;
    }

    if(preOrder[i]<mini || preOrder[i]>maxi){
        return NULL;
    }

    node* root = new node(preOrder[i++]);

    root->left = solve(preOrder,mini,root->data,i);
    root->right = solve(preOrder,root->data,maxi,i);

    return root;
}

node* preOrderToBST(vector<int> & preOrder){
    int mini = INT_MIN;
    int maxi = INT_MAX;
    int i = 0;

    return solve(preOrder,mini,maxi,i);

}


// -----------------------------------------------------------------------------
void inorder(node* root){
    // base case
    if(root==NULL){
        return;
    }

    // LNR
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}


int main(){

    vector<int> preorder = {20,10,5,15,13,35,30,42};

    node* ans = preOrderToBST(preorder);

    inorder(ans);


    return 0;
}