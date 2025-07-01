#include<bits/stdc++.h>
using namespace std;

class Node{
    
    public:
    int data;
    Node* next;

    // constructor
    Node(int data){
        this->data = data;
        this->next = NULL;
    }
};
 
int main()
{
    Node* head = new Node(10);
    return 0;
}