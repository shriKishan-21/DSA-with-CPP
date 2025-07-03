#include<bits/stdc++.h>
using namespace std;

class Node{
    
    public:
    int data;
    Node* next;
    Node* prev;

    // constructor
    Node(int data){
        this->data = data;
        this->next = NULL;
        this->prev = NULL;
    }
};

void insertAtTail(Node* &head,Node* &tail,int d){

    // empty list
    // create a new node and point head and tail on it
    if(head==NULL){
        Node* temp = new Node(d);
        head=temp;
        tail = temp;
    }
    else{
        // create new node
        Node* temp = new Node(d);
        // point tail to this new node
        tail->next = temp;
        // update prev
        temp->prev = tail;
        // update head
        tail = temp;
    }
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
    
    insertAtTail(head,tail,20);
    insertAtTail(head,tail,30);
    insertAtTail(head,tail,40);

    printLL(head);

    return 0;
}