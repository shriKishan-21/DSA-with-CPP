#include<bits/stdc++.h>
using namespace std;


class Node{
    public:
    int data;
    Node* next;

    Node(int data){
        this->data=data;
        this->next = NULL;

    }
    Node(int data, Node* next){
        this->data=data;
        this->next = next;
    }
};

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
int main()
{
    Node* head = new Node(10);
    head->next = new Node(20); 
    head->next->next = new Node(30); 
    head->next->next->next = new Node(40); 
    head->next->next->next->next = head; 

    if(isCircular(head)){
        cout<<"Circular Linked List"<<endl;
    }
    else{
        cout<<"Not Circular Linked List"<<endl;
    }

    return 0;
}