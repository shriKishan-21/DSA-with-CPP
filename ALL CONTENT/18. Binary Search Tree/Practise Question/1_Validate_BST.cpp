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

// --------------------------------------------------------------------------------------

// Approach 1
bool inOrder(node* root , int &prev){
    // base case
    if(!root){
        return true;
    }

    // L
    if(!inOrder(root->left,prev)){
        return false;
    }

    // N
    if(prev >= root->data){
        return false;
    }
    // update prev value to current
    prev = root->data;

    // R
    return inOrder(root->right,prev);

}

bool validBST(node* root){
    int prev = INT_MIN;
    return inOrder(root,prev);
}


// Approach 2

bool isBST(node* root, int min , int max){
    // base case
    if(root==NULL){
        return true;
    }

    if(root->data>=min && root->data<=max){
        bool left = isBST(root->left,min,root->data);
        bool right = isBST(root->right,root->data,max);

        return right && left;
    }
    else{
        return false;
    }
}


bool validBST2(node* root){
    return isBST(root,INT_MIN,INT_MAX);
}




int main()
{
    node* root = NULL;

    cout<<"Enter data to create BST : "<<endl;
    takeInput(root);

    // 10 6 12 2 8 11 1 -1

    cout<<validBST(root)<<endl;

    cout<<validBST2(root)<<endl;

    return 0;
}