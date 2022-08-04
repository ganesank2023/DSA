#include <iostream>
using namespace std;
int main(){
    cout<<"Enter the number:\n";
    int number1;
    cin>>number1;
     int temp = number1;
    int lsb = temp&1;
    cout<<"The LSB value of the given number is "<<lsb<<endl;
    int msb = 0;
    temp = number1;
    temp = temp/2;
    while(temp!=0)
    {
        temp= temp/2;
        msb++;
    }
    int res = 1<< msb;
    cout<<"The MSB value of the given number is "<< res<<endl;
}