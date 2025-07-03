
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
bool checkPalindrome(vector<int> arr){
    int i = 0;
    int j =arr.size()-1;
    while(i<=j){
        if(arr[i]!=arr[j]){
            return false;
        }
        else{
            i++;
            j--;
        }
    }
    return true;
}
bool isPalindrome(Node* head){
    Node* temp = head;
    // creating an array
    vector<int> arr;

    while(temp!=NULL){
        arr.push_back(temp->data);
        temp=temp->next;
    }

    return checkPalindrome(arr);
}

// --------------------------------------------------------------------

// Approach 2
// Optimised approach

// function to find middle
Node* findMiddle(Node* head){
    Node* slow = head;
    Node* fast = head->next;

    while(fast!=NULL && fast->next!=NULL){
        fast=fast->next->next;
        slow=slow->next;
    }

    return slow;
}
// function to reverse
Node* reverse(Node* head){
    Node* prev = NULL;
    Node* curr = head;
    Node* forward = NULL;
 
    while(curr!=NULL){
        forward = curr->next;
        curr->next = prev;
        prev = curr;
        curr = forward;
    }

    return prev;
}

bool isPalindrome2(Node* head){
    // if head is null
    if(head == NULL){
        return true;
    }

    // step 1 : find middle
    Node* middle = findMiddle(head);

    // step 2 : reverse LL after middle
    Node* temp = middle->next;
    middle->next = reverse(temp);

    // step 3 : compare both halves
    Node* head1 = head;
    Node* head2 = middle->next;

    while(head2!=NULL){
        if(head1->data!=head2->data){
            return false;
        }
        head1 = head1->next;
        head2 = head2->next;
    }

    // step 4 - reverse LL again back to original
    temp = middle->next;
    middle->next = reverse(temp);

    return true;
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
    insertAtTail(tail1, 2);
    insertAtTail(tail1, 1);

    cout<<isPalindrome(first)<<endl; 
    
    // first list
    Node *second = new Node(1);
    // head pointing to node1
    Node *head2 = second;
    Node *tail2 = second;
    insertAtTail(tail2, 2);
    insertAtTail(tail2, 3);
    insertAtTail(tail2, 3);
    insertAtTail(tail2, 2);
    insertAtTail(tail2, 1);


    cout<<isPalindrome2(second)<<endl;
    return 0;
}
