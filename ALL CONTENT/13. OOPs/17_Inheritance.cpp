// Inheritance
// It is a process of reusing the code of a class by creating a new class based on an existing class
// Base class is called parent class or super class and derived class is called child class or sub class
#include<bits/stdc++.h>
using namespace std;

// parent or super class
class Human{
    public:
    int height;
    int weight;
    int age;

    int getAge(){
        return age;
    }

    void setWeight(int w){
        weight = w;
    }

};

// child or sub class
class Male : public Human{
    public:
    string color;

    void sleep(){
        cout<<"Male sleeping"<<endl;
    }
};

int main()
{
    // creating object for child class
    Male m1;
    m1.sleep();

    // we can access public member of parent class using child class object
    m1.height = 5;
    cout<<m1.height<<endl;

    return 0;
}