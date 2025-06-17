#include<bits/stdc++.h>
using namespace std;

int main()
{
    int arr[3][4]={1,2,3,4,5,6,7,8,9,10,11,12};
    int target=5;

    // calculate row and col size
    int row=sizeof(arr)/sizeof(arr[0]);
    int col=sizeof(arr[0])/sizeof(arr[0][0]);

    // initialise low and high
    int start = 0;
    int end = row*col-1;

    // initialise mid
    int mid = start + (end-start)/2;

    while(start<=end)
    {
        // calculate mid
        int midElement = arr[mid/col][mid%col];

        if(midElement==target)
        {
            cout<<"Element is found at index "<<mid<<endl;
            return 0;
        }
        else if(midElement<target){
            start=mid+1;
        }
        else{
            end=mid-1;
        }

        mid = start + (end-start)/2;
    }

    cout<<"Element is not found"<<endl;
    return 0;


}