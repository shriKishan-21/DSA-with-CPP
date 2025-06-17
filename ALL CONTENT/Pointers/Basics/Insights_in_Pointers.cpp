#include<bits/stdc++.h>
using namespace std;

int main()
{

// ---------------------------------------------------------------------------------------------------------------------
    int num = 5;
    int a = num;
    a++;
    cout<<num<<endl;
    // Here o/p will be 5 as num and a are different variable and a is a copy of num

// ---------------------------------------------------------------------------------------------------------------------
    int *ptr = &num;
    (*ptr)++;
    cout<<num<<endl;
    // Here o/p will be 6 as num and ptr are different variable and ptr is a pointer to num
    // *ptr is a pointer to num value and *ptr++ is a pointer to num value incremented by 1

// ---------------------------------------------------------------------------------------------------------------------
    int i =3;
    int *t = &i;
    cout<<*t++<<endl; // o/p will be 3
    cout<<(*t)++<<endl; // o/p will be 4
    // *t is a pointer to i value and *t++ is a pointer to i value incremented by 1
    // so format is important

// ---------------------------------------------------------------------------------------------------------------------
    int j =3;
    int *u = &j;
    *u=*u+1; // o/p will be 5
    // *u is a pointer to j value and *u+1 is a pointer to j value incremented by 1

// ---------------------------------------------------------------------------------------------------------------------
    int k =3;
    int *v = &k;
    v = v+1; // o/p will be 4
    // let address of k be 100 and then v will contain 100 , now on increasing v by 1 it will contain 104 not 101 
    // as k occupies space of 4 bytes and 4 bytes are added to 100 address to get 104 address

// ---------------------------------------------------------------------------------------------------------------------

    return 0;
}