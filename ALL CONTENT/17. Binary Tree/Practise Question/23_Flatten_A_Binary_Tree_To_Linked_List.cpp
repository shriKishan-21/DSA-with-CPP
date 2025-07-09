#include <iostream>
#include <vector>
using namespace std;


// A binary tree node
class node {
public:
    int data;
    node* left;
    node* right;

    node(int x) {
        data = x;
        left = right = NULL;
    }
};

// Function for inorder traversal using Morris Traversal
void flattenABinaryTree(node* root) {

    // Initialize current
    node* curr = root;

    // Here we can see preOrder traversal - NLR 
    while (curr != NULL) {
        // if current left exists
        if (curr->left) {
            // Find the preorder predecessor of curr
            node* prev = curr->left;
            while (prev->right != NULL) {
                prev = prev->right;
            }
            // point preorder predecessor to current right
            prev->right = curr->right;
            // make current left as right of current
            curr->right = curr->left;
            // make current left as NULL
            curr->left = NULL;
        }
        else {
            curr = curr->right;
        }
    }
}

int main() {

    node* root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);
    root->left->right = new node(5);
    root->right->left = new node(6);
    root->right->right = new node(7);

    flattenABinaryTree(root);

    node* curr = root;
    while(curr!=NULL){
        cout<<curr->data<<" ";
        curr = curr->right;
    }
    
    return 0;
}
