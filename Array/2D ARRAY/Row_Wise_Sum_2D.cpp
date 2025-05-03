#include <iostream>
using namespace std;


int printSum(int arr[][4],int row,int col){
    for (int row = 0; row < 3; row++)
    {
        int sum=0;
        for (int col = 0; col < 4; col++)
        {
            sum+=arr[row][col];
        }
        cout<<"Sum of Row "<<row<<" is: "<<sum<<endl;
    }   
}
int main()
{
    int arr[3][4];

    for (int  row= 0; row < 3; row++)
    {
        for (int col = 0; col < 4; col++)
        {
            cin >> arr[row][col];
        }
    }

    cout<< "Printing the array:"<<endl;
    for (int row = 0; row < 3; row++)
    {
        for (int col = 0; col < 4; col++)
        {
            cout << arr[row][col] << " ";
        }
        cout<<endl;
    }

    printSum(arr,3,4);
}