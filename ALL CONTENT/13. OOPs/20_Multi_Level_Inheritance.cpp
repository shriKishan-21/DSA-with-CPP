// Multi Level Inheritance

#include<bits/stdc++.h>
using namespace std;

class Animal{

    public:
    int height = 0;
    int weight = 0;
    

    void speak(){
        cout<<"Speaking"<<endl;
    }

};

class Dog : public Animal{

    public:

    void bark(){
        cout<<"Barking"<<endl;
    }
};

class Puppy : public Dog{

    public:

    void weep(){
        cout<<"Weeping"<<endl;
    }
};

int main(){

    Puppy d1;
    d1.speak();
    d1.bark();
    d1.weep();
    cout<<d1.height<<endl;
    
    return 0;
}