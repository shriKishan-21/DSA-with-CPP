#include<iostream>
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


// Approach 1
int height(node* node){
    // base case
    if(node==NULL){
        return 0;
    }

    int left = height(node->left);
    int right=height(node->right);

    int ans = max(left,right) + 1;

    return ans;
}

int diameter1(node* root){

    if(root==NULL){
        return 0;
    }

    int op1 = diameter1(root->left);
    int op2 = diameter1(root->right);
    int op3 = height(root->left) + height(root->left) + 1;

    int ans = max(op1,max(op2,op3));

    return ans;
}

/*
TIme complexity = O(N^2)
Space Complexity = O(N)
*/

// Optimized approach
pair<int,int> diameterFast(node* root){
    // base case
    if(root==NULL){
        pair<int,int> p = make_pair(0,0);
        return p;
    }

    pair<int,int> left = diameterFast(root->left);
    pair<int,int> right = diameterFast(root->right);

    int op1 = left.first;
    int op2 = right.first;
    int op3 = left.second + right.second + 1;

    pair<int,int> ans;
    ans.first = max(op1,max(op2,op3));
    ans.second = max(left.second,right.second);

    return ans;
}

int diameter2(node* node){
    return diameterFast(node).first;
}


int main(){

    node* root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);
    root->left->right = new node(5);
    root->right->left = new node(6);
    root->right->right = new node(7);

    cout<<diameter1(root)<<endl;
    cout<<diameter2(root)<<endl;

    return 0;
}
