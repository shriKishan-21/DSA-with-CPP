
#include <bits/stdc++.h>
using namespace std;

class Node
{

public:
    int data;
    Node* next;
    Node* child;

    // constructor
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
        this->child = NULL;
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


Node* flattenLL(Node* head){

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
    Node *first = new Node(3);
    // head pointing to node1
    Node *head1 = first;
    Node *tail1 = first;
    insertAtTail(tail1, 5);
    insertAtTail(tail1, 2);
    insertAtTail(tail1, 1);
    insertAtTail(tail1, 2);
    insertAtTail(tail1, 9);


    // Approach 1
    Node* ans = flattenLL(head1);
    printLL(ans);

    return 0;
}
