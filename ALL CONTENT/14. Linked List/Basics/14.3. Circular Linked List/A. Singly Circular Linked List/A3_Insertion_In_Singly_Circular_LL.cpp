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

void insertNode(Node* &head,Node* &tail,int element,int d){
    // assuming that the element is present in the list

    // empty list
    if(tail==NULL){
        Node* newNode = new Node(d);
        tail = newNode;
        newNode->next = newNode;
    }
    else{
        // non empty list
        Node* curr = tail;

        while(curr->data!=element){
            curr = curr->next;
        }

        // element found
        Node* temp = new Node(d);
        temp->next = curr->next;
        curr->next = temp;
    }
}

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
    Node* node1 = new Node(10);

    // head pointing to node1
    Node* head = node1;
    Node* tail = node1;

    insertNode(head,tail,10,12);
    insertNode(head,tail,12,15);
    insertNode(head,tail,15,18);
    insertNode(head,tail,18,21);
    print(head);

    return 0;
}