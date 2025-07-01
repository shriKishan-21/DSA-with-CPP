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


// using floyd cycle detection algorithm
Node* floydCycleDetection(Node* head){
    if(head==NULL){
        return NULL;

        Node* slow = head;
        Node* fast = head;

        while(slow!=NULL && fast!=NULL){
            fast=fast->next->next;
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

// function to detect loop starting node
Node* getStartingNode(Node* head){
    if(head==NULL){
        return NULL;
    }

    // find the first intersection where fast and slow meet -- and that node will be fast
    Node* firstIntersection = floydCycleDetection(head);

    // check if firstIntersection is not null
    if(firstIntersection==NULL){
        return NULL;
    }

    // put slow at head
    Node* slow = head;

    // move slow and firstIntersection(fast) by same pase -- 1 step
    while(slow!=firstIntersection){
        slow=slow->next;
        firstIntersection=firstIntersection->next;
    }

    // they will meet at the starting node of loop
    return slow;

}

// function to remove loop in LL
void removeLoop(Node* head){
    if(head==NULL){
        return;
    }

    Node* startOfLoop = getStartingNode(head);
    
    // check if startOfLoop is not null
    if(startOfLoop==NULL){
        return;
    }

    Node* temp = startOfLoop;

    while(temp->next!=startOfLoop){
        temp=temp->next;
    }

    temp->next = NULL;
}


int main()
{
    Node* head = new Node(10);
    head->next = new Node(20); 
    head->next->next = new Node(30); 
    head->next->next->next = new Node(40); 
    head->next->next->next->next = head->next;

    // remove loop
    removeLoop(head);

    // To find starting node of cycle
    Node* node = floydCycleDetection(head);
    if(node!=NULL){
        cout<<"Cycle is present in Linked List"<<endl;
    }
    else{
        cout<<"Not Cycle is present in Linked List"<<endl;
    }



    return 0;
}