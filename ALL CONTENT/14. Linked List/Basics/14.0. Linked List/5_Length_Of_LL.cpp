#include<iostream>
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

    // constructor
    Node(int data,Node* next){
        this->data = data;
        this->next = next;
    }
};

// length of linked list
int getLength(Node* head){
    int len = 0;
    Node* temp = head;

    while(temp!=NULL){
        len++;
        temp=temp->next;
    }
    return len;
}
// printing a linked list
void printLL(Node* &head){
    // First check if Linked List is empty
    if(head==NULL){
        cout<<"Linked list is empty"<<endl;
    }

    // store head in a temporary variable
    Node* temp = head;

    // run while loop till temp reaches NULL
    while(temp!=NULL){
        // print the current node
        cout<<temp->data<<" ";
        // move temp to next node
        temp = temp->next;

    }
}
 