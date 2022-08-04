#include <iostream>
using namespace std;

int main(){
    cout<<"Enter the value:\n";
    int number1;
    cin>>number1;
    cout<<"Enter the power:\n";
    int number2;
    cin>>number2;
    int ans =1;
    while(number2>0)
    {
        int last = (number2&1);
        if(last>0)
        {
            ans = ans*number1;
        }
        number1=number1*number1;
        number2=number2>>1;
    }
    cout<<ans;
    return 0;

}