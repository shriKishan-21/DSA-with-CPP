#include<iostream>
#include<stack>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;


long long minCost(long long arr[], long long n)
{
    // create min heap
    priority_queue<long long, vector<long long>, greater<long long>> pq;

    for(int i=0; i<n; i++){
        pq.push(arr[i]);
    }

    long long cost = 0;

    while(pq.size()> 1){
        // 1. choose first two min element
        long long a = pq.top();
        pq.pop();
        long long b = pq.top();
        pq.pop();

        // 2. calculate their sum
        long long sum = a + b;

        // 3. update min cost
        cost += sum;

        // 4. push back sum into pq
        pq.push(sum);
    }

    return cost;
}

int main()
{
    long long arr[] = {4, 3, 2, 6};
    long long n = 4;
    cout << minCost(arr, n) << endl;
    return 0;

}
