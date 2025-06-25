#include<bits/stdc++.h>
using namespace std;


// using default arguments
// here int index = 0 is default argument where if we don't pass any value it will take 0
void print(int arr[],int size,int start = 0){
    for(int i=start;i<size;i++){
        cout<<arr[i]<<" ";
    }
}
// Always keep in mind default arguments should always start from last argument(rightmost argument)
// otherwise it will throw error

int main()
{
      int arr[5] = {1,4,7,8,9};
      int size = 5;

      // Printing the array by passing start value
      print(arr,size,2);

      // printing the array without passing start value
      cout<<endl;
      print(arr,size);
      // here it will take default value 0
      
      return 0;
}