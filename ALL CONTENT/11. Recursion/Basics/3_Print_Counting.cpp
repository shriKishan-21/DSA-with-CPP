#include<bits/stdc++.h>
using namespace std;

void print(int n){
    // base case
    if(n==0){
        return ;
    }

    // processing
    cout<<n<<endl;

    // recurrence relation
    print(n-1);
}
// in the above recursion function recurrence relation is at tail so its called tail recursion

void print2(int n){
    // base case
    if(n==0){
        return ;
    }

    // Recurrence relation
    print2(n-1);

    // processing
    cout<<n<<endl;

}
// In the above recursion code recurrence relation is above processing (not at tail) so its called head recusion
int main()
{
    int n;
    cin>>n;

    // for tail recursion
    cout<<endl;
    print(n);

    // for head recursion
    cout<<endl;
    print2(n);

    return 0;
}

// the tail recursion will print counting from n to 1
// the head recursion will print counting from 1 to n