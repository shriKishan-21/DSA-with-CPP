#include<iostream>
#include<stack>
#include<queue>
#include<vector>
#include<algorithm>
#include<map>
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

node* LCA(node* root , int n1 , int n2){
    // base case
    if(root==NULL){
        return NULL;
    }

    if(root->data == n1 || root->data == n2 ){
        return root;
    }

    node* leftAns = LCA(root->left,n1,n2);
    node* rightAns = LCA(root->right,n1,n2);

    if(leftAns != NULL && rightAns != NULL){
        return root;
    }
    else if(leftAns != NULL && rightAns == NULL){
        return leftAns;
    }
    else if(leftAns == NULL && rightAns != NULL){
        return rightAns;
    }
    else{
        return NULL;
    }

}


int main() {
    node* root = NULL;
    root = buildTree(root);

    int n1, n2;
    cout << "Enter the first node value: ";
    cin >> n1;
    cout << "Enter the second node value: ";
    cin >> n2;

    node* lca = LCA(root, n1, n2);
    if (lca != NULL) {
        cout << "Lowest Common Ancestor of " << n1 << " and " << n2 << " is: " << lca->data << endl;
    } else {
        cout << "Lowest Common Ancestor not found." << endl;
    }

    return 0;
}

