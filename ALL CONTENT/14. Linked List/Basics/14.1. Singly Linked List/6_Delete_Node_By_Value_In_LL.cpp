
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
//---------------------------------------------------------------------

// function to delete node in LL
void deleteNode(int value, Node *&head, Node *&tail)
{
    // deleting first or start node (head)
    if (value == head->data)
    {
        Node *temp = head;
        head = head->next;
        delete (temp);
    }
    else
    {
        // deleting an middle or last node(tail)
        Node *curr = head;
        Node *prev = NULL;
        int count = curr->data;

        while (count < value)
        {
            prev = curr;
            curr = curr->next;
            count=curr->data;
        }

        // case to handle tail
        if (curr->next == NULL)
        {
            tail = prev;
        }
        prev->next = curr->next;
        curr->next = NULL;
        // free memory
        delete curr;
    }
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
    Node *head = node1;
    Node *tail = node1;

    insertAtTail(tail, 12);
    insertAtTail(tail, 15);
    insertAtTail(tail, 18);
    insertAtTail(tail, 21);
    printLL(head);
    cout << endl;

    deleteNode(12,head,tail);
    printLL(head);

    return 0;
}