// REVERSE AN ARRAY AFTER A PARTICULAR INDEX

#include <bits/stdc++.h>
using namespace std;

void reverseArray(vector<int>& arr,int m){
    int i=m+1;
    int j=arr.size()-1;
    while(j>i){
        swap(arr[i],arr[j]);
        i++;
        j--;
    }
}
int main()
{
    vector<int> arr={1,2,3,4,5,6,7,8};
    int m=3;
    reverseArray(arr,m);
    for(int i=0;i<arr.size();i++){
        cout<<arr[i]<<" ";
    }

}