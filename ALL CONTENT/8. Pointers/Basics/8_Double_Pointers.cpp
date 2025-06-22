#include<bits/stdc++.h>
using namespace std;

int main()
{
    int i = 5;
    int *p = &i;
    int **p1 = &p;


    // For single pointer
    cout<<i<<endl;
    cout<<p<<endl;
    cout<<*p<<endl;
    cout<<&p<<endl;

    // For double pointer
    cout<<p1<<endl;
    cout<<*p1<<endl;
    cout<<&p1<<endl;
    cout<<**p1<<endl;
}