// BOOK ALLOCATION PROBLEM

#include<bits/stdc++.h>
using namespace std;


bool isPossible (vector<int>& arr,int n,int m,int mid){
    int stdCount=1;
    int pageSum=0;
    for(int i=0;i<n;i++){
        if(pageSum+arr[i]>mid){
            stdCount++;
            pageSum=arr[i];
            if(stdCount>m || arr[i]>mid){
                return false;
            }
        }
        else{
            pageSum+=arr[i];
        }
    }
    return true;
}
// bool isPossible(int arr[],int n,int m,int mid){
//     // pagesum to calculate total pages allocate to a student
//     int pageSum=0;
//     // studentcount to calculate total number of student 
//     int studentCount=1;
//     for(int i=0;i<n;i++){
//         if(pageSum+arr[i]<=mid){
//             // if pagesum is less than or equal to mid
//             pageSum+=arr[i];
//         }
//         else{
//             // if pagesum is greater than mid
//             studentCount++;
//             if(studentCount>m || arr[i]>mid){
//                 // if studentcount is greater than m or pagesum is greater than mid
//                 return false;
//             }
//             else{
//                 pageSum+=arr[i];
//             }
//         }
//     }
//     return true;
// }

int bookAllocation(vector<int>& arr,int n,int m){
    int s=0;
    int sum=0;
    for(int i=0;i<n;i++){
        sum+=arr[i];
    }
    int e=sum;
    int mid=s+(e-s)/2;
    int ans=-1;
    while(s<=e){
        if(isPossible(arr,n,m,mid)){
            ans=mid;
            e=mid-1;
        }
        else{
            s=mid+1;
        }
        mid=s+(e-s)/2;
    }
    return ans;
}

int main(){
    vector<int> arr={2,8,8,4,5};
    int n=arr.size();
    int m=6;
    cout<<bookAllocation(arr,n,m);
    return 0;
}


