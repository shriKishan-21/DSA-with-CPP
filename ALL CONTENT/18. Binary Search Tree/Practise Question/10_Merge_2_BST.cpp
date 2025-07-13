 #include <iostream>
#include <algorithm>
#include<stack>
#include <queue>
#include<algorithm>
#include <climits>
using namespace std;

class node
{

public:
    int data;
    node *left;
    node *right;

    node(int d)
    {
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};

node *insertIntoBST(node *&root, int d)
{
    // base case
    if (root == NULL)
    {
        root = new node(d);
        return root;
    }

    if (root->data < d)
    {
        // insertion in right
        root->right = insertIntoBST(root->right, d);
    }
    else
    {
        // insertion in left
        root->left = insertIntoBST(root->left, d);
    }
    return root;
}
void takeInput(node *&root)
{
    int data;
    cin >> data;

    while (data != -1)
    {
        insertIntoBST(root, data);
        cin >> data;
    }
}

// -----------------------------------------------------------------------------

// Approach 1
void inorder1(node* root,vector<int> &arr){
    if(root==NULL){
        return;
    }
    inorder1(root->left,arr);
    arr.push_back(root->data);
    inorder1(root->right,arr);
}

vector<int> mergeArrays(vector<int> a , vector<int> b){
    vector<int> ans(a.size() + b.size());

    int i =0;
    int j =0;
    int k =0;

    while(i<a.size() && j<b.size()){
        if(a[i]<b[j]){
            ans[k++] = a[i];
            i++;
        }
        else{
            ans[k++] = b[j];
            j++;
        }
    }

    while(i<a.size()){
        ans[k++] = a[i];
        i++;
    }

    while(j<b.size()){
        ans[k++] = b[j];
        j++;
    }

    return ans;
}

node* inorderToBST1(int s , int e , vector<int> &in){

    if(s>e){
        return NULL;
    }

    int mid = (s+e)/2;
    node* root = new node(in[mid]);
    root->left = inorderToBST1(s,mid-1,in);
    root->right = inorderToBST1(mid+1,e,in);

    return root;
}

node* mergeBST(node* root1,node* root2){
    // step 1 : store inorder   
    vector<int> bst1,bst2;;
    inorder1(root1,bst1);
    inorder1(root2,bst2);

    // step 2 : merge the arrays
    vector<int> merged = mergeArrays(bst1,bst2);

    // step 3 : create BST from the merged array
    int s = 0,e = merged.size()-1;

    return inorderToBST1(s,e,merged);

}

// -----------------------------------------------------------------------------

// Approach 2
// 1. convert a BST to a sorted DLL
void convertIntoSortedToDLL(node* root,node* &head){
    // base case
    if(root==NULL){
        return;
    }

    convertIntoSortedToDLL(root->left,head);
    head->right = head;
    if(head != NULL){
        head->left = root;
    }
    head = root;

    convertIntoSortedToDLL(root->right,head);
    
}

// 2. merge 2 sorted DLL
node* mergeDLL(node* head1,node* head2){
    node* head = NULL;
    node* tail = NULL;

    while(head1 != NULL && head2 != NULL){
        if(head1->data < head2->data){
            if(head==NULL){
                head = head1;
                tail = head1;
                head1 = head1->right;
            }
            else{
                tail->right = head1;
                head1->left = tail;
                tail = head1;
                head1 = head1->right;
            }
        }
        else{
            if(head==NULL){
                head = head2;
                tail = head2;
                head2 = head2->right;
            }
            else{
                tail->right = head2;
                head2->left = tail;
                tail = head2;
                head2 = head2->right;
            }
            
        }
    }

    while(head1 != NULL){
        tail->right = head1;
        head1->left = tail;
        tail = head1;
        head1 = head1->right;
    }

    while(head2 != NULL){
        tail->right = head2;
        head2->left = tail;
        tail = head2;
        head2 = head2->right;
    }

    return head;

}

// 3. convert DLL to BST
node* sortedLLToBST(node* &head , int n){
    // base case
    if(n<=0 || head == NULL){
        return NULL;
    }

    node* left = sortedLLToBST(head,n/2);

    node* mid = head;
    mid->left = NULL;
    head = head->right;

    mid->right = sortedLLToBST(mid->right,n-n/2-1);

    return mid;
}

int countNodes(node* root){
    int cnt = 0;
    node* temp = root;

    while(temp != NULL){
        cnt++;
        temp = temp->right;
    }
    return cnt;
}
node* mergeBST2(node* root1,node* root2){
    // step 1 : convert to DLL
    node* head1 = NULL;
    convertIntoSortedToDLL(root1,head1);
    head1->left = NULL;

    node* head2 = NULL;
    convertIntoSortedToDLL(root2,head2);
    head2->left = NULL;

    // step 2 : merge DLL
    node* merged = mergeDLL(head1,head2);

    // step 3 : convert DLL to BST
    int n = countNodes(merged);
    return sortedLLToBST(merged,n);
}


// -----------------------------------------------------------------------------
void inorder2(node* root){
    // base case
    if(root==NULL){
        return;
    }

    // LNR
    inorder2(root->left);
    cout<<root->data<<" ";
    inorder2(root->right);
}


int main(){
    node* root1= NULL;
    cout<<"Enter data to create BST : "<<endl;
    takeInput(root1);

    node* root2= NULL;
    cout<<"Enter data to create BST : "<<endl;
    takeInput(root2);

    // For Approach 1
    node* root3 = mergeBST(root1,root2);
    cout<<"Merged BST is : "<<endl;
    inorder2(root3);

    // For Approach 2
    node* root4 = mergeBST2(root1,root2);
    cout<<"Merged BST is : "<<endl;
    inorder2(root4);

    return 0;
}