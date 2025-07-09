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


void solve(node* root , vector<int> &ans , int level){
    // base case
    if(root==NULL){
        return ;
    }

    // condition to tell -- we entered a new level
    if(level == ans.size()){
        ans.push_back(root->data);
    }

    // in left view call is from left to right
    solve(root->left,ans,level+1);
    solve(root->right,ans,level+1);

}
vector<int> leftView(node* root){
    vector<int> ans;
    solve(root,ans,0);
    return ans;
}

int main(){

    node* root = NULL;

    root = buildTree(root);

    vector<int> view = leftView(root);

    for(auto i : view){
        cout<<i<<" ";
    }

    return 0;
}