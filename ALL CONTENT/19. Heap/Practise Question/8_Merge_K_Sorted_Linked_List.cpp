#include<iostream>
#include<stack>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;

class node{
    public:
    int val;
    node* next;

    node(int val){
        this->val = val;
        this->next = NULL;
    }
};

class compare{
    public:
    bool operator()(node* a,node* b){
        return a->val > b->val;
    }
};

node* mergeKList(vector<node*> &listArray){

    // 1. cretae a min heap with a different comparator
    priority_queue<node*,vector<node*>,compare> minHeap;

    int k = listArray.size();

    if(k==0){
        return NULL;
    }

    // 2. push first element of each LL into heap
    for(int i=0;i<k;i++){
        if(listArray[i]!=NULL){
            minHeap.push(listArray[i]);
        }
    }

    // 3. create a LL to store the merged LL
    node* head = NULL;
    node* tail = NULL;

    while(minHeap.size()>0){
        
        node* temp = minHeap.top();
        minHeap.pop();

        // 4. push the top element into LL
        if(head==NULL){
            head = temp;
            tail = temp;
        }
        else{
            tail->next = temp;
            tail = temp;
        }

        // 5. push the next element of the popped element into heap
        if(temp->next!=NULL){
            minHeap.push(tail->next);
        }
    }

    return head;
}

int main(){

    vector<node*> listArray = {new node(1),new node(1),new node(2)};
    listArray[0]->next = new node(4);
    listArray[0]->next->next = new node(5);
    listArray[1]->next = new node(3);
    listArray[1]->next->next = new node(4);
    listArray[2]->next = new node(6);

    node* head = mergeKList(listArray);

    while(head!=NULL){
        cout<<head->val<<"->";
        head = head->next;
    }
    cout<<endl;
    
    return 0;
}
