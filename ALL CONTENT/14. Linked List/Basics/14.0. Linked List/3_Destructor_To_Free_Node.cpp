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
        // value is just to check which node is deleted
        int value = this->data;

        // memory free
        while(this->next!=NULL){
            delete next;
            this->next=NULL;
        }

        cout<<"Memory is for node with data : "<<value<<endl;
    }

};

int main(){

    Node* head = new Node(10);
    Node* node1 = new Node(20);

    delete(node1);

    cout<<head->data<<endl;
    cout<<node1->data<<endl;

    return 0;
}