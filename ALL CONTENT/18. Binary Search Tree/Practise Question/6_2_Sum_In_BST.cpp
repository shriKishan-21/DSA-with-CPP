#include <iostream>
#include <algorithm>
#include <queue>
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

node *insertIntoBST(node *&root, int d)
{
    // base case
    if (root == NULL)
    {
        root = new node(d);
        return root;
    }

    if (root->data < d)
    {
        // insertion in right
        root->right = insertIntoBST(root->right, d);
    }
    else
    {
        // insertion in left
        root->left = insertIntoBST(root->left, d);
    }
    return root;
}
void takeInput(node *&root)
{
    int data;
    cin >> data;

    while (data != -1)
    {
        insertIntoBST(root, data);
        cin >> data;
    }
}

// -----------------------------------------------------------------------------

// function for inorder traveersal
void inorder(node* root , vector<int> &in){
    // base case
    if(root==NULL){
        return;
    }

    // LNR
    inorder(root->left,in);
    in.push_back(root->data);
    inorder(root->right,in);

}


bool twoSumInBST(node* root , int target){
    // arr to store inorder traversal
    vector<int> inorderVal;
    inorder(root,inorderVal);

    // initialize two pointers
    int i = 0 , j = inorderVal.size()-1;
    // use 2 pointer to find sum
    while(i<j){
        int sum = inorderVal[i] + inorderVal[j];
        
        // if target found
        if(sum==target){
            return true;
        }
        // if target is largert than size -- reduce larger value
        else if(sum>target){
            j--;
        }
        // if target is smaller than size -- increase smaller value
        else{
            i++;
        }
    }
    return false;
}

int main(){
    node* root = NULL;

    cout<<"Enter data to create BST : "<<endl;
    takeInput(root);

    // 10 6 12 2 8 11 15 -1
    cout<<twoSumInBST(root,20)<<endl;

    return 0;
}