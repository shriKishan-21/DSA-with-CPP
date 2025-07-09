#include<iostream>
using namespace std;


class Queue{
    private:
    int *arr;
    int qfront;
    int rear;
    int size;

    public:

    Queue(){
        size = 100001;
        arr = new int[size];
        qfront = 0;
        rear = 0;
    }

    // empty operation
    bool isEmpty(){
        if(rear==qfront){
            return true;
        }
        else{
            return false;
        }
    }

    // enqueue operation
    void enqueue(int data){
        // check if queue is full
        if(rear==size){
            cout<<"Queue is full"<<endl;
        }
        else{
            arr[rear]=data;
            rear++;
        }
    }

    // dequeue operation
    int dequeue(){
        // check if queue is empty
        if(rear==qfront){
            cout<<"Queue is empty"<<endl;
        }
        else{
            // store qfront element
            int ans = arr[qfront];
            // mark the dequeue qfront block as empty with -1
            arr[qfront]=-1;
            // move qfront
            qfront++;

            // add condition to utilize that empty space
            if(rear==qfront){
                qfront=0;
                rear=0;
            }

            return ans;
        }
    }

    // front operation
    int front(){
        if(qfront==rear){
            return -1;
        }
        else{
            return arr[qfront];
        }
    }

};
int main()
{
    Queue q1;

    // enqueue operation
    q1.enqueue(10);
    q1.enqueue(20);
    q1.enqueue(30);

    // dequeue operation
    cout<<q1.dequeue()<<endl;

    // empty operation
    cout<<q1.isEmpty()<<endl;

    // front operation;
    cout<<q1.front()<<endl;
    
}