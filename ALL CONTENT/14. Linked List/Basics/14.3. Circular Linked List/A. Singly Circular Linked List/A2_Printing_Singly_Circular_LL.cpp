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

    // Destructor
    ~Node(){
        int value = this->data;
        if(this->next!=NULL){
            delete next;
            next = NULL;
        }
        cout<<"Memory is free for Node with data "<<value<<endl;
    }
};
 

void print(Node* tail){
    Node* temp = tail;

    // move tail until it again reaches itself which is stored as temp
    do{
        cout<<tail->data<<" ";
        tail=tail->next;
    }while(tail!=temp);
}


int main()
{
    Node* head = new Node(10);
    
    print(head);

    return 0;
}