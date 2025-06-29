// Method overriding
// method overriding is the process of defining a method in a child class that has the same signature as a method in a parent class

#include<bits/stdc++.h>
using namespace std;

class Parent{
    public:
    void print(){
        cout<<"Parent class"<<endl;
    }
};

class Child : public Parent{
    public:
    void print(){
        cout<<"Child class"<<endl;
    }
};

int main()
{
    Child c1;
    // Here the child class print method is overriding the parent class print method
    // You put your implementation in the child class
    // once you put your implementation in the overridden method then it will always take the implemented method  
    c1.print();
    return 0;
}