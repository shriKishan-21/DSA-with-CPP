#include<iostream>
#include<stack>
#include<queue>
using namespace std;


// Approach 1
queue<int> rev(queue<int> q){

    // create a stack
    stack<int> s;
    // enter all the elements of queue in stack
    while(!q.empty()){
        int element = q.front();
        q.pop();
        s.push(element);
    }

    // put back all elements in queue
    while(!s.empty()){
        int element = s.top();
        s.pop();
        q.push(element);
    }

    return q;
}

// Approach 2

int main()
{
    queue<int> q;
    q.push(4);
    q.push(2);
    q.push(3);
    q.push(1);
    q.push(5);
    q.push(6);

    queue<int> ans = rev(q);

    while(!ans.empty()){
        cout<<ans.front()<<" ";
        ans.pop();
    }

    return 0;
}