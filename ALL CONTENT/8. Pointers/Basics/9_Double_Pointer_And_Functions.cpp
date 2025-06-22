#include<bits/stdc++.h>
using namespace std;

void update(int **q){
    q=q+1;
    // will something be changed --> No

    *q=*q+1;
    // will something be changed --> Yes

    **q=**q+1;
    // will something be changed --> Yes
}

int main()
{
    int i = 5;
    int *p = &i;
    int **q = &p;

    // Before updation
    cout<<"Before :"<<i<<endl;
    cout<<"Before :"<<p<<endl;
    cout<<"Before :"<<q<<endl;

    // After updation
    update(q);
    cout<<"After :"<<i<<endl;
    cout<<"After :"<<p<<endl;
    cout<<"After :"<<q<<endl;

    return 0;
}