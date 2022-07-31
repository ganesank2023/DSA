#include <iostream>
using namespace std;

int main()
{
    int n, ele;
    cout << "\nEnter size of the array: ";
    cin >> n;
    int arr[n];
    cout << "\nEnter Array elements" << endl;
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    cout << "\nEnter the element to search for: ";
    cin >> ele;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == ele)
        {
            cout << ele << " found at index: " << i << " and at pos: " << i + 1 << endl;
            return 0;
        }
    }
    cout << "\nElement no found try again !!..." << endl;
}