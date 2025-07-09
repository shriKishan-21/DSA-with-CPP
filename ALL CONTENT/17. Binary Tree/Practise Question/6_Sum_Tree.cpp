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

pair<bool,int> isSumTreeFast(node* root){
    // base case
    if(root==NULL){
        pair<bool,int> p = make_pair(true,0);
        return p;
    }

    // check leaaf node
    if(root->left == NULL && root->right == NULL){
        pair<bool,int> p = make_pair(true,root->data);
        return p;
    }

    pair<bool,int> leftAns = isSumTreeFast(root->left);
    pair<bool,int> rightAns = isSumTreeFast(root->right);

    bool left = leftAns.first;
    bool right = rightAns.first;

    bool condition = root->data = leftAns.second = rightAns.second;

    pair<bool,int> ans;

    if(left && right && condition){
        ans.first = true;
        ans.second = 2*root->data;
    }
    else{
        ans.first = false;
    }

    return ans;

}

bool isSumTree(node* root){

    return isSumTreeFast(root).first;

}

int main(){

    node* root = NULL;

    root = buildTree(root);

    bool result = isSumTree(root);

    if(result){
        cout<<"It is a sum tree "<<endl;
    }
    else{
        cout<<"It is not a sum tree "<<endl;
    }

    return 0;
}
