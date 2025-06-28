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

    // copy constructor
    Hero(Hero &temp){
        char *ch = new char[strlen(temp.name)+1];
        strcpy(ch,temp.name);
        this->name = ch;

        cout<<" Copy constructor is called"<<endl;
        this->health = temp.health;
        this->level = temp.level;
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

    Hero h1;
    char name[6] = "Rohan";
    h1.setName(name);
    h1.setHealth(70);
    h1.level = 'A';

    // creating a copy of h1
    Hero h2(h1);

    // lets update the rank of h1 object
    h1.name[0] = 'M';

    h1.print();
    h2.print();

    // copy Assignment Operator
    h2 = h1;

    h1.print();
    h2.print();

    return 0;
}