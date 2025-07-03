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

    // Destructor
    ~Node(){
        if(next!=NULL){
            delete next;
            next = NULL;
        }
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

// ---------------------------------------------------------------------------
void deleteNode(Node* &head , int position){

    // deleting first or head node
    if(position==1){
        Node* temp = head;
        temp->next->prev = NULL;
        head = temp->next;
        temp->next = NULL;
        delete temp;
    }
    else{
        // delete any middle or last node
        Node* curr = head;
        Node* prev = NULL;
        int count = 1;

        while(count<position){
            prev=curr;
            curr=curr->next;
            count++;
        }

        curr->prev = NULL;
        prev->next = curr->next;
        curr->next = NULL;
        delete curr;
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

    deleteNode(head,3);

    printLL(head);

    return 0;
}