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

//Approach 1 -- Recursion
bool searchInBST(node* root, int key){

    // base case
    if(root == NULL){
        return false;
    }

    if(root->data == key){
        return true;
    }

    if(root->data < key){
        return searchInBST(root->right,key);
    }
    else{
        return searchInBST(root->left,key);
    }
}

/*
TIME COMPLEXITY : O(n)
SPACE COMPLEXITY : O(N)
*/

// Approach 2 -- Iteration

bool searchInBST(node* root, int key){

    node* temp = root;

    while(temp != NULL){
        if(root->data == key){
            return true;
        }
        else if(root->data > key){
            temp = temp->left;
        }
        else{
            temp = temp->right;
        }
    }
    return false;
}

int main()
{
    node* root = NULL;

    cout<<"Enter data to create BST : "<<endl;
    takeInput(root);
    // 10 8 21 7 27 5 4 3 -1

    int key;
    cin>>key;

    cout<<searchInBST(root,key)<<endl;

    return 0;
}