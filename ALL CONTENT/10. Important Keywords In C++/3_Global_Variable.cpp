// Global variable
// We should not use global variable as it is a bad practice
// Because any function can change the value of global variable
#include<bits/stdc++.h>
using namespace std;

// Here score is a global variable
int score = 15;

void a(int& i){
    cout<<score<<" In a function"<<endl;
    cout<<i<<endl;
}
int main()
{
    int i =5;
    cout<<score<<" In main function"<<endl;
    /*
    score++;
    we can change the value of global variable which is a problem for us
    so we don't use global variable
    */
    a(i);
    cout<<i<<endl;    
    return 0;

}