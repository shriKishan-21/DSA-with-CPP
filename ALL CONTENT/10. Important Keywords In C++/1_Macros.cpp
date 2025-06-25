#include<iostream>
using namespace std;

#define PI 3.14
// Here the PI is the macro and 3.14 is the value
// Macro is a piece of code in a program that is replaced by a value at compile time
// Brfor comilation all the macro present in code will be replacd by the defined value

int main()
{
    int r =5;

    double area = PI*r*r;

    // if we try to update macro then it will give error
    // PI = PI + 1;
    // Macro value cannot be updated/changed
    
    cout<<"Area of circle is "<<area<<endl;

    return 0;
}
