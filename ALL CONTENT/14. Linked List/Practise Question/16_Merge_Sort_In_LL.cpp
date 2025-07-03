
#include <bits/stdc++.h>
using namespace std;

class Node
{

public:
    int data;
    Node* next;

    // constructor
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

void insertAtTail(Node* &tail, int d)
{
    // create new node
    Node *temp = new Node(d);
    // point this new node to head
    tail->next = temp;
    // update head
    tail = temp;
}

// --------------------------------------------------------------------- 

Node* findmid(Node* head){
    Node* fast = head->next;
    Node* slow = head;

    while(fast!=NULL && fast->next!=NULL){
        fast=fast->next->next;
        slow=slow->next;
    }
    return slow;
}

Node* merge(Node* left,Node* right){
    if(left==NULL){
        return right;
    }
    if(right==NULL){
        return left;
    }

    // dummy node to store LL
    Node* ans = new Node(-1);
    Node* temp = ans;

    while(left!=NULL && right!=NULL){
        if(left->data < right->data){
            temp->next = left;
            temp = left;
            left = left->next;
        }
        else{
            temp->next=right;
            temp=right;
            right=right->next;
        }
    }

    while(left!=NULL){
        temp->next=left;
        temp=left;
        left=left->next;
    }

        while(right!=NULL){
        temp->next=right;
        temp=right;
        right=right->next;
    }

    // remove dummy node
    ans = ans -> next;

    return ans;
}

Node* mergeSort(Node* head){
    // base case
    if(head==NULL || head->next==NULL){
        return head;
    }

    // find mid
    Node* mid = findmid(head);

    // find head of left half and right half
    Node* left = head;
    Node* right = mid->next;

    mid->next = NULL;

    // recursive call
    left = mergeSort(left);
    right = mergeSort(right);

    // merge both left ans right -- merge 2 sorted LL
    Node* result = merge(left,right);

    return result;

}

// --------------------------------------------------------------------

void printLL(Node *&head)
{
    if (head == NULL)
    {
        cout << "Linked list is empty" << endl;
    }

    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
}
int main()
{
    // first list
    Node *first = new Node(3);
    // head pointing to node1
    Node *head1 = first;
    Node *tail1 = first;
    insertAtTail(tail1, 5);
    insertAtTail(tail1, 2);
    insertAtTail(tail1, 1);
    insertAtTail(tail1, 2);
    insertAtTail(tail1, 9);


    // Approach 1
    Node* ans = mergeSort(head1);
    printLL(ans);

    return 0;
}
