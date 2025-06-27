#include <bits/stdc++.h>
using namespace std;

void solve(string str,string output,int index,vector<string>& ans){
	// base case
	if(index >= str.length()){
		// we dont need empty string as one of its subsequence
		if(output.length() > 0){
			ans.push_back(output);
		}
		return ;
	}

	// exclude recursive call
	solve(str,output,index+1,ans);

	// include recursive call
	char element = str[index];
	output.push_back(element);
	solve(str,output,index+1,ans);

}
vector<string> subsequences(string str){
	
	vector<string> ans;
	string output = "";
	int index = 0;
	solve(str,output,index,ans);

	return ans;
	
}

int main(){

	string str = "abc";
	vector<string> ans = subsequences(str);
	
	for(auto i:ans){
		cout<<i<<" ";
	}
}
