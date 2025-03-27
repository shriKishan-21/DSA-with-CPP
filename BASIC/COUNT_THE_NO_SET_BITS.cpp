// FUNCTION TO COUNT THE NUMBER OF SET BITS

#include<iostream>
using namespace std;

int setBits(int a,int b){
   int count=0;
   while(a!=0 || b!=0){
       if((a&1)!=(b&1)){
           count++;
       }
       a=a>>1;
       b=b>>1;
   }
   return count;    
}

int main(){
    int a,b;
    cin>>a>>b;
    cout<<setBits(a,b);
}