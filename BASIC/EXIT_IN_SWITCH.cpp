// USING SWITCH CASE IN INFINITE LOOP TO EXIT FROM IT
// WE USE exit()

#include<iostream>
using namespace std;
int main(){
    int n;
    cout<<"Enter a number between 1 to 5"<<endl;
    cin>>n;
    while(1){
        switch(n){
            case 1:cout<<"One"<<endl;
            break;
            case 2:cout<<"Two"<<endl;
            break;
            case 3:cout<<"Three"<<endl;
            break;
            case 4:cout<<"Four"<<endl;
            break;
            case 5:cout<<"Five"<<endl;
            break;
            default:cout<<"Invalid Number"<<endl;
        }
        exit(0);
        //exit(1);
/* exit(0) which is the exit succesfully which means program has run successfully and then it is terminated i.e. program has been
   successfully executed without any error */
/* exit(1) which is the exit unsuccesfully which means program has run successfully but it is terminated with error*/
}
    return 0;
}