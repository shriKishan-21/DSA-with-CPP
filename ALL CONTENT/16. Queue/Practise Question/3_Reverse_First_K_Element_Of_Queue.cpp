#include<iostream>
#include<stack>
#include<queue>
using namespace std;


queue<int> modifyQueue(queue<int> q,int k){
    // step 1 : pop first k element from queue ans put into stack
    stack<int> s;

    for(int i=0;i<k;i++){
        int val = q.front();
        q.pop();
        s.push(val);
    }

    // step 2 : fetch from stack and push into q
    while(!s.empty()){
        int val = s.top();
        s.pop();
        q.push(val);
    }

    // step 3 : fetch first n-k elements from q and push back into q
    int t = q.size() - k;

    while(t--){
        int val = q.front();
        q.pop();
        q.push(val);
    }

    return q;
}
int main()
{
    queue<int> q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);

    int k = 3;

    queue<int> ans = modifyQueue(q,k);

    while(!ans.empty()){
        cout<<ans.front()<<" ";
        ans.pop();
    }

    return 0;
}