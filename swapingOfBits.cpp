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
    for(int j=0;j<i-1;j+=2)
    {
        int temp = arr[j];
        arr[j]=arr[j+1];
        arr[j+1]=temp;

    }
    for(int j=i-1;j>=0;j--)
    {
        cout<<arr[j]<<" ";
    }
}