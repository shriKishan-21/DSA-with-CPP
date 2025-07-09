#include<iostream>
using namespace std;


class CircularQueue{
    private:
    int *arr;
    int qfront;
    int rear;
    int size;

    public:

    CircularQueue(int n){
        size = n;
        arr = new int[size];
        qfront = rear = -1;
    }

    // enqueue operation -- return true if data can be push else return -1
    bool enqueue(int data){
        // check if queue is full
        if((qfront==0 && rear==size-1) || (rear == (qfront-1)%(size-1))) {
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
        arr[rear] = data;
        return true;
    }

    // dequeue operation
    int dequeue(){
        // check if queue is empty
        if(qfront==-1){
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


};
int main()
{
    CircularQueue q1(3);

    // enqueue operation
    cout<<q1.enqueue(10)<<endl;
    cout<<q1.enqueue(20)<<endl;
    cout<<q1.enqueue(30)<<endl;
    // dequeue operation
    cout<<q1.dequeue()<<endl;

    cout<<q1.enqueue(40)<<endl;    
}