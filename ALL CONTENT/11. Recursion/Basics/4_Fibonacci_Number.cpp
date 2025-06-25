// Fibonacci Number is a series -->
// 0 , 1 , 1 , 2 , 3 , 5 , 8 , 13 , 21 , 34 , 55 , 89 , 144 , 233 , 377 , 610 , ........


#include<bits/stdc++.h>
using namespace std;


int fib(int n)
{
    // base case
    if(n == 0) return 0;
    if(n == 1) return 1;

    // recurrence relation
    // f(n) = f(n-1) + f(n-2);
    return fib(n-1) + fib(n-2);
}
int main()
{
    int n;
    cin >> n;

    int ans = fib(n);
    cout << ans << endl;

    return 0;

}