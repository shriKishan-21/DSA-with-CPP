#include<iostream>
#include<queue>
#include<stack>
using namespace std;


void interleave(queue<int> &q , int n){
    // create a stack
    stack<int> s;

    // Put first half element in stack
    for(int  i=0; i<(n/2); i++){
        int val = q.front();
        q.pop();
        s.push(val);
    }

    // Again insert the stack value in the end of queue
    while(!s.empty()){
        int val = s.top();
        s.pop();
        q.push(val);
    }

    // put first half of queue in the back
    for(int i=0 ; i<(n/2) ; i++){
        int val = q.front();
        q.pop();
        q.push(val);
    }

    // Again put the first half of queue in stack
    for(int i=0 ; i<(n/2) ; i++){
        int val = q.front();
        q.pop();
        s.push(val);
    }

    // Now compare both stack and queue and interleave
    while(!s.empty()){
        // first push first element of stack into queue
        int val = s.top();
        s.pop();
        q.push(val);
        
        // now push first element of queue into queue
        val = q.front();
        q.pop();
        q.push(val);
    }
}

int main()
{
    queue<int> q;
    q.push(11);
    q.push(12);
    q.push(13);
    q.push(14);
    q.push(15);
    q.push(16);
    q.push(17);
    q.push(18);

    interleave(q,8);

    for(int i=0;i<8;i++){
        cout<<q.front()<<" ";
        q.pop();
    }

    return 0;
}