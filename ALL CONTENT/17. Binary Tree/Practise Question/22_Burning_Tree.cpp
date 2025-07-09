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

// function to create mapping
// this function will create a mapping from node to parent in the binary tree
// this will be used to find the parent of a node in the tree
// function to create mapping
// this function will create a mapping from node to parent in the binary tree
// this will be used to find the parent of a node in the tree
node* createParentMapping(node* root , int target , map<node*,node*> &nodeToParent){
    
    node* res = NULL;
    
    queue<node*> q;

    // pushing root node
    q.push(root);

    // traverse the tree level by level
    while(!q.empty()){
        node* front = q.front();
        q.pop();

        // if the target node is found then return the node
        if(front->data == target){ 
            res = front;
        }

        // adding left and right node in the queue
        if(front->left){
            // adding left node in the queue
            nodeToParent[front->left] = front;
            q.push(front->left);
        }

        if(front->right){
            // adding right node in the queue
            nodeToParent[front->right] = front;
            q.push(front->right);
        }
    }
    return res;
}


// function to burn the tree
// this function will burn the tree in minimum time
// it will return the minimum time required to burn the tree
int burnTree(node* root , map<node*,node*> &nodeToParent){
    // to keep track of visited nodes
    map<node*,bool> visited;
    // to store nodes in the queue
    queue<node*> q;

    q.push(root);
    visited[root] = true;

    int time = 0;
    
    while(!q.empty()){

        // to check whether there is an addition in queue or not
        bool flag = false;

        int size = q.size();
        for(int i=0;i<size;i++){
            // process neighbouring nodes
            node* front = q.front();
            q.pop();

            if(front->left && !visited[front->left]){
                flag = true;
                q.push(front->left);
                visited[front->left] = true;
            }

            if(front->right && !visited[front->right]){
                flag = true;
                q.push(front->right);
                visited[front->right] = true;
            }

            if(nodeToParent[front] && !visited[nodeToParent[front]]){
                flag = true;
                q.push(nodeToParent[front]);
                visited[nodeToParent[front]] = true;
            }
        }

        if(flag){
            time++;
        }
    }

    return time;
}

int minTime(node* root , int target){
    
    /*
    Algorithm :
    1. create a mapping from node to parent
    2. find the target node
    3. burn the tree
    */

    // to create node to parent mapping
    map<node*,node*> nodeToParent;

    // to find target node
    node* targetNode = createParentMapping(root , target , nodeToParent);

    // to store the minimum time
    int ans = burnTree(targetNode , nodeToParent);

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

    node* root = buildTree(root);
    printInOrder(root);

    int target = 8;
    int ans = minTime(root , target);

    cout << endl << "Minimum time required to burn the tree : " << ans << endl;

    return 0;
}


