
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
Node* sortList(Node* head){
    // to count every 0s,1s,2s
    int zeroCount = 0;
    int oneCount = 0;
    int twoCount = 0;

    Node* temp = head;

    // to calculate the count of 0s,1s,2s
    while(temp!=NULL){
        if(temp->data==0){
            zeroCount++;
        }
        else if(temp->data==1){
            oneCount++;
        }
        else if(temp->data==2){
            twoCount++;
        }
        temp=temp->next;
    }

    // bring temp to head
    temp = head;

    // replace element in LL with sorted 0s,1s,2s
    while(temp!=NULL){
        if(zeroCount!=0){
            temp->data=0;
            zeroCount--;
        }
        else if(oneCount!=0){
            temp->data=1;
            oneCount--;
        }
        else if(twoCount!=0){
            temp->data=2;
            twoCount--;
        }
        temp=temp->next;
    }
    return head;
}


// --------------------------------------------------------------------

void populate(Node* &tail,Node* curr){
    tail->next = curr;
    tail=curr;
}

// Approach 2
Node* sortList2(Node* head){
    // create dummy node for 1s,2s,3s
    Node* zeroHead = new Node(-1);
    Node* zeroTail = zeroHead;
    Node* oneHead = new Node(-1);
    Node* oneTail = oneHead;    
    Node* twoHead = new Node(-1);
    Node* twoTail = twoHead;

    Node* curr = head;

    // create separate list for 0s,1s,2s
    while(curr!=NULL){
        int value = curr->data;

        // if value is 0 -- put it in 0 list
        if(value==0){
            populate(zeroTail,curr);
        }
        // if value is 1 -- put it in 1 list
        if(value==1){
            populate(oneTail,curr);
        }
        // if value is 2 -- put it in 2 list
        if(value==2){
            populate(twoTail,curr);
        }
        curr=curr->next;
    }

    // merge
    // check -- 1s list is not empty
    if(oneHead->next!=NULL){
        // put 0s list
        zeroTail->next = oneHead->next;
    }
    else{
        // 1s is empty
        // put 0s in 2s
        zeroTail->next = twoHead->next;
    }

    // put 1s in 2s
    oneTail->next = twoHead->next;
    // point 3s tail to NULL
    twoTail->next = NULL;

    // setup Head
    head = zeroHead->next;

    // deleted dummy node
    delete zeroHead;
    delete oneHead;
    delete twoHead;

    return head;
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
    Node *node1 = new Node(1);

    // head pointing to node1
    Node *head1 = node1;
    Node *tail1 = node1;

    insertAtTail(tail1, 0);
    insertAtTail(tail1, 2);
    insertAtTail(tail1, 1);
    insertAtTail(tail1, 2);
    printLL(head1);
    cout << endl;

    Node* sorted1 = sortList(head1);
    printLL(sorted1);
    cout<<endl;
    
    // For Approach 2
    Node *node2 = new Node(1);
    // head pointing to node1
    Node *head2 = node2;
    Node *tail2 = node2;
    insertAtTail(tail2, 2);
    insertAtTail(tail2, 0);
    insertAtTail(tail2, 1);
    insertAtTail(tail2, 0);
    printLL(head2);
    cout << endl;


    Node *sorted2 = sortList2(head2);
    printLL(sorted2);
    cout<<endl;

    return 0;
}
