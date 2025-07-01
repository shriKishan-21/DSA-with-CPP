#include<iostream>
using namespace std;

class Node{
    
    public:
    int data;
    Node* next;

    // constructor -- only input data
    Node(int data){
        this->data = data;
        this->next = NULL;
    }

    // constructor -- will take data and address of next node
    Node(int data,Node* next){
        this->data = data;
        this->next = next;
    }

};

int main(){

    // creating head node
    Node* head = new Node(10);

    cout<<head->data<<endl;
    cout<<head->next<<endl;

    // creating node 

    return 0;
}