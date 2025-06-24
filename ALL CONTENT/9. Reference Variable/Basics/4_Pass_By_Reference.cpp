// Pass By Reference

#include<bits/stdc++.h>
using namespace std;

/* 
This is dangerous practise (Do not perform this) :

int& updated(int n){
    int a = 10;
    int &ans = a;
    return ans;
}
    
Because -->
 1. We can't access the memory of ans
 2. Maybe some other garbage is over that memory(or memory maybe updated by someone else)
*/

void update(int& n){
    n++;
}
int main()
{
    int n = 5;

    cout<<"Before :"<<n<<endl;
    update(n);
    cout<<"After :"<<n<<endl;

    return 0;
}

// Here the value of n will be updated as in the pass by reference we use reference variable
// where we use the same memory but with different name
// Here No New memory created