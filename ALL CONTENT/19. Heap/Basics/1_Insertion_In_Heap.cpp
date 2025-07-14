#include<iostream>
#include<stack>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;

class heap{
    public:
    int arr[100];
    int size;

    // constructor
    heap(){
        arr[0]=-1;
        size=0;
    }

    // insertion in heap
    void insert(int val){
        size=size+1;
        int index=size;
        arr[index]=val;

        while(index>1){
            int parent = index/2;

            if(arr[parent]<arr[index]){
                swap(arr[parent],arr[index]);
                index=parent;
            }
            else{
                return;
            }
        }
    }

};
int main()
{
    heap h;
    h.insert(10);
    h.insert(20);
    h.insert(30);
    h.insert(40);
    h.insert(50);
    h.insert(60);
    h.insert(70);
    h.insert(80);
    h.insert(90);
    h.insert(100);

    for(int i=1;i<=h.size;i++){
        cout<<h.arr[i]<<" ";
    }
    return 0;
}