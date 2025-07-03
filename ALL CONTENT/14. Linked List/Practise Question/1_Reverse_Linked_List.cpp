#include<iostream>
#include <bits/stdc++.h>
using namespace std;

// Following is the class structure of the Node class:
class Node{
public:
    int data;
    Node *next;
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

// ---------------------------------------------------------------------------
// Approach 1 :
// Iterative approach
Node *reverseLinkedList1(Node *head)
{
    // if we have empty LL or one node LL
    if (head == NULL)
    {
        return head;
    }

    // else
    Node *prev = NULL;
    Node *curr = head;
    Node *forward = NULL;

    while (curr != NULL)
    {
        forward = curr->next;
        curr->next = prev;
        prev = curr;
        curr = forward;
    }

    return prev;
    
}

// ------------------------------------------------------------------------------

// Approach 2 :
// Recursive approach
Node *reverse(Node* &head,Node *curr,Node *prev){
    // base case
    if(curr==NULL){
        head = prev;
        return head;
    }

    // 1 cas solve
    Node *position = curr->next;

    // recursive call
    reverse(head,position,curr);

    curr->next = prev;
}

Node *reverseLinkedList2(Node *head)
{
    Node *prev = NULL;
    Node *curr = head;
    reverse(head,curr,prev);

    return head;
}

//--------------------------------------------------------------------------------------

// Approach 3
// using recursion
Node *reverse1(Node *head){
    // base case 
    if(head==NULL || head->next==NULL){
        return head;
    }

    // head of revesed LL
    // reverse1(head->next) will reverse the LL
    Node *smallHead = reverse1(head->next);

    // solve 1 case
    head->next->next = head;
    head->next=NULL;

    return smallHead;
}

Node *reverseLinkedList3(Node *head)
{
    reverse1(head);

    return head;
}

// -----------------------------------------------------------------------

// print the linked list
void print(Node* &head){
    Node *temp = head;

    while(temp != NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}

// -------------------------------------------------------------------------

int main()
{

    // For Approach 1
    Node *node = new Node(1);
    node->next = new Node(2);
    node->next->next = new Node(3);
    node->next->next->next = new Node(4);
    node->next->next->next->next = new Node(5);

    Node *head = reverseLinkedList1(node);
    print(head);

    // For Approach 2
    Node *node1 = new Node(1);
    node1->next = new Node(2);
    node1->next->next = new Node(3);
    node1->next->next->next = new Node(4);
    node1->next->next->next->next = new Node(5);

    Node *head1 = reverseLinkedList2(node1);
    print(head1);   
    
    // For Approach 3
    Node *node2 = new Node(1);
    node2->next = new Node(2);
    node2->next->next = new Node(3);
    node2->next->next->next = new Node(4);
    node2->next->next->next->next = new Node(5);

    Node *head2 = reverseLinkedList3(node2);
    print(head2);  

    return 0;
}
