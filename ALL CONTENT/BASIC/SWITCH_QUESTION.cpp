// NOTES REQUIRED FOR AMOUNT USING SWITCH STATEMENT

#include<iostream>
using namespace std;

int main(){
    int amount;
    cout<<"Enter Amount:";
    cin>>amount;
    int hundred,fifty,twenty,one;
    switch(100){
        case 100:
        hundred=amount/100;
        cout<<"one hundred notes used are:"<<hundred<<endl;
        amount=amount-hundred*100;
        switch(50){
            case 50:
            fifty=amount/50;
            cout<<"fifty notes used are:"<<fifty<<endl;
            amount=amount-fifty*50;
            switch(20){
                case 20:
                twenty=amount/20;
                cout<<"twenty notes used are:"<<twenty<<endl;
                amount=amount-twenty*20;
                switch(1){
                    case 1:
                    one=amount/1;
                    cout<<"one notes used are:"<<one<<endl;
                    amount=amount-one*1;
                    break;
                }
            }
        }
    }
}