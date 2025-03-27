// PASS BY VALUE

#include<iostream>
using namespace std;

int update(int n){
    n-=5;
    return n;
}
int main(){
    int n=15;
    update(n);
    cout<<n<<endl;
    cout<<update(n);
}