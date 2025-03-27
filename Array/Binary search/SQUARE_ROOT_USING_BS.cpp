// SQUARE ROOT OF A NUMBER USING BINARY SEARCH

#include <iostream>
using namespace std;

int binarySearch(int x){
    int s=0,e=x;
    long long int mid=s+(e-s)/2;
    int ans=-1;
    while(s<=e){
        long long int square = mid*mid;
        if(square==x){
            return mid;
        }
        else if(square<x){
            ans=mid;
            s=mid+1;
        } 
        else{
            e=mid-1;
        }
        mid=s+(e-s)/2;
    }
    return ans;
}

int squareRoot(int x){
    return binarySearch(x);
}

int main()
{
    int x=65;
    cout<<squareRoot(x);
}