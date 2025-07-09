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

bool isBalance1(node* root){

    // base case
    if(root==NULL){
        return true;
    }

    bool left = isBalance1(root->left);
    bool right = isBalance1(root->right);

    bool diff = abs(height(root->left) - height(root->right)) <=1;

    if(left && right && diff){
        return true;
    }
    else{
        return false;
    }
}

/*
TIME COMPLEXITY : O(N^2)
*/

// optimized Approach 2
pair<bool,int> isBalance2(node* root){
    // base case
    if(root==NULL){
        pair<bool,int> p = make_pair(true,0);
        return p;
    }

    // traverse left side
    pair<bool,int> left = isBalance2(root->left);
    // traverse right side
    pair<bool,int> right = isBalance2(root->right);

    // store the left ans
    bool leftAns = left.first;
    // store the right ans
    bool rightAns = right.first;

    // differnce
    bool difference = abs(left.second - right.second) <=1;

    // to store ans
    pair<bool,int> ans;

    // update the max height
    ans.second = max(left.second,right.second) + 1;

    // check whether all conditiion are true or not
    if(leftAns && rightAns && difference){
        ans.first = true;
    }
    else{
        ans.first = false;
    }

    return ans;
}

int main(){

    node* root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);
    root->left->right = new node(5);
    root->right->right = new node(6);
    root->right->left = new node(7);
    root->right->left->left = new node(8);
    root->right->right->right = new node(9);

    pair<bool,int> ans = isBalance2(root);

    if(ans.first){
        cout<<"Balance"<<endl;
    }
    else{
        cout<<"Not Balance"<<endl;
    }

    return 0;
}
