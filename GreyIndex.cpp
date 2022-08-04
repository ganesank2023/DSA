#include <iostream>
using namespace std;
int main(){
    cout<<"Enter the number:\n";
    int number1;
    cin>>number1;
    int arr[20];
    int i=0;
    int temp =number1;
    while(temp>0)
    {
        int a=temp%2;
        arr[i++]=a;
        temp = temp/2;
    }
    int grey[i];
    int k=1;
    grey[0]=arr[i-1];
    for(int j=i-1;j>0;j--)
    {
        
       grey[k++]= arr[j]^arr[j-1];
        
    }
    for(int n=0;n<i;n++)
    {
        cout<<grey[n]<<" ";
    }
}