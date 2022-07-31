#include <iostream>
using namespace std;

// sort an array
// Merge two subarrays L and M into arr
void merge(int arr[], int p, int q, int r)
{

    // Create L ← A[p..q] and M ← A[q+1..r]
    int n1 = q - p + 1;
    int n2 = r - q;

    int L[n1], M[n2];

    for (int i = 0; i < n1; i++)
        L[i] = arr[p + i];
    for (int j = 0; j < n2; j++)
        M[j] = arr[q + 1 + j];

    // Maintain current index of sub-arrays and main array
    int i, j, k;
    i = 0;
    j = 0;
    k = p;

    // Until we reach either end of either L or M, pick larger among
    // elements L and M and place them in the correct position at A[p..r]
    while (i < n1 && j < n2)
    {
        if (L[i] <= M[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = M[j];
            j++;
        }
        k++;
    }

    // When we run out of elements in either L or M,
    // pick up the remaining elements and put in A[p..r]
    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        arr[k] = M[j];
        j++;
        k++;
    }
}

// Divide the array into two subarrays, sort them and merge them
void mergeSort(int arr[], int l, int r)
{
    if (l < r)
    {
        // m is the point where the array is divided into two subarrays
        int m = l + (r - l) / 2;

        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);

        // Merge the sorted subarrays
        merge(arr, l, m, r);
    }
}

// Print the array
void printArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}

// Binary search function
int binarySearch(int arr[], int index, int size, int ele)
{
    int mid = index + (size - index) / 2;
    if (arr[mid] == ele)
        return mid;
    else if (ele < arr[mid] && mid - 1 >= 0)
        return binarySearch(arr, index, mid - 1, ele);
    else if (ele > arr[mid] && mid <= size)
        return binarySearch(arr, mid + 1, size, ele);
    else
        return -1;
}

int main()
{
    int arr[] = {6, 5, 12, 10, 9, 1};
    int size = sizeof(arr) / sizeof(arr[0]);
    int ele, pos;
    mergeSort(arr, 0, size - 1);
    cout << "\nEnter the element: ";
    cin >> ele;
    pos = binarySearch(arr, 0, size - 1, ele);
    if (pos >= 0)
    {
        cout << "\nThe element is at pos: " << pos + 1 << endl;
        printArray(arr, size);
    }
    else
        cout << "Element not found" << endl;
}