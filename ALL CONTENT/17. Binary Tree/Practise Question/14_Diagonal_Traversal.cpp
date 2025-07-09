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

    // create a map for the mapping of horizontal distance value and map of level and all nodes in that level
    map<int,map<int,vector<int>>> nodes;

    // create a queue which store pair of node and their coresponding horizontal distance and level pair4
    queue<pair<node*,pair<int,int>>> q;

    // create arr ans to store the nodes in output way
    vector<int> ans;

    if(root==NULL){
        return ans;
    }

    // pushing root node
    q.push(make_pair(root,make_pair(0,0)));

    while(!q.empty()){
        pair<node* , pair<int,int>> temp = q.front();
        q.pop();

        // temp.first will be the node
        node* frontNode = temp.first;

        // temp.second is pair<int,int> and first mean first int which is horizontal distance
        int hd = temp.second.first;
        // temp.second is pair<int,int> and second mean second int which is level
        int lvl = temp.second.second;

        // pushing the node int the map nodes according to their horizontal distance and level
        nodes[hd][lvl].push_back(frontNode->data);

        // moving left -- moving left of root node mean decrease in hd and increase in lvl as we move down
        if(frontNode->left){
            q.push(make_pair(frontNode->left,make_pair(hd-1,lvl+1)));
        }

        // moving right -- moving right of root node mean increase in hd and increase in lvl as we move down
        if(frontNode->right){
            q.push(make_pair(frontNode->right,make_pair(hd+1,lvl+1)));
        }

        // pushing nodes in the ans -- we need to push nodes
        // i : nodes -- entire map named nodes
        for(auto i : nodes){
            // j : i.second -- the second element of that map that is -- map<int,vector<int>>
            for(auto j : i.second){
                // k : j.second -- the second element of map<int,vector<int>> that is -- vector<int>
                for(auto k : j.second){
                    // pushing nodes stored in vector<int> int another arr ans
                    ans.push_back(k);
                }
            }
        }

    }

    return ans;
}

int main() {
    node* root = NULL;
    root = buildTree(root);

    vector<int> result = verticalOrder(root);

    cout << "Vertical Order Traversal: ";
    for (int val : result) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}

