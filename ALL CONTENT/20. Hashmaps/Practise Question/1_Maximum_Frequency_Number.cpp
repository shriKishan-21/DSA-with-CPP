#include<iostream>
#include<unordered_map>
#include<vector>
#include<algorithm>
using namespace std;


int maximumFrequency(vector<int> &nums, int n) {

    unordered_map<int,int> count;

    int maxFreq = 0;
    int maxAns = 0;

    for(int i=0;i<n;i++){
        count[nums[i]]++;
        maxFreq = max(maxFreq,count[nums[i]]);
    }

    for(int i=0;i<n;i++){
        if(maxFreq == count[nums[i]]){
            maxAns = nums[i];
            break;
        }
    }

    return maxAns;
}
int main()
{
    vector<int> arr = {1,2,3,1,2,5,4,2,4};
    int n = arr.size();

    cout<<maximumFrequency(arr,n)<<endl;

    return 0;
}