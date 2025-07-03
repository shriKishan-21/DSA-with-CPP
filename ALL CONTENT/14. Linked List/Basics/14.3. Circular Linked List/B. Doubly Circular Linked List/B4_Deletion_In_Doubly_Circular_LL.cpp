#include<iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node* prev;

    // Constructor
    Node(int data) {
        this->data = data;
        this->next = NULL;
        this->prev = NULL;
    }

    // Destructor
    ~Node() {
        int value = this->data;
        if(this->next != NULL) {
            delete next;
            this->next = NULL;
        }
        cout << "Memory is free for Node with data " << value << endl;
    }
};

void insertNode(Node*& tail, int element, int d) {
    // Empty list
    if(tail == NULL) {
        Node* newNode = new Node(d);
        newNode->next = newNode;
        newNode->prev = newNode;
        tail = newNode;
    }
    else {
        // Non-empty list: find the node with 'element'
        Node* curr = tail;
        do {
            if(curr->data == element) break;
            curr = curr->next;
        } while(curr != tail);

        // Insert after curr
        Node* newNode = new Node(d);

        newNode->next = curr->next;
        newNode->prev = curr;

        curr->next->prev = newNode;
        curr->next = newNode;

        // Optionally update tail if we want to maintain tail at last inserted
        // For your style, update tail if inserting after tail
        if(curr == tail) {
            tail = newNode;
        }
    }
}

void deleteNode(Node*& tail, int value) {
    // Empty list
    if(tail == NULL) {
        cout << "List is empty" << endl;
        return;
    }

    Node* curr = tail;
    Node* target = NULL;

    // Search for the node to delete
    do {
        if(curr->data == value) {
            target = curr;
            break;
        }
        curr = curr->next;
    } while(curr != tail);

    // Not found
    if(target == NULL) {
        cout << "Value " << value << " not found in the list" << endl;
        return;
    }

    // Only one node in the list
    if(target->next == target && target->prev == target) {
        tail = NULL;
    }
    else {
        // Unlink target node
        target->prev->next = target->next;
        target->next->prev = target->prev;

        // Update tail if needed
        if(target == tail) {
            tail = target->prev;
        }
    }

    // Break links
    target->next = NULL;
    target->prev = NULL;
    delete target;
}

void print(Node* tail) {
    if(tail == NULL) {
        cout << "List is empty" << endl;
        return;
    }

    Node* head = tail->next;
    Node* temp = head;

    do {
        cout << temp->data << " ";
        temp = temp->next;
    } while(temp != head);

    cout << endl;
}

void printReverse(Node* tail) {
    if(tail == NULL) {
        cout << "List is empty" << endl;
        return;
    }

    Node* temp = tail;

    do {
        cout << temp->data << " ";
        temp = temp->prev;
    } while(temp != tail);

    cout << endl;
}

int main() {
    Node* tail = NULL;

    insertNode(tail, 0, 10);     // list empty, first node
    insertNode(tail, 10, 12);
    insertNode(tail, 12, 15);
    insertNode(tail, 15, 18);
    insertNode(tail, 18, 21);

    cout << "List forward: ";
    print(tail);

    cout << "List backward: ";
    printReverse(tail);

    cout << endl << "Deleting 12..." << endl;
    deleteNode(tail, 12);

    cout << "List forward after deletion: ";
    print(tail);

    cout << "List backward after deletion: ";
    printReverse(tail);

    return 0;
}
