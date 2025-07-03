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

Node* uniqueSortedList(Node* head){
    // empty List
    if(head==NULL){
        return NULL;
    }

    // non empty list
    Node* curr = head;

    while(curr!=NULL){
        if(curr->next != NULL && curr->data==curr->next->data){
            // store next node that duplicate node is posinting to
            Node* forward = curr->next->next;

            // store the node to be deleted
            Node* nodeToDelete = curr->next;

            //delete the node
            delete (nodeToDelete);

            // update the next node
            curr->next = forward;
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
    // first list
    Node *first = new Node(1);
    // head pointing to node1
    Node *head1 = first;
    Node *tail1 = first;
    insertAtTail(tail1, 2);
    insertAtTail(tail1, 2);
    insertAtTail(tail1, 3);
    insertAtTail(tail1, 3);
    insertAtTail(tail1, 3);
    insertAtTail(tail1, 4);

    Node* newHead = uniqueSortedList(first);
    print(newHead);

    return 0;
}