
#include<bits/stdc++.h>
using namespace std;

class Node{
    
    public:
    int data;
    Node* next;

    // constructor
    Node(int data){
        this->data = data;
        this->next = NULL;
    }
};
 
/*
Function 1 --> cant handle head and tail case
void insertAtPosition(Node* &head,int d,int position){
    // find the node where to insert the node
    Node* temp = head;
    int count = 1;
    // temp will move until position-1 is reach
    while(count<position-1){
        // move until position is reach
        temp = temp->next;
        count++;
    }
    // creating new node
    Node* nodeToInsert = new Node(d);
    // newNode -> next will be the node at position -1 ->next
    nodeToInsert->next = temp->next;
    // temp -> next will be nodeToInsert
    temp->next = nodeToInsert;

}

*/

// Lets write a function that can handle all code
// optimized function

// case 1 : code for inserting at head
void insertAtHead(Node* &head,int d){

    // create new node
    Node* temp = new Node(d);
    // point this new node to head
    temp->next = head;
    // update head
    head = temp;
}

// case 2 : code for insertion at tail
void insertAtTail(Node* &tail,int d){

    // create new node
    Node* temp = new Node(d);
    // point this new node to head
    tail->next = temp;
    // update head
    tail = temp;
}

void insertAtPosition(Node* &head,Node* &tail,int d,int position){

    // case 1: if position is 1 --> insert at head
    if(position==1){
        insertAtHead(head,d);
        return ;
    }

    // find the node where to insert the node
    Node* temp = head;
    int count = 1;
    // temp will move until position-1 is reach
    while(count<position-1){
        // move until position is reach
        temp = temp->next;
        count++;
    }

    // case 2 : if position at end --> insert at tail
    if(temp->next==NULL){
        insertAtTail(tail,d);
        return ;
    }

    // case 3 : insert at position
    // creating new node
    Node* nodeToInsert = new Node(d);
    // newNode -> next will be the node at position -1 ->next
    nodeToInsert->next = temp->next;
    // temp -> next will be nodeToInsert
    temp->next = nodeToInsert;

}

void printLL(Node* &head){
    if(head==NULL){
        cout<<"Linked list is empty"<<endl;
    }

    Node* temp = head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp = temp->next;

    }
}
int main()
{
    Node* node1 = new Node(10);


    // head pointing to node1
    Node* head = node1;
    Node* tail = node1;

    insertAtTail(tail,12);
    insertAtTail(tail,15);
    insertAtTail(tail,18);
    insertAtTail(tail,21);
    printLL(head);
    cout<<endl;

    // inserting at position -- ex 1
    insertAtPosition(head,tail,16,4);
    printLL(head);
    cout<<endl;

    // inserting at position -- ex 2
    insertAtPosition(head,tail,19,6);
    printLL(head);


    return 0;
}