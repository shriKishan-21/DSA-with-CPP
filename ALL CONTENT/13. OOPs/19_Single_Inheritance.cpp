/*
Types of Inheritance :
1. Single Inheritance
2. Multiple Inheritance
3. Multilevel Inheritance
4. Hybrid Inheritance
5. Hierarchical Inheritance
*/

// Single Inheritance

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
};

int main(){

    Dog d1;
    d1.speak();
    cout<<d1.height<<endl;
    
    return 0;
}