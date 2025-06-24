#include<bits/stdc++.h>
using namespace std;

int main()
{
    int i = 5;

    // Create a Reference variable --> 
    int& j = i;

    cout<<i<<" "<<j<<endl;

    // increment in i and j 
    cout<<i<<endl;
    i++;
    cout<<i<<endl;

    j++;
    cout<< j <<endl;

}