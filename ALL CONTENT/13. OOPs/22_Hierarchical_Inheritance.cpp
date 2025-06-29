// Hierarchical Inheritance

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

class Cow : public Animal{

    public:

    void Moo(){
        cout<<"cow Moo"<<endl;
    }
};

class Dog : public Animal{

    public:

    void bark(){
        cout<<"Barking"<<endl;
    }
};

int main(){

    // object for class Cow can only access class Animal
    Cow c1;
    c1.speak();
    c1.Moo();
    cout<<c1.height<<endl;

    // object for class Dog can only access class Animal
    Dog d1;
    d1.speak();
    d1.bark();
    cout<<d1.height<<endl;
    
    return 0;
}