// Destructor
// Destructor is called automatically when the object is destroyed
// if no destructor is created in the class then the compiler will create a destructor and call it.
#include<bits/stdc++.h>
using namespace std;


class Hero{

    // properties
    private:
    int health;

    public:
    char *name;
    char level;


    // default constructor
    Hero(){
        cout<<" Default constructor is called"<<endl;
        name = new char[100];
    }

    // Destructor
    ~Hero(){
        cout<<" Destructor is called"<<endl;
        delete [] name;
    }

    int getHealth(){
        return this->health;
    }

    void setHealth(int h){
        health = h;
    }

    void setName(char name[]){
        // copies the new name to the existing name
        strcpy(this->name,name);
    }

    void print(){
        cout<<"Name :"<<name<<" , ";
        cout<<"Health :"<<health<<" , ";
        cout<<"Level :"<<level<<endl;
    }

};
int main()
{
    // Static allocation
    Hero h1;

    // Dynamic Allocation
    Hero *h2 = new Hero;

    // Here we can see that when the object is created by both static and dynamic allocation then the constructor is called for both of them
    // but when the object is destroyed by both static and dynamic allocation then the destructor is called only once
    // because for -->
    // Static allocation --> the destructor is called automatically
    // Dynamic Allocation --> the destructor is called manually
    delete h2;

    return 0;
}