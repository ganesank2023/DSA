#include <iostream>
using namespace std;

void printArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}

// Insertion sort
void sortArray(int arr[], int size)
{
    int key;
    for (int i = 1; i < size; i++)
    {
        key = arr[i];
        int j = i - 1;
        while (key < arr[j] && j >= 0)
        {
            arr[j + 1] = arr[j];
            --j;
        }
        arr[j + 1] = key;

        // printArray(arr, size);
    }
}

int main()
{
    int arr[] = {9, 5, 1, 4, 3};
    int size = sizeof(arr) / sizeof(arr[0]);
    cout << "\nArray before sorting is: " << endl;
    printArray(arr, size);
    cout << "\nArray after sorting is: " << endl;
    sortArray(arr, size);
    printArray(arr, size);
}