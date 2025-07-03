
#include <bits/stdc++.h>
using namespace std;

class Node
{

public:
    int data;
    Node* next;
    Node* random;

    // constructor
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
        this->random = NULL;
    }
};

void insertAtTail(Node* &tail, int d)
{
    // create new node
    Node *temp = new Node(d);
    // point this new node to head
    tail->next = temp;
    // update head
    tail = temp;
}

// --------------------------------------------------------------------- 

// common function to all three approaches
void insertAtTail(Node* &head,Node* &tail,int digit){
    Node* newNode = new Node(digit);

    if(head==NULL){
        head=newNode;
        tail = newNode;
        return ;
    }
    else{
        tail->next=newNode;
        tail=newNode;
    }

}


// --------------------------------------------------------------------
// Approach 1

/*
TIME COMPLEXITY : O(N^2)
SPACE COMPLEXITY : O(N)
*/
// --------------------------------------------------------------------

// Approach 2
// using Map
Node* copyList(Node* head){
    // step 1 : create a clone list
    Node* cloneHead = NULL;
    Node* cloneTail = NULL;

    Node* temp = head;

    while(temp!=NULL){
        insertAtTail(cloneHead,cloneTail,temp->data);
        temp = temp ->next;
    }

    // step 2 : create a map
    unordered_map<Node* , Node*> mapping;

    Node* originalNode = head;
    Node* cloneNode = cloneHead;

    // mapping all originalnode with cloneNode
    while(originalNode!=NULL){
        mapping[originalNode]=cloneHead;

        originalNode = originalNode->next;
        cloneNode = cloneNode->next;
    }

    // copying random pointer
    originalNode = head;
    cloneNode = cloneHead;

    while(originalNode!=NULL){

        cloneNode->random = mapping[originalNode->random];

        originalNode = originalNode->next;
        cloneNode = cloneNode->next;
    }
    return cloneHead;
}

/*
TIME COMPLEXITY : O(N)
SPACE COMPLEXITY : O(N)
*/

// ---------------------------------------------------------------------

// Approach 3
// using map logic but not map structure
Node* copyList3(Node* head){

    // step 1 : create a clone list
    Node* cloneHead = NULL;
    Node* cloneTail = NULL;

    Node* temp = head;

    while(temp!=NULL){
        insertAtTail(cloneHead,cloneTail,temp->data);
        temp = temp ->next;
    }

    // step 2 : cloneNode add in between originalNode

    Node* originaNode = head;
    Node* cloneNode = cloneHead;

    while(originaNode!=NULL && cloneNode!=NULL){
        // updating original node - links
        Node* next = originaNode->next;
        originaNode->next = cloneNode;
        originaNode = next;
        // updating clone node
        next = cloneNode->next;
        cloneNode->next = originaNode;
        cloneNode=next;
    }

    // step 3 : random pointer copy
    temp = head;

    while(temp!=NULL){
        // if(temp->next!=NULL && temp->random!=NULL){
        //     temp->next->random = temp->random->next;
        // }
        // else{
        //     temp->next = temp ->random
        // }
        // we can write above if else using ternary operator in one line 
        if(temp->next!=NULL){
            temp->next->random = temp->random?temp->random->next:temp->random;
        }
        temp=temp->next;
    }

    // step 4 : revert changes done in step 2
    originaNode = head;
    cloneNode = cloneHead;

    while(originaNode!=NULL && cloneNode!=NULL){
        // revert changes in originalNode
        originaNode->next = cloneNode->next;
        originaNode=originaNode->next;

        // revert changes in cloneNode
        cloneNode->next = originaNode;
        cloneNode=cloneNode->next; 
    }

    // step 5 : return ans
    return cloneHead;
}

/*
TIME COMPLEXITY : O(N)
SPACE COMPLEXITY : O(1)
*/




// --------------------------------------------------------------------

void printLL(Node *&head)
{
    if (head == NULL)
    {
        cout << "Linked list is empty" << endl;
    }

    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
}
int main()
{
    // first list
    Node *first = new Node(1);
    // head pointing to node1
    Node *head1 = first;
    Node *tail1 = first;
    insertAtTail(tail1, 2);
    insertAtTail(tail1, 3);
    insertAtTail(tail1, 4);
    insertAtTail(tail1, 5);

    // Approach 1
    Node* ans = copyList(head1);
    printLL(ans);

    // Approach 2
    Node* ans2 = copyList3(head1);
    printLL(ans2);

    return 0;
}
