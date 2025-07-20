
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

// Reverse the LL
Node* reverse(Node* &head){

    Node* curr = head;
    Node* prev = NULL;
    Node* forward = NULL;

    while(curr!=NULL){
        forward=curr->next;
        curr->next=prev;
        prev=curr;
        curr=forward;
    }
    return prev;
}

// create LL
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

// Add 2 LL
Node* add(Node* &first,Node* &second){
    // carry 
    int carry = 0;

    // store head and tail of ans node
    Node* ansHead = NULL;
    Node* ansTail = NULL;

    // optimised while loop that can handle all condition
    // 1. if first and second length is same
    // 2. if first is larger than second
    // 3. if second is larger than first
    // 4. if carry is still remaining after adding all nodes
    while(first!=NULL || second!=NULL || carry!=0){
        // store first value
        int val1 = 0;
        if(first!=NULL){
            val1 = first->data;
        }
        // store second value
        int val2 = 0;
        if(second!=NULL){
            val2=second->data;
        }

        // sum = carry + first + second
        int sum = carry + val1 + val2;
        // value to insert in LL -- last digit of value
        int digit = sum%10;
        // create LL
        insertAtTail(ansHead,ansTail,digit);
        // calculate carry 
        carry = sum/10;

        // move first ans second node
        if(first!=NULL){
            first = first->next;
        }
        if(second!=NULL){
            second=second->next;
        }
    } 
    return ansHead;
}

Node* addTwoLists(Node* first, Node* second) {
    
    // Step 1 : reverse input LL
    first = reverse(first);
    second = reverse(second);

    //step 2 : Add LL
    Node* ans = add(first,second);

    // step 3 : Reverse ans
    ans = reverse(ans);

    return ans;
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
    insertAtTail(tail1, 4);
    
    // second list
    Node *second = new Node(2);
    // head pointing to node1
    Node *head2 = second;
    Node *tail2 = second;
    insertAtTail(tail2, 3);
    insertAtTail(tail2, 0);
    
    Node* ans = addTwoLists(first,second);
    printLL(ans);


    return 0;
}
