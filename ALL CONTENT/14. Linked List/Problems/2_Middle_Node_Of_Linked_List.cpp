
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

    // Destructor
    ~Node()
    {
        // value is just to check which node is deleted
        int value = this->data;

        // memory free
        while (this->next != NULL)
        {
            delete next;
            this->next = NULL;
        }

        cout << "Memory is for node with data : " << value << endl;
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
int findLength(Node* head){
    int len = 0;

    while(head!=NULL){
        len++;
        head=head->next;
    }
    return len;
}

Node *findMiddle(Node* head) {
    int len = findLength(head);
    int position = len/2;

    Node* temp = head;
    int count=0;
    while(count<position){
        temp=temp->next;
        count++;
    }

    return temp;
}


// --------------------------------------------------------------------

// Optimized Approach
// Using fast and slow pointers
Node *findMiddle2(Node *head) {
    // Write your code here
    // for empty and 1 node LL
    if(head==NULL || head->next==NULL){
        return head;
    }

    Node* slow = head;
    Node* fast = head->next;
    
    while(fast!=NULL){
        fast=fast->next;
        if(fast!=NULL){
            fast=fast->next;
        }
        slow=slow->next;
    }

    return slow;
}

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
    Node *node1 = new Node(10);

    // head pointing to node1
    Node *head1 = node1;
    Node *tail1 = node1;

    insertAtTail(tail1, 12);
    insertAtTail(tail1, 15);
    insertAtTail(tail1, 18);
    insertAtTail(tail1, 21);
    printLL(head1);
    cout << endl;

    Node* middle1 = findMiddle(head1);
    cout<<middle1->data;
    cout<<endl;
    
    // For Approach 2
    Node *node2 = new Node(50);
    // head pointing to node1
    Node *head2 = node2;
    Node *tail2 = node2;
    insertAtTail(tail2, 52);
    insertAtTail(tail2, 55);
    insertAtTail(tail2, 58);
    insertAtTail(tail2, 61);
    printLL(head2);
    cout << endl;


    Node *middle2 = findMiddle2(head2);
    cout<<middle2->data;
    cout<<endl;

    return 0;
}
