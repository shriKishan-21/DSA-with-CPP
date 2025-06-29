// Hybrid Inheritance

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

class voice {

    public:

    void AnimalVoice(){
        cout<<"animal voice"<<endl;
    }
};

class Cat : public Animal{

    public:

    void meow(){
        cout<<"Meowing"<<endl;
    }    
};
class Dog : public Animal, public voice{

    public:

    void bark(){
        cout<<"Barking"<<endl;
    }
};

int main(){

    // object for class Cat can only access class Animal
    Cat c1;
    c1.speak();
    c1.meow();
    cout<<c1.height<<endl;

    // object for class Dog can only access class Animal and class voice
    Dog d1;
    d1.speak();
    d1.bark();
    d1.AnimalVoice();
    cout<<d1.height<<endl;
    
    return 0;
}