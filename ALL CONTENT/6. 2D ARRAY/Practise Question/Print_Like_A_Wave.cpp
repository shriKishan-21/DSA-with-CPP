#include<bits/stdc++.h>
using namespace std;

int main()
{
    int arr[3][4] = {1,2,3,4,5,6,7,8,9,10,11,12};
    int n = 3, m = 4;

    vector<int> ans;
    for(int i =0;i<m;i++){
        if(i%2==0){
            for(int j=0;j<n;j++){
                ans.push_back(arr[j][i]);
            }
        }
        else{
            for(int j=n-1;j>=0;j--){
                ans.push_back(arr[j][i]);
            }
        }  
    }
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
}