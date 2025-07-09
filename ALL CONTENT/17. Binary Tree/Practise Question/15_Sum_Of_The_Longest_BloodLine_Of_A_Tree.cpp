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

void solve(node* root , int sum , int maxSum , int len , int maxLen){
    // base case
    // meaning there can be a leaf node or a node with no left or right child
    if(root==NULL){
        // if len has increased -- new node added
        if(len>maxLen){
            maxLen = len;
            maxSum = sum;
        }
        // else if length is same -- update the max sum
        else if(len==maxSum){
            maxSum = max(sum,maxSum);
        }
    }

    // adding sum 
    sum = sum + root->data;

    solve(root->left,sum,maxSum,len+1,maxLen);
    solve(root->right,sum,maxSum,len+1,maxLen);

}

int sumOfLongRootToLeafPath(node* root){
    int len = 0;
    int maxLen = 0;

    int sum = 0;
    int maxSum = INT64_MAX;

    solve(root,sum,maxSum,len,maxLen);

    return maxSum;

}

int main(){

    node* root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);
    root->right->right = new node(5);

    cout << sumOfLongRootToLeafPath(root) << endl;

    return 0;
}
