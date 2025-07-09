#include<iostream>
#include<stack>
#include<queue>
#include<vector>
#include<algorithm>
#include<map>
#include<limits.h>
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

node* solve(node* root, int &k , int target){

    // base case
    if(root==NULL){
        return NULL;
    }

    if(root->data==target)
        return root;

    node* leftAns = solve(root->left,k,target);
    node* rightAns = solve(root->right,k,target);

    if(leftAns != NULL && rightAns == NULL){
        k--;
        if(k<=0){
            // k = intmax so that we can further update it 
            k = INT_MAX;
            return root;
        }
        else{
            return leftAns;
        }
    }

    if(leftAns == NULL && rightAns != NULL){
        k--;
        if(k<=0){
            // k = intmax so that we can further update it 
            k = INT_MAX;
            return root;
        }
        else{
            return rightAns;
        }
    }

    return NULL;
    
}
int kthAncestor(node* root,int k,int target){

    node* ans = solve(root,k,target);

    if(ans ==NULL || ans->data == target){
        return -1;
    }
    else{
        return ans->data;
    }

}


int main() {
    node* root = NULL;

    // Build the binary tree
    root = buildTree(root);

    int k, target;
    cout << "Enter value of k (which ancestor): ";
    cin >> k;

    cout << "Enter target node value: ";
    cin >> target;

    int ancestor = kthAncestor(root, k, target);

    if(ancestor == -1) {
        cout << k << "-th ancestor of node " << target << " does not exist." << endl;
    } else {
        cout << k << "-th ancestor of node " << target << " is: " << ancestor << endl;
    }

    return 0;
}