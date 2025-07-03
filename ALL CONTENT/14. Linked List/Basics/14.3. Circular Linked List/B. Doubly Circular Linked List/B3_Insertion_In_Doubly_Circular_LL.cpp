#include<iostream>
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

    // destructor
    ~Node(){
        int value = this->data;
        if(this->next != NULL){
            delete next;
            next = NULL;
        }
        cout<<"Memory is free for Node with data "<<value<<endl;
    }
};

// Insert after element
void insertNode(Node* &tail, int element, int d){
    // Empty list
    if(tail == NULL){
        Node* newNode = new Node(d);
        newNode->next = newNode;
        newNode->prev = newNode;
        tail = newNode;
    }
    else{
        // Non-empty list - find element
        Node* curr = tail;

        do {
            if(curr->data == element) break;
            curr = curr->next;
        } while(curr != tail);

        // Insert after curr
        Node* newNode = new Node(d);
        newNode->next = curr->next;
        newNode->prev = curr;

        curr->next->prev = newNode;
        curr->next = newNode;

        // Optional: update tail if we want to consider insert at end
        // For this implementation, tail remains same unless inserting after tail
        if(curr == tail){
            tail = newNode;
        }
    }
}

void print(Node* tail){
    if(tail == NULL){
        cout<<"List is empty"<<endl;
        return;
    }

    Node* head = tail->next;
    Node* temp = head;

    do{
        cout<<temp->data<<" ";
        temp = temp->next;
    } while(temp != head);

    cout<<endl;
}

// Print in reverse
void printReverse(Node* tail){
    if(tail == NULL){
        cout<<"List is empty"<<endl;
        return;
    }

    Node* temp = tail;

    do{
        cout<<temp->data<<" ";
        temp = temp->prev;
    } while(temp != tail);

    cout<<endl;
}

int main(){
    Node* tail = NULL;

    insertNode(tail, 0, 10);     // first node when list is empty
    insertNode(tail, 10, 12);
    insertNode(tail, 12, 15);
    insertNode(tail, 15, 18);
    insertNode(tail, 18, 21);

    cout<<"List forward: ";
    print(tail);

    cout<<"List backward: ";
    printReverse(tail);

    return 0;
}
