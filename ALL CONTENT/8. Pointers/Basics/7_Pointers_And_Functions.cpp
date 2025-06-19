#include<bits/stdc++.h>
using namespace std;


// Printing p using functions
void print(int *p){
    cout<< p << endl;
}

// updating p value 
void update(int *p){
    p=p+1;
    // if we print updated p here it will give updated p
    cout<<"Updated p:"<<p<<endl;
}

// updating p address value
void updateValue(int *p){
    *p=*p+1;
}

// get the sum of array
// int getSum(int arr[],int n){
int getSum(int *arr,int n){
    // here its actually (int *arr)
    // cout<<"Size of arr :"<<sizeof(arr)<<endl;
    int sum=0;
    for(int i=0;i<n;i++){
        sum+=arr[i];
    }
    return sum;
}

int main()
{
    int value = 5;
    int *p = &value;

    // printing p -->
    print(p);

    // updating p -->
    cout<<"Before p :"<<p<<endl;
    update(p);
    cout<<"After p :"<<p<<endl;
    // But here the before and after value will be same as we are giving main() p as output and updating update() p

    // updating p address value -->
    cout<<"Before p :"<<*p<<endl;
    updateValue(p);
    cout<<"After p :"<<*p<<endl;

    // geting sum of array
    int arr[5] = {1,2,3,4,5};
    cout<<"Sum of arr is :"<<getSum(arr,5)<<endl;
    // here sizeof(arr) should be 20 (4(int type)*5(total element))
    // but it came out 4 . Whyy??
    // bcz when we pass an argument its actually its pointer which is passed (here int *arr) not the actual arr 
    // because of this benefit we can send part of array
    cout<<"Sum of arr (3->5) is :"<<getSum(arr+2,3)<<endl;


    return 0;
}