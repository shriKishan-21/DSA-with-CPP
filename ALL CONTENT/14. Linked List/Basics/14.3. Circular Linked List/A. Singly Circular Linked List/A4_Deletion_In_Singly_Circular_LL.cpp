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
        if(this->next != NULL){
            delete next;
            next = NULL;
        }
        cout<<"Memory is free for Node with data "<<value<<endl;
    }
};

void insertNode(Node* &tail, int element, int d){
    // empty list
    if(tail == NULL){
        Node* newNode = new Node(d);
        tail = newNode;
        newNode->next = newNode;
    }
    else{
        // non-empty list
        Node* curr = tail;
        // find element
        do{
            if(curr->data == element){
                break;
            }
            curr = curr->next;
        } while(curr != tail);

        // insert after curr
        Node* temp = new Node(d);
        temp->next = curr->next;
        curr->next = temp;
    }
}

void deleteNode(Node* &tail, int value){
    // empty list
    if(tail == NULL){
        cout<<"List is empty"<<endl;
        return;
    }
    else{
        Node* prev = tail;
        Node* curr = prev->next;
        Node* start = curr;

        // search for node to delete
        do{
            if(curr->data == value){
                break;
            }
            prev = curr;
            curr = curr->next;
        } while(curr != start);

        // if not found
        if(curr->data != value){
            cout<<"Value "<<value<<" not found in the list"<<endl;
            return;
        }

        // node found, delete it
        prev->next = curr->next;

        // only one node
        if(curr == prev){
            tail = NULL;
        }
        // if tail to be deleted
        else if(curr == tail){
            tail = prev;
        }

        curr->next = NULL;
        delete curr;
    }
}

void print(Node* tail){
    if(tail == NULL){
        cout<<"List is empty"<<endl;
        return;
    }

    Node* curr = tail->next;
    Node* start = curr;

    do{
        cout<<curr->data<<" ";
        curr = curr->next;
    } while(curr != start);

    cout<<endl;
}

int main(){
    Node* tail = NULL;

    insertNode(tail, 0, 10);
    insertNode(tail, 10, 12);
    insertNode(tail, 12, 15);
    insertNode(tail, 15, 18);
    insertNode(tail, 18, 21);

    print(tail);

    cout<<endl<<"Deleting 12..."<<endl;
    deleteNode(tail,12);

    print(tail);

    return 0;
}
