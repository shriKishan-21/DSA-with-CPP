#include<iostream>
#include<queue>
using namespace std;

int main()
{
    // create queue
    queue<int> q;

    // push operation
    q.push(11);
    q.push(15);
    q.push(13);

    // size operation
    cout<<"Size of queue is : "<<q.size()<<endl;

    // pop operation
    q.pop();

    // empty operation
    if(q.empty()){
        cout<<"Queue is empty "<<endl;
    }
    else{
        cout<<"Queue is not empty"<<endl;
    }

    // front element
    cout<<"Element in front is : "<<q.front()<<endl;

    return 0;

}