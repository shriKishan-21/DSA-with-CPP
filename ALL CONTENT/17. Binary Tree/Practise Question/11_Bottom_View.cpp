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

vector<int> topView(node* root){

    // create arr ans to store the nodes in output way
    vector<int> ans;

    if(root==NULL){
        return ans;
    }

    map<int,int> topNodes;

    queue<pair<node*,int>> q;

    // pushing root node
    q.push(make_pair(root,0));

    while(!q.empty()){
        pair<node* , int> temp = q.front();
        q.pop();

        // temp.first will be the node
        node* frontNode = temp.first;

        // temp.second is horizontal distance
        int hd = temp.second;
    
        // no need to check any condition -- as we need new value appear to replace the previous value
        topNodes[hd] = frontNode->data;

        // moving left -- moving left of root node mean decrease in hd
        if(frontNode->left){
            q.push(make_pair(frontNode->left,hd-1));
        }

        // moving right -- moving right of root node mean increase in hd
        if(frontNode->right){
            q.push(make_pair(frontNode->right,hd+1));
        }
    }


    for(auto i : topNodes){
        ans.push_back(i.second);
    }
            

    return ans;
}

int main(){

    node* root = NULL;

    root = buildTree(root);

    vector<int> ans = topView(root);

    for(auto i : ans){
        cout<<i<<" ";
    }

    return 0;
}
