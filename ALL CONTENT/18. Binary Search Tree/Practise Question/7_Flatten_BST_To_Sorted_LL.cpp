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


node* flatten(node* root){
    // arr to store inorder traversal
    vector<int> inorderVal;
    inorder(root,inorderVal);

    int n = inorderVal.size()-1;

    // create first node of inorder as head
    node* newNode = new node(inorderVal[0]);

    // create a curr node pointing the current node created
    node* curr = newNode;

    // move from 2nd node till the last second node
    for(int i =1 ; i<n ; i++){
        node* temp = new node(inorderVal[i]);

        // adjust its links
        curr->left = NULL;
        curr-> right = temp;
        curr = temp; 
    }

    // adjust the last element
    curr->left = NULL;
    curr->right = NULL;

    return newNode;

}

int main(){
    node* root = NULL;

    cout<<"Enter data to create BST : "<<endl;
    takeInput(root);

    // 10 6 12 2 8 11 15 -1

    node* head = flatten(root);

    node* temp = head;
    while(temp != NULL){
        cout<<temp->data<<" ";
        temp = temp->right;
    }

    return 0;
}