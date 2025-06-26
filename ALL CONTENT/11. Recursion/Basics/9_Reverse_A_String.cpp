#include<bits/stdc++.h>
using namespace std;

void reverseString(string& str, int i,int j){
    // base case
    if(i>j) return ;

    swap(str[i],str[j]);

    i++;
    j--;

    reverseString(str,i,j);
    
}
int main()
{
    string str = "hello";
    reverseString(str,0,str.length()-1);
    for(auto i:str){
        cout<<i<<" ";
    }

}