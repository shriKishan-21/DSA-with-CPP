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

vector<int> verticalOrder(node* root){

    // create ans to store nodes
    vector<int> ans;

    if(root==NULL){
        return ans;
    }

    queue<node*> q;
    q.push(root);

    while(!q.empty()){
        node* curr = q.front();
        q.pop();

        while(curr){
            // store curr->right in ans
            ans.push_back(curr->data);
            // if curr->left exists then push it into queue
            if(curr->left){
                q.push(curr->left);
            }
            // move curr to next right position
            curr=curr->right;
        }
    }
    return ans;
}


int main() {
    node* root = NULL;
    root = buildTree(root);

    vector<int> ans = verticalOrder(root);

    for(auto i : ans){
        cout<<i<<" ";
    }


    return 0;
}

