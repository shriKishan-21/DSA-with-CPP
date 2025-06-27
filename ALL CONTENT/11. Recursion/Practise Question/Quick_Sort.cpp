#include<bits/stdc++.h>
using namespace std;

int partition(vector<int>& arr,int s,int e){
    // pivot
    int pivot = arr[s];

    // count
    int count=0;
    for(int i=s+1;i<=e;i++){
        if(arr[i]<=pivot){
            count++;
        }
    }

    // pivotIndex
    int pivotIndex = s+count;
    swap(arr[pivotIndex],arr[s]);

    // maintain condition
    int i=s , j=e;
    while(i<pivotIndex && j>pivotIndex){
        while(arr[i]<=pivot){
            i++;
        }
        while(arr[j]>pivot){
            j--;
        }
        if(i<pivotIndex && j>pivotIndex){
            swap(arr[i++],arr[j--]);
        }
    }
    return pivotIndex;
}

void solve(vector<int>& arr,int s,int e){
    // base case
    if(s>=e){
        return ;
    }

    int p = partition(arr,s,e);

    // recusive call
    solve(arr,s,p-1);
    solve(arr,p+1,e);
}
vector<int> quickSort(vector<int>& arr)
{
    solve(arr,0,arr.size()-1);
    return arr;
}


int main(){
    vector<int> arr = {4,2,5,1,3};
    quickSort(arr);
    for(int i=0;i<arr.size();i++){
        cout<<arr[i]<<" ";
    }
}