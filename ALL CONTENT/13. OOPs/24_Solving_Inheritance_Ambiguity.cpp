// Solving Inheritance Ambiguity
// Inheritance Ambiguity is the problem which occurs when a derived class inherits from more than one base class
// To solve this ambiguity we can use scope resolution operator(::)

#include<bits/stdc++.h>
using namespace std;

class A{

    public:
    void func(){
        cout<<"Class a function"<<endl;
    }

};

class B {

    public:

    void func(){
        cout<<"Class b function"<<endl;
    }
};

class C : public A , public B{  
};

int main(){
    
    C obj;
    // obj.func(); // will raise error as both class a and b have same function name
    // well use scope resolution operator(::) here
    obj.A::func();
    obj.B::func();


    return 0;
}