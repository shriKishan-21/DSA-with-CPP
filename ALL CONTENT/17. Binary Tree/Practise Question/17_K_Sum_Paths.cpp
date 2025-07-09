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

void solve(node* root,int k , int count , vector<int> path){

    // base case
    if(root==NULL){
        return ;
    }

    path.push_back(root->data);

    // left
    solve(root->left,k,count,path);
    // right
    solve(root->right,k,count,path);

    // check for k sum
    int size = path.size();
    int sum =0;
    for(int i=size-1 ; i>=0 ; i--){
        sum += path[i];
        if(sum==k){
            count++;
        }
    }
    // remove previous element when going back
    path.pop_back();
}
int sumK(node* root,int k){
    vector<int> path;
    int count = 0;
    solve(root,k,count,path);
    
    return count;

}


int main() {
    node* root = NULL;
    
    // Build the tree
    root = buildTree(root);

    // Enter the sum k for which paths need to be found
    cout << "Enter the sum k: ";
    int k;
    cin >> k;
    
    // Find the number of k-sum paths
    int count = sumK(root, k);
    cout << "Number of k-sum paths: " << count << endl;
    
    return 0;
}
 