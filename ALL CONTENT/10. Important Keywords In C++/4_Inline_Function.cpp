// Inline function are used to reduce the function call overhead
// Inline function are same as macro in working ,
// The function call are replaced by the function body at compile time
#include<bits/stdc++.h>
using namespace std;

// Inline function
inline int getMax(int& a , int& b){
    return (a>b)?a:b;
}
int main()
{
    int a = 1,b = 2;
    int ans = 0;

    ans = getMax(a,b);
    cout<<"Maximum of "<<a<<" and "<<b<<" is "<<ans<<endl;

    a = a + 3;
    b = b + 1;

    ans = getMax(a,b);
    cout<<"Maximum of "<<a<<" and "<<b<<" is "<<ans<<endl;

    return 0;
}

// Why to use inline function -->
// 1. No extra memory usage
// 2. No function call overhead