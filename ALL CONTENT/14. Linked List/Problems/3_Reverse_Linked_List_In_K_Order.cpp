#include<bits/stdc++.h>
using namespace std;


class Node{
    public:
    int data;
    Node* next;
    Node(int data){
        this->data=data;
        this->next=NULL;
    }

};

// Approach 1 -- using recursion
Node* kReverse(Node* head,int k){
    // basec case
    if(head==NULL){
        return NULL;
    }

    // step 1 : reverse first k nodes
    Node* forward = NULL;
    Node* curr = head;
    Node* prev = NULL;
    int count = 0;

    while(count<k && curr!=NULL){
        forward = curr->next;
        curr->next = prev;
        prev = curr;
        curr = forward;
        count++;
    }

    // Step 2 : recursive call
    if(forward!=NULL){
        head->next = kReverse(forward,k);
    }

    // Step 3 : return head of reversed LL
    return prev;

}

void print(Node* &head){
    Node* temp = head;
    if(temp==NULL){
        cout<<"List is empty";
        return;
    }
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}

int main()
{
    Node* head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(30);
    head->next->next->next = new Node(40);
    head->next->next->next->next = new Node(50);
    head->next->next->next->next->next = new Node(60);

    int k = 2;
    Node* newHead = kReverse(head,k);
    print(newHead);
    return 0;
}