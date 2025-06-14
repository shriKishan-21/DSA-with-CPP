#include<bits/stdc++.h>
using namespace std;

int main()
{
    int row,col;
    cin>>row>>col;
    int arr[row][col];

    for(int i=0;i<col;i++){
        for(int j=0;j<row;j++){
            cin>>arr[j][i];
        }
    }
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}