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

bool isIdentical(node* r1 , node* r2){

    if(r1==NULL && r2==NULL){
        return true;
    }

    if(r1!=NULL && r2==NULL){
        return false;
    }

    if(r1==NULL && r2!=NULL){
        return false;
    }

    bool left = isIdentical(r1->left,r2->left);
    bool rigt = isIdentical(r1->right,r2->right);

    bool value = r1->data = r2->data;

    if(left && right && value){
        return true;
    }
    else{
        return false;
    }
}

int main(){

    node* root1 = NULL;
    node* root2 = NULL;

    root1 = buildTree(root1);
    root2 = buildTree(root2);

    if(isIdentical(root1,root2)){
        cout<<"Both trees are identical"<<endl;
    }
    else{
        cout<<"Both trees are not identical"<<endl;
    }

    return 0;
}
