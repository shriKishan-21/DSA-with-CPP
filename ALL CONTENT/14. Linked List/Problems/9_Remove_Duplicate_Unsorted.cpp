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


Node* uniqueSortedList(Node* head){
    // empty List
    if(head==NULL){
        return NULL;
    }

    // non empty list
    Node* curr = head;

    while(curr!=NULL){
        if(curr->next != NULL && curr->data==curr->next->data){
            // store next node to the node to delete
            Node* temp = curr->next->next;

            // store the node to be deleted
            Node* nodeToDelete = curr->next;

            //delete the node
            delete (nodeToDelete);

            // update the next node
            curr->next = temp;
        }
        else{
            // move to the next node
            curr = curr->next;
        }
    }

    return head;
}

void print(Node* &head){
    Node* temp = head;

    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}
int main()
{
    Node* head = new Node(10);
    head->next = new Node(20); 
    head->next->next = new Node(30); 
    head->next->next->next = new Node(40); 
    head->next->next->next->next = head;

    Node* newHead = uniqueSortedList(head);
    print(newHead);

    return 0;
}