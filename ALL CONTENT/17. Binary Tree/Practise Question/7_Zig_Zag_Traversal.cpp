#include<iostream>
#include<stack>
#include<queue>
#include<vector>
#include<algorithm>
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

vector<int> zigZagTraversal(node* root){

    // result to store final ans
    vector<int> result;
    if(root==NULL){
        return result;
    }

    // build a queue
    queue<node*> q;
    q.push(root);

    // bool to traverse leftToRight or RightToLeft
    bool leftToRight = true;

    while(!q.empty()){
        // calculate size of queue
        int size = q.size();
        // create a temp ans to store nodes pair from RL or LR
        vector<int> ans;

        // Level process
        for(int i =0;i<size;i++){
            node* frontNode = q.front();
            q.pop();

            // normal insert or reverse insert
            int index = leftToRight?i:size-i-1;

            ans[index] = frontNode->data;

            if(frontNode->left){
                q.push(frontNode->left);
            }
            if(frontNode->right){
                q.push(frontNode->right);
            }
        }

        // change direction
        leftToRight = !leftToRight;

        // store ans in result
        for(auto i : ans){
            result.push_back(i);
        }
    }
    return result;
}

int main()
{
    node* root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);
    root->left->right = new node(5);
    root->right->left = new node(6);
    root->right->right = new node(7);

    vector<int> result = zigZagTraversal(root);
    for (auto i : result)
    {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}
