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
 
int main()
{
    Node* head = new Node(10);
    Node* node1 = new Node(20);
    printLL(head);


    return 0;
}