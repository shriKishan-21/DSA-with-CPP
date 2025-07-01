
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

Node* solve(Node* first,Node* second){
    // smallest first element list will be considered first here and other second depending upon arguments

    // solve separately if only one node is present in first -- as it will never enter while loop
    if(first->next == NULL){
        first->next = second;
        return first;
    }
    
    Node* curr1 = first;
    Node* curr2 = second;
    Node* next1 = curr1->next;
    // to keep track of node in second after node is remove
    Node* next2 = curr2->next;

    // move until curr is not null for both list
    while(next1!=NULL && curr2!=NULL){
        // check if curr2->value is suitable to insert between curr1 and next1 -- if yes
        if((curr2->data>=curr1->data) && (curr2->data <= next1->data)){
            // add node to first list
            curr1->next = curr2;
            next2 = curr2->next;
            curr2->next=next1;
            
            // update pointers
            curr1 = curr2;
            curr2 = next2;
        }
        else{
            // if no
            // move next1 and curr1 to next
            curr1 = next1;
            next1 = next1->next;

            // lets check if next1 is null -- first list is finish -- so well point it to the remaining of list 2
            if(next1==NULL){
                curr1->next = curr2;
                return first;
            }
        }
        return first;
    }
}
// Approach 1
Node* sortTwoList(Node* first,Node* second){
    // if first is empty return second
    if(first==NULL){
        return second;
    }
    // if second is empty return first
    if(second==NULL){
        return first;
    }

    // choose the list to merge with smallest first value
    if(first->data <= second->data){
        return solve(first,second);
    }
    else{
        return solve(second,first);
    }

    
}


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
    insertAtTail(tail1, 3);
    insertAtTail(tail1, 5);
    //second list
    Node* second = new Node(2);
    // head pointing to new node
    Node* head2 = second;
    Node* tail2 = second;
    insertAtTail(tail2, 4);
    insertAtTail(tail2, 5);
    printLL(head1);
    cout<<endl;
    printLL(head2);
    cout << endl;

    Node* sorted = sortTwoList(first,second); 
    printLL(sorted);
    cout<<endl;
    
    return 0;
}
