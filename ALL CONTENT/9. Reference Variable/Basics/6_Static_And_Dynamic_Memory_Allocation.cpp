#include<bits/stdc++.h>
using namespace std;

int main()
{
    // static memory allocation
    int a[5];
    for(int i=0;i<5;i++){
        cin>>a[i];
    }
    for(int i=0;i<5;i++){
        cout<<a[i]<<" ";
    }

    // static memory is released automatically

    // dynamic memory allocation
    int* b = new int[5];
    for(int i=0;i<5;i++){
        cin>>b[i];
    }
    for(int i=0;i<5;i++){
        cout<<b[i]<<" ";
    }

    // Dynamic memory is released manually by the user
    // deleting array
    delete[] b;

    return 0;
}