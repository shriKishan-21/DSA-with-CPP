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


void insertAtHead(Node* &head,Node* &tail,int d){

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
        // point this new node to head
        temp->next = head;
        // update prev
        head->prev = temp;
        // update head
        head = temp;
    }
}

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
void insertAtPosition(Node* &head , Node* &tail , int position , int d){

    if(position==1){
        insertAtHead(head,tail,d);
        return ;
    }

        Node* temp = head;
        int count = 0;

        while(count<position-1){
            temp=temp->next;
            count++;
        }

        if(temp->next==NULL){
            insertAtTail(head,tail,d);
            return ;
        }

        Node* newNode = new Node(d);
        newNode->next = temp->next;
        temp->next->prev = newNode;
        temp->next = newNode;
        newNode->prev = temp; 
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

    insertAtPosition(head,tail,3,35);

    printLL(head);

    return 0;
}