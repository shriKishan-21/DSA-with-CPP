#include<bits/stdc++.h>
using namespace std;


class Node{
    public:
    int data;
    Node* next;

    Node(int data){
        this->data=data;
        this->next = NULL;

    }
    Node(int data, Node* next){
        this->data=data;
        this->next = next;
    }
};

// Aproach 1
bool detectLoop(Node* head){
    // empty list
    if(head==NULL){
        return true;
    }

    // use map to store the address of nodes and check if any node is visited twice
    map<Node*, bool> visited;

    Node* temp = head;

    while(temp!=NULL){
        // if node is alreay visited -- cycle is present
        if(visited[temp]==true){
            return true;
        } 
        // otherwise mark it as visited
        visited[temp]=true;
        temp=temp->next;
    }

    return false;

}

// Approach 2 -- using floyd cycle detection algorithm
Node* floydCycleDetection(Node* head){
    if(head==NULL){
        return NULL;

        Node* slow = head;
        Node* fast = head;

        while(slow!=NULL && fast!=NULL){
            fast=fast->next;
            if(fast!=NULL){
                fast=fast->next;
            }
            slow=slow->next;

            // if both are pointing to same node -- cycle is present
            if(slow==fast){
                return slow;
            }
        }

        // comes out of loop -- cycle is not present
        return NULL;
    }
}
int main()
{
    Node* head = new Node(10);
    head->next = new Node(20); 
    head->next->next = new Node(30); 
    head->next->next->next = new Node(40); 
    head->next->next->next->next = head; 

    // Approach 1
    if(detectLoop(head)){
        cout<<"Cycle is present in Linked List"<<endl;
    }
    else{
        cout<<"Not Cycle is present in Linked List"<<endl;
    }

    // Approach 2
    Node* node = floydCycleDetection(head);
    if(node!=NULL){
        cout<<"Cycle is present in Linked List"<<endl;
        cout<<"Node is : "<<node->data<<endl;
    }
    else{
        cout<<"Not Cycle is present in Linked List"<<endl;
    }


    return 0;
}