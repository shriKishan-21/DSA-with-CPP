#include<iostream>
using namespace std;

class KQueue{

    public:
    int n;
    int k;
    int *front;
    int *rear;
    int *arr;
    int freespot;
    int *next;

    public:
    KQueue(int n,int k){
        this->n = n;
        this->k = k;
        front = new int[k];
        rear = new int[k];
        arr = new int[n];
        next = new int[n];

        // initialize front and rear
        for(int i=0 ; i<k ; i++){
            front[i] = -1;
            rear[i] = -1;
        }

        // initialize next
        for(int i=0 ; i<n ; i++){
            next[i] = i+1;
        }

        // last element of next arr
        next[n-1] = -1;

        // freespot
        freespot = 0;

    }

    // enqueue
    void enqueue(int data , int qn){

        // overflow
        if(freespot==-1){
            cout<<"Queue is full"<<endl;
            return ;
        }

        // find first free index
        int index = freespot;
        
        // check whether first element
        if(front[qn-1]==-1){
            front[qn-1]=index;
        }
        else{
            // link new element to the prev element
            next[rear[qn-1]] = index;
        }

        // update
        next[index] = -1;

        // update rear
        rear[qn-1] = index;

        // push element
        arr[index] = data;
    }

    // dequeue
    int dequeue(int qn){
        // underflow
        if(front[qn-1]==-1){
            cout<<"empty queue"<<endl;
        }

        // find index to pop
        int index = front[qn-1];

        // move front ahead
        front[qn-1] = next[index];

        // Manage freeslots
        next[index] = freespot;
        
        freespot = index;

        return arr[index];
    }
};


int main()
{
    KQueue kq(8,3);
    kq.enqueue(5,1);
    kq.enqueue(6,1);

    cout<<kq.dequeue(1);

    return 0;
    
}