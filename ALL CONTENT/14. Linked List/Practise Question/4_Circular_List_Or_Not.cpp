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

// Aproach 1
bool isCircular(Node* head){
    // empty list
    if(head==NULL){
        return true;
    }

    // Node >=1 case
    Node* temp = head->next;

    // while loop will run till either temp will be NULL (that means list is not circulat)
    // or temp will be  head(that means list is circular)
    while(temp!=NULL && temp!=head){
        temp=temp->next;
    }

    // temp value will be given and if temp is NULL return false otherwise true
    if(temp==head){
        return true;
    }

    else{
        return false;
    } 
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

    if(isCircular(head1)){
        cout<<"Circular Linked List"<<endl;
    }
    else{
        cout<<"Not Circular Linked List"<<endl;
    }

    return 0;
}