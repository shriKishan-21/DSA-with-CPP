#include<bits/stdc++.h>
using namespace std;


bool isPresent(int arr[][4],int target,int row,int col){
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            if(arr[i][j]==target){
                return 1;
            }
        }
    }
    return 0;
}
int main()
{
    int arr[3][4] = {1,2,3,4,5,6,7,8,9,10,11,12};
    int target=5;
    int row=3;
    int col=4;
    cout<<isPresent(arr,target,row,col);
}