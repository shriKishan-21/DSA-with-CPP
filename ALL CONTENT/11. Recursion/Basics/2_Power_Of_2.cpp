// Recursive code to calculate the power of 2 i.e. 2^n
#include<bits/stdc++.h>
using namespace std;


int power(int n){
    // base case
    if(n==0){
        return 1;
    }
    /*
    recurrence relation
    f(n) = 2 * f(n-1)
    f(n) = big problem && f(n-1) = small problem
    int smallProblem = power(n-1);
    int biggerProblem = 2 * smallProblem;

    return biggerProblem;
    */

    return 2 * power(n-1);
}
int main()
{
    int n;
    cin>>n;

    int ans = power(n);

    cout<<ans<<endl;
}