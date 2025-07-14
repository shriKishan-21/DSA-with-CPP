#include<iostream>
#include<queue>
using namespace std;



int main()
{
    // using priority queue
    // priority queue is used to create a max heap or min heap
    // need to include head file <queue> to use priority queue

    // 1. max heap -- default -- stores elements in increasing order
    priority_queue<int> pq;
    pq.push(1);
    pq.push(2);
    pq.push(3);
    pq.push(4);
    pq.push(5);

    cout<<"MAX HEAP USING PRIORITY QUEUE: "<<endl;
    while(!pq.empty())
    {
        cout<<pq.top()<<" ";
        pq.pop();
    }
    cout<<endl;


    // 2. min heap -- stores elements in decreasing order
    priority_queue<int,vector<int>,greater<int>> pq1;
    pq1.push(1);
    pq1.push(2);
    pq1.push(3);
    pq1.push(4);
    pq1.push(5);

    cout<<"MIN HEAP USING PRIORITY QUEUE: "<<endl;
    while(!pq1.empty())
    {
        cout<<pq1.top()<<" ";
        pq1.pop();
    }
    cout<<endl;

    
    
    return 0;

}