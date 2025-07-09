#include<iostream>
#include<queue>
using namespace std;

int main()
{
    deque<int> dq;

    // push elements in the queue
    dq.push_front(10); // push 10 in the queue
    dq.push_back(20); // push 20 in the queue

    // print the first and second
    cout<<dq.front()<<endl; // print 10
    cout<<dq.back()<<endl; // print 20

    // pop the element
    dq.pop_front(); // pop 10 from the queue
    dq.pop_back(); // pop 20 from the queue

    // empty operation
    if(dq.empty()){
        cout<<"Queue is empty "<<endl;
    }
    else{
        cout<<"Queue is not empty"<<endl;
    }

    return 0;
}