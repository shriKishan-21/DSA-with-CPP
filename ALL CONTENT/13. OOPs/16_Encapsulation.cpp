// Encapsulation
// It is the process of hiding the information or data of a class from the outside world.
// It is defined as wrapping up of data members and functions together
#include<bits/stdc++.h>
using namespace std;


class student{
    private:
    string name;
    int age;
    int height;

    public:
    int getAge(){
        return age;
    }
    void setAge(int a){
        age = a;
    }
};
int main()
{
    student s1;
    s1.setAge(20);
    cout<<s1.getAge();
    return 0;
}