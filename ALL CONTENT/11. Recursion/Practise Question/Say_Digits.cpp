#include<bits/stdc++.h>
using namespace std;

void sayDigit(int n,string arr[]){
    if(n==0)
        return ;
    
        
    // processing
    int digit = n%10;
    n = n/10;

    // if we print the digit here it will print in reverse

    sayDigit(n,arr);
    
    // we print the digit after recursion call so that it will print in correct order
    cout<<arr[digit]<<" ";
    // same as the previous problem where we print counting from 1 to n by head recursion 
}
int main()
{
    string arr[10]={"zero","one","two","three","four","five","six","seven","eight","nine"};

    int n;
    cin>>n;
    cout<<endl;

    sayDigit(n,arr);
}