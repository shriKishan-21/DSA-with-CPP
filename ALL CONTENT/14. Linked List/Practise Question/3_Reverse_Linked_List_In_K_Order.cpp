#include <bits/stdc++.h>
using namespace std;

class Node
{

public:
    int data;
    Node *next;

    // constructor
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

void insertAtTail(Node *&tail, int d)
{

    // create new node
    Node *temp = new Node(d);
    // point this new node to head
    tail->next = temp;
    // update head
    tail = temp;
}

// --------------------------------------------------------------------- 

// Approach 1 -- using recursion
Node* kReverse(Node* head,int k){
    // basec case
    if(head==NULL){
        return NULL;
    }

    // step 1 : reverse first k nodes
    Node* forward = NULL;
    Node* curr = head;
    Node* prev = NULL;
    int count = 0;

    while(count<k && curr!=NULL){
        forward = curr->next;
        curr->next = prev;
        prev = curr;
        curr = forward;
        count++;
    }

    // Step 2 : recursive call
    if(forward!=NULL){
        head->next = kReverse(forward,k);
    }

    // Step 3 : return head of reversed LL
    return prev;

}

void print(Node* &head){
    Node* temp = head;
    if(temp==NULL){
        cout<<"List is empty";
        return;
    }
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}

int main()
{
    Node *node1 = new Node(10);

    // head pointing to node1
    Node *head1 = node1;
    Node *tail1 = node1;

    insertAtTail(tail1, 12);
    insertAtTail(tail1, 15);
    insertAtTail(tail1, 18);
    insertAtTail(tail1, 21);
    print(head1);
    cout << endl;

    int k = 2;
    Node* newHead = kReverse(head1,k);
    print(newHead);
    return 0;
}