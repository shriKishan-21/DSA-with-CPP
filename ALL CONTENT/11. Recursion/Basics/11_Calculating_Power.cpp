#include<bits/stdc++.h>
using namespace std;

int pow(int n,int p){
    // base case
    if(p==0){
        return 1;
    }
    if(p==1){
        return n;
    }

    // recursive call
    int ans = pow(n,p/2);

    if(p%2==0){
        return ans*ans;
    }
    else{
        return n*ans*ans;
    }
}
int main()
{
    int n,p;
    cin>>n>>p;
    cout<<pow(n,p)<<endl;
    return 0;
}