#include<bits/stdc++.h>
using namespace std;


int countDistinctWays(int nStairs) {
    // base case
    if(nStairs<0) return 0;
    if(nStairs==0) return 1;

    // recurrence relation
    // f(n) = f(n-1) + f(n-2);
    // to reach nth stari either well jump from (n-1)th stair or from (n-2)th stair
    return countDistinctWays(nStairs-1)+countDistinctWays(nStairs-2);
}
int main()
{
    int nStairs;
    cin>>nStairs;
    cout<<countDistinctWays(nStairs);

}

// To complete this code we still need dynamic programming which will be covered further
