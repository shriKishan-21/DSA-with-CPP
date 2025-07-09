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

void createMapping(int in[],map<int,int> &nodeToIndex,int n){
    for(int i = 0;i<n;i++){
        nodeToIndex[in[i]]=i;
    }
}


node* solve(int in[] , int pre[] , int index , int inOrderStart , int inOrderEnd , int n , map<int,int> &nodeToIndex){
    // base case
    // if index exceeds total length or if startofinorder exceeds its end
    if(index >= n || inOrderStart>inOrderEnd){
        return NULL;
    }

    int element = pre[index++];
    node* root = new node(element);

    int position = nodeToIndex[element];

    // As preorder is NLR so first root node -> left side call -> right side call
    // recursive call
    // so left side of root in inOrder will be from the firstIndex of inOrder to position-1 
    root->left = solve(in,pre,index,inOrderStart,position-1,n,nodeToIndex);

    // right side of root in inOrder will be from position+1 to end of inOrder 
    root->right = solve(in,pre,index,position+1,inOrderEnd,n,nodeToIndex);

    return root;
}

node* buildTree(int in[],int pre[],int n){
    // as it is preOrder so the first index will be the root index -- NLR
    int preOrderIndex = 0;

    // creating map to map the values in inorder with their indexes
    map<int,int> nodeToIndex;

    // function to add indexes in map
    createMapping(in,nodeToIndex,n);

    node* ans = solve(in,pre,preOrderIndex,0,n-1,n,nodeToIndex);

    return ans;

}


void printInOrder(node* root){
    if(root == NULL){
        return;
    }
    printInOrder(root->left);
    cout << root->data << " ";
    printInOrder(root->right);
}

int main() {
    int in[] = {3,1,4,2,5};
    int pre[] = {1,2,3,4,5};
    int n = 5;
    node* root = buildTree(in,pre,n);

    printInOrder(root);

    return 0;
}


