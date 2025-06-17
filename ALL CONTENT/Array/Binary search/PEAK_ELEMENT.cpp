// PEAK INDEX IN AN MOUNTAIN ARRAY

#include <bits/stdc++.h>
using namespace std;    

int peakIndexInMountainArray(vector<int> &arr)
{
    int s = 0, e = arr.size() - 1;
    int mid = s + (e - s) / 2;
    while (s < e)
    {
        if (arr[mid] > arr[mid + 1] && arr[mid] > arr[mid - 1])
        {
            return mid;
        }
        else if (arr[mid] < arr[mid + 1])
        {
            s = mid + 1;
        }
        else
        {
            e = mid;
        }
        mid = s + (e - s) / 2;
    }
    return -1;
}

int main(){
    vector<int> arr={0,1,0};
    cout<<peakIndexInMountainArray(arr);
}