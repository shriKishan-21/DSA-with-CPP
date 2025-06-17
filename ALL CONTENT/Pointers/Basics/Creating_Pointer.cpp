#include<iostream>
using namespace std;

int main()
{
    int a = 10;
    // creating pointer
    // here a is a variable and ptr is a pointer  
    int *ptr = &a;

    // to print the address of a (print pointer ptr):
    cout<<"Address : "<<ptr<<endl;
    // to print the value of a(print pointing value):
    // we use * (dereference operator) :
    cout<<"Value : "<<*ptr<<endl;


    // double type
    double d = 1.2;

    double *p = &d;
    
    cout<<p<<endl;
    cout<<*p<<endl;

    // lets check their size
    cout<<"Size of a(int) is : "<<sizeof(a)<<endl;
    cout<<"Size of pointer ptr is : "<<sizeof(ptr)<<endl;
    cout<<"Size of d(double) is : "<<sizeof(d)<<endl;
    cout<<"Size of pointer p is : "<<sizeof(p)<<endl;
    
    return 0;

}