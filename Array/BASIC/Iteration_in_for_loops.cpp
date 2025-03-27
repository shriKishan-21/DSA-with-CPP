#include<iostream>
using namespace std;

int main(){
    for(int i=0;i<5;i++){
        for(int j=i+1;j<5;j++){
            for(int k=i+2;k<5;k++){
                cout<<" "<<i<<" "<<j<<" "<< k;
            }
        }
    }
}

// first k ends the j ends and then i ends
/*

0 1 2
0 1 3
0 1 4

K ENDS

0 2 2
0 2 3
0 2 4
0 3 2
0 3 3
0 3 4
0 4 2
0 4 3
0 4 4

J ENDS

1 2 3
1 2 4 
1 3 3
1 3 4
1 4 3
1 4 4
2 3 4
2 4 4

I ENDS

*/

