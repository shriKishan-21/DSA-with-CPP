#include <iostream>
#include <vector>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int x) {
        data = x;
        left = right = NULL;
    }
};

// Function for inorder traversal using Morris Traversal
vector<int> morrisTraversal(Node* root) {
    vector<int> res;

    // Initialize current
    Node* curr = root;

    while (curr != NULL) {
        if (curr->left == NULL) {
          
            // If no left child, visit this node and go right
            res.push_back(curr->data);
            curr = curr->right;
        }
        else {
          
            // Find the inorder predecessor of curr
            Node* prev = curr->left;
            while (prev->right != NULL && prev->right != curr) {
                prev = prev->right;
            }

            // Make curr the right child of its inorder predecessor
            if (prev->right == NULL) {
                prev->right = curr;
                curr = curr->left;
            } 
            else {
              
                // Revert the changes made in the tree structure
                prev->right = NULL;
                res.push_back(curr->data);
                curr = curr->right;
            }
        }
    }
    return res;
}


int main() {
  
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    vector<int> res = morrisTraversal(root);
  
     for (int data : res) {
        cout << data << " ";
    }
    
    return 0;
}
