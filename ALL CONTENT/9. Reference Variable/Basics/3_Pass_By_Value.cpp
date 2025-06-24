// Pass By Value 

#include<bits/stdc++.h>
using namespace std;

void update(int i){
    i++;
}

int main()
{
    int i = 5;

    cout<<"Before : "<<i<<endl;
    update(i);
    cout<<"After : "<<i<<endl;

    return 0;
}

// Here the value of i will not be updated as in the pass by value a copy of the variable is pass to the function
// on which operations occured not on the actual value
// Here New memory is created