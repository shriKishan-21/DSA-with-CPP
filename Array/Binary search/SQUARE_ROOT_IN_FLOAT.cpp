// FINDING THE FLOAT PART IN SQUARE ROOT

#include <iostream>
using namespace std;

int binarySearch(int x){
    int s=0,e=x;
    long long int mid=s+(e-s)/2;
    long long int ans=-1;
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

double morePrecision(int n,int precision,int tempSol){
    double factor=1;
    double ans=tempSol;
    for(int i=0;i<precision;i++){
        factor=factor/10;
        for(double j=ans;j*j<n;j=j+factor){
            ans=j;
        }
    }
    return ans;
}

int main(){
    int n=65;
    int tempSol=binarySearch(n);
    int precision=3;
    cout<<morePrecision(n,precision,tempSol)<<endl;
    return 0;
}