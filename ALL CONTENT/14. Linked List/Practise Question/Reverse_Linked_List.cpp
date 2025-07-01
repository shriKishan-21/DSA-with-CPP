#include<iostream>
#include <bits/stdc++.h>
using namespace std;

// Following is the class structure of the LinkedListNode class:

template <typename T>
class LinkedListNode
{
public:
    T data;
    LinkedListNode<T> *next;
    LinkedListNode(T data)
    {
        this->data = data;
        this->next = NULL;
    }
};

// ---------------------------------------------------------------------------
// Approach 1 :
// Iterative approach
LinkedListNode<int> *reverseLinkedList1(LinkedListNode<int> *head)
{
    // if we have empty LL or one node LL
    if (head == NULL)
    {
        return head;
    }

    // else
    LinkedListNode<int> *prev = NULL;
    LinkedListNode<int> *curr = head;
    LinkedListNode<int> *forward = NULL;

    while (curr != NULL)
    {
        forward = curr->next;
        curr->next = prev;
        prev = curr;
        curr = forward;
    }

    return prev;
    
}

// ------------------------------------------------------------------------------

// Approach 2 :
// Recursive approach
LinkedListNode<int> *reverse(LinkedListNode<int>* &head,LinkedListNode<int> *curr,LinkedListNode<int> *prev){
    // base case
    if(curr==NULL){
        head = prev;
        return head;
    }

    // 1 cas solve
    LinkedListNode<int> *position = curr->next;

    // recursive call
    reverse(head,position,curr);

    curr->next = prev;
}

LinkedListNode<int> *reverseLinkedList2(LinkedListNode<int> *head)
{
    LinkedListNode<int> *prev = NULL;
    LinkedListNode<int> *curr = head;
    reverse(head,curr,prev);

    return head;
}

//--------------------------------------------------------------------------------------

// Approach 3
// using recursion
LinkedListNode<int> *reverse1(LinkedListNode<int> *head){
    // base case 
    if(head==NULL || head->next==NULL){
        return head;
    }

    // head of revesed LL
    // reverse1(head->next) will reverse the LL
    LinkedListNode<int> *smallHead = reverse1(head->next);

    // solve 1 case
    head->next->next = head;
    head->next=NULL;

    return smallHead;
}

LinkedListNode<int> *reverseLinkedList3(LinkedListNode<int> *head)
{
    reverse1(head);

    return head;
}

// -----------------------------------------------------------------------

// print the linked list
void print(LinkedListNode<int>* &head){
    LinkedListNode<int> *temp = head;

    while(temp != NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}

// -------------------------------------------------------------------------

int main()
{

    // For Approach 1
    LinkedListNode<int> *node = new LinkedListNode<int>(1);
    node->next = new LinkedListNode<int>(2);
    node->next->next = new LinkedListNode<int>(3);
    node->next->next->next = new LinkedListNode<int>(4);
    node->next->next->next->next = new LinkedListNode<int>(5);

    LinkedListNode<int> *head = reverseLinkedList1(node);
    print(head);

    // For Approach 2
    LinkedListNode<int> *node1 = new LinkedListNode<int>(1);
    node1->next = new LinkedListNode<int>(2);
    node1->next->next = new LinkedListNode<int>(3);
    node1->next->next->next = new LinkedListNode<int>(4);
    node1->next->next->next->next = new LinkedListNode<int>(5);

    LinkedListNode<int> *head1 = reverseLinkedList2(node1);
    print(head1);   
    
    // For Approach 3
    LinkedListNode<int> *node2 = new LinkedListNode<int>(1);
    node2->next = new LinkedListNode<int>(2);
    node2->next->next = new LinkedListNode<int>(3);
    node2->next->next->next = new LinkedListNode<int>(4);
    node2->next->next->next->next = new LinkedListNode<int>(5);

    LinkedListNode<int> *head2 = reverseLinkedList3(node2);
    print(head2);  

    return 0;
}
