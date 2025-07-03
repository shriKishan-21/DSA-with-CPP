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

// Approach 1
Node* uniqueSortedList1(Node* head){
    // empty List
    if(head==NULL){
        return NULL;
    }

    // non empty list
    Node* curr = head;

    while(curr!=NULL){
        Node* temp = curr->next;

        while(temp!=NULL){
            if(temp->data==curr->data){
                Node* nodeToDelete = temp;
                temp = temp->next;
                curr->next = temp;
                delete nodeToDelete;
            }
            else{
                temp = temp->next;
            }
        }
        curr = curr->next;
    }

    return head;
}

// Approach 2
Node* uniqueSortedList2(Node *head) {
    unordered_set<int> hashSet;
    Node *curr = head;
    Node *prev = NULL;

    while (curr != NULL) {

        // Check if the element is already in the hash table
        if (hashSet.find(curr->data) != hashSet.end()) {

            // Element is present, remove it
            prev->next = curr->next;

            // Delete the curr node
            Node *temp = curr;
            curr = curr->next;
            delete temp;
        }
        else {

            // Element is not present, add it to hash table
            hashSet.insert(curr->data);
            prev = curr;
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

    Node* newHead = uniqueSortedList1(first);
    print(newHead);

    cout<<endl;

    // second list
    Node *second = new Node(3);
    // head pointing to node1
    Node *head2 = second;
    Node *tail2 = second;
    insertAtTail(tail2, 3);
    insertAtTail(tail2, 4);
    insertAtTail(tail2, 6);
    insertAtTail(tail2, 4);
    insertAtTail(tail2, 3);
    insertAtTail(tail2, 6);

    Node* newHead2 = uniqueSortedList2(second);
    print(newHead2);

    return 0;
}