#include<bits/stdc++.h>
using namespace std;

void update(int n){
    n++;
}

void update2(int& n){
    n++;
}

/*
DO not try this as it is dangerous
int& func(int a){
    int num = a;
    int& ans = num;
    return ans;
}
Here all the variable is local variable and will be deleted after the function
*/

int main()
{
    int n = 5;

    // Will not update the n value
    // AS it is call by value
    cout<<"Before : "<<n<<endl;
    update(n);
    cout<<"After :"<<n<<endl;

    // Will update the n value
    // As it is call by reference
    cout<<"Before : "<<n<<endl;
    update2(n);
    cout<<"After :"<<n<<endl;
}