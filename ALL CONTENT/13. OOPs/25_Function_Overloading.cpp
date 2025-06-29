// Function Overloading --> same function name but different parameters

#include<bits/stdc++.h>
using namespace std; 

class A{
    public:

    // function 1
    void fun(){
        cout<<"1"<<endl;
    }

    // function 2
    // This func will give error - same name , return type and parameters
    // void fun(){
    //     cout<<"2"<<endl;
    // }

    // function 3
    // This func will work - same name , same return type but different parameters
    void fun(int a,int b){
        cout<<"2"<<endl;
    }

    // function 4
    // This func will give error - same name , same parameters but different return type
    // int fun(){
    //     return 3;
    // }

    // function 5
    // This func when comapre to function 3 - have same return type , same name , same no of parameters
    // but it will work only because the parameters types are different 
    void fun(char a , int b){
        cout<<"4"<<endl;
    }
};

int main(){
    A obj;
    obj.fun();
    obj.fun(1,2);
    obj.fun('a',2);

    return 0;
}