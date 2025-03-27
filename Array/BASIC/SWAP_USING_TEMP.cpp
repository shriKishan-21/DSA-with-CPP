// SWAPPING TWO VARIABLES USING THIRD VARIABLE(WITHOUT SWAP FUNCTION)

#include<iostream>
using namespace std;

int main(){

    int a=10,b=20;
    cout<<"Before swapping:"<<"a="<<a<<" "<<"b="<<b<<endl;
    //swap using third variable
    int temp;// let temp be the third variable 
    temp=a;
    a=b;
    b=temp;
    cout<<"After swapping:"<<"a="<<a<<" "<<"b="<<b<<endl;

}