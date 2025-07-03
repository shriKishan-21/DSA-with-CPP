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



pair<Node*,Node*> splitCircularList(Node* head){
    Node* slow = head;
    Node* fast = head;
    
    if(head==NULL){
        return {NULL,NULL};
    }
    
    // for odd nodes - fast->next will be head
    // for even nodes - fast->next->next will be head
    while(fast->next != head && fast->next->next != head){
        fast=fast->next->next;
        slow=slow->next;
    }
    
    // for even elements - fast will be a node behind last node so well move fast to next node
    if(fast->next->next == head){
        fast=fast->next;
    }
    
    Node* head1 = head;
    Node* head2 = slow->next;
    
    fast->next = slow->next;
    
    slow->next = head;
    
    return {head1,head2};
    
}

void print(Node* &head){
    Node* temp = head;

    if(head!=NULL){
        do{
            cout<<temp->data<<" ";
            temp=temp->next;
        }while(temp!=head);
        cout<<endl;
    }
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

    pair<Node*,Node*> result = splitCircularList(head1);
    Node* head1 = result.first;
    Node* head2 = result.second;

    print(head1);
    print(head2);

    return 0;
}