#include <bits/stdc++.h> 
using namespace std;


void stringrev(string& str,int i,int j){
	if(i>j){
		return ;
	}

	swap(str[i],str[j]);
	i++;
	j--;

	stringrev(str,i,j);
}
string reverseString(string str)
{
	stringrev(str,0,str.length()-1);

	return str;
	
}
/*
code if you want to use only one pointer i (without using j pointer)
void stringrev(string& str,int i){
	int j = str.length()-i-1;
	if(i>j){
		return ;
	}

	swap(str[i],str[j]);
	i++;
	j--;

	stringrev(str,i);
}
string reverseString(string str)
{
	stringrev(str,0);

	return str;
	
}
*/

int main()
{
    string str="coding";
    cout<<reverseString(str);
}