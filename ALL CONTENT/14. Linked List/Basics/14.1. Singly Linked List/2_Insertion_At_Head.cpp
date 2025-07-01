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

// function to insert node at head
void insertAtHead(Node* &head,int d){

    // create new node
    Node* temp = new Node(d);
    // point this new node to head
    temp->next = head;
    // update head
    head = temp;
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
    
    insertAtHead(head,20);

    printLL(head);

    return 0;
}