#include<iostream>
#include<queue>
using namespace std;

int solve(int *arr , int n , int k){
    deque<int> maxi(k);
    deque<int> mini(k);

    // Addition of first k size window
    for(int i=0; i<k; i++){
        while(!maxi.empty() && arr[maxi.back()] <= arr[i]){
            maxi.pop_back();
        }

        while(!mini.empty() && arr[mini.back()] >= arr[i]){
            mini.pop_back();
        }

        maxi.push_back(i);
        mini.push_back(i);
    }

    int ans = 0;

    for(int i=k; i<n; i++){
        ans += arr[maxi.front()] + arr[maxi.front()];

        // move to next window : 
        // 1. Deleting previous element
        while(!maxi.empty() && i - maxi.front() >= k){
            maxi.pop_front();
        }

        while(!mini.empty() && i - mini.front() >= k){
            mini.pop_back();
        }

        // 2. Adding new element
        while(!maxi.empty() && arr[maxi.back()] <= arr[i]){
            maxi.pop_back();
        }

        while(!mini.empty() && arr[mini.back()] >= arr[i]){
            mini.pop_back();
        }

        maxi.push_back(i);
        mini.push_back(i); 
    }

    ans += arr[maxi.front()] + arr[maxi.front()];

    return ans;
}
int main()
{
    int arr[] = {2,5,-1,-3,-1,-2};
    int n = 6;
    int k = 4;
    
    cout<<solve(arr,n,k)<<endl;

    return 0;
}