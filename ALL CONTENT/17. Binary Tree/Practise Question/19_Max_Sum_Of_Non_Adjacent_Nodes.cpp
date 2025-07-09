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

pair<int,int> solve(node* root){

    // base case
    if(root==NULL){
        pair<int,int> p = make_pair(0,0);
        return p;
    }

    pair<int,int> left = solve(root->left);
    pair<int,int> right = solve(root->right);

    pair<int,int> res;

    // for including root
    res.first = root->data + left.second + right.second;

    // for not including root
    res.second = max(left.first,left.second) + max(right.first,right.second);

    return res;

}
int getMaxSum(node* root){

    pair<int,int> ans = solve(root);

    return max(ans.first,ans.second);

}


int main() {

    node* root = NULL;

    root = buildTree(root);

    int ans = getMaxSum(root);

    cout<<"Max Sum : "<<ans<<endl;

    return 0;
}