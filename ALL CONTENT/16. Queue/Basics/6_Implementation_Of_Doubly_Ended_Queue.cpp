#include<iostream>
using namespace std;


class DoublyEndedQueue{
    public:
    int *arr;
    int qfront;
    int rear;
    int size;


    DoublyEndedQueue(int n){
        size = n;
        arr = new int[size];
        qfront = -1;
        rear = -1;
    }

    bool pushfront(int x){
        // check if queue is full
        if(isFull()) {
            return false;
        }

        // first element to be push
        else if(qfront==-1){
            qfront=rear=0;
        }

        // element to be push in cyclic way
        else if(qfront==0 && rear!=size-1){
            qfront=size-1;
        }

        // else - normal puhs
        else{
            qfront--;
        }
        arr[qfront] = x;
        return true;
    }

    bool pushRear(int x){
        // check if queue is full
        if(isFull()) {
            return false;
        }

        // first element to be push
        else if(qfront==-1){
            qfront=rear=0;
        }

        // element to be push in cyclic way
        else if(rear==size-1 && qfront!=0){
            rear=0;
        }

        // else - normal puhs
        else{
            rear++;
        }
        arr[rear] = x;
        return true;
    }

    // dequeue operation
    int popfront(){
        // check if queue is empty
        if(isEmpty()){
            return -1;
        }

        // store pop element
        int ans = arr[qfront];
        arr[qfront] == -1;

        // for single element
        if(qfront==rear){
            qfront=rear=-1;
        }

        // for pop in cyclic order
        else if(qfront==size-1){
            qfront=0;
        }

        else{
            qfront++;
        }

        return ans;
    }

    int popRear(){
        // check if queue is empty
        if(isEmpty()){
            return -1;
        }

        // store pop element
        int ans = arr[rear];
        arr[rear] == -1;

        // for single element
        if(qfront==rear){
            qfront=rear=-1;
        }

        // for pop in cyclic order
        else if(rear==0){
            rear=size-1;
        }

        else{
            rear--;
        }

        return ans;
    }

    int getfront(){
        if(qfront==-1){
            return -1;
        }
        return arr[qfront];
    }

    int getRear(){
        if(qfront==-1){
            return -1;
        }
        return arr[rear];
    }

    bool isEmpty(){
        if(qfront==-1){
            return 1;
        }
        return 0;
    }

    bool isFull(){
        if((qfront==0 && rear==size-1) || (qfront!=0 && rear == (qfront-1)%(size-1))) {
            return 1;
        }
        return 0;
    }


};
int main()
{
    DoublyEndedQueue q1(5);
    
    // enqueue operation
    cout<<q1.pushfront(10)<<endl;
    cout<<q1.pushRear(20)<<endl;
    cout<<q1.pushRear(30)<<endl;
    // dequeue operation
    cout<<q1.popfront()<<endl;
    
    cout<<q1.pushRear(40)<<endl;    
    return 0;
}