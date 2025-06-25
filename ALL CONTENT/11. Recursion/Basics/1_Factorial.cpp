#include<bits/stdc++.h>
using namespace std;

/*
 Factorial -->
 5! = s*4*3*2*1
    = 5 * 4!

 so, 5! = 5 * 4!
 --> n! = n * (n-1)!
    n! : big problem
    (n-1)! : small problem

 Recurrence Relation : f(n) = n * f(n-1)
*/

int factorial(int n){
    // Base case
    // base case is the stopping condition in recursion
    if (n==0){
        return 1;
    }

    /*
    f(n) = n * f(n-1)
    f(n) = large && f(n-1) = small
    int small = factorial(n-1);
    int large = n * small;

    return large;
    */

    // we directly write 
    return n * factorial(n-1);
}
int main()
{
    int n;
    cin>>n;

    int ans = factorial(n);

    cout<<ans<<endl;
}