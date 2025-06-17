#include<bits/stdc++.h>
using namespace std;

int main()
{
    int arr[3][4] = {1,2,3,4,5,6,7,8,9,10,11,12};
    int row=3,col=4;

    int maxi=INT_MIN;
    int rowIndex=-1;

    for(int i=0;i<row;i++){
        int sum=0;
        for(int j=0;j<col;j++){
            sum+=arr[i][j];
        }
        if(sum>maxi){
            maxi=sum;
            rowIndex=row;
        }
    }

    cout<<"Largest row sum is of row "<<rowIndex<<" with sum : "<<maxi<<endl;

    return 0;
}