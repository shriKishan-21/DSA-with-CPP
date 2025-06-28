// Shallow copy
// Here on updating the original object the copy object will get updated
// Accessing same memory with different name
#include<bits/stdc++.h>
using namespace std;


class Hero{

    // properties
    private:
    int health;

    public:
    char *name;
    char level;

    Hero(){
        cout<<" Default constructor is called"<<endl;
        // initializing the name
        name = new char[100];
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

    // object creation
    Hero h1;
    char name[6] = "Rohan";
    h1.setName(name);
    h1.setHealth(70);
    h1.level = 'A';
    cout<<"Object h1 :" << endl;
    h1.print();

    // creating a copy of h1
    Hero h2(h1);
    
    cout<<"Object h2 :" << endl;
    h2.print();

    // lets update the rank of h1 object
    h1.name[0] = 'M';
    cout<<"Object After updating h1 :" << endl;
    h1.print();

    // lets check h2 now
    cout<<"Object h2 :" << endl;
    h2.print();

    // here we can see that when we update h1 object then h2 object also gets updated
}