//
#include<iostream>

using namespace std;

void printArray(int arr[], int n)
{
    for(int i = 0; i<n; i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

void bubbleSort(int arr[], int n)
{
    for(int i = 0; i<n-1; i++)
    {
        for(int j = 0; j<n-1-i; j++)
        {
            if(arr[j]>arr[j+1])
            {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

//worst case:-  O(n^2)
//average case:-  O(n^2)
//best case:-  O(n^2)

void optimizedBubbleSort(int arr[], int n)
{
    for(int i = 0; i<n-1; i++)
    {
        //this flag will check if array is sorted
        bool isSwapped = false;
        for(int j = 0; j<n-1-i; j++)
        {
            if(arr[j]>arr[j+1])
            {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
                isSwapped = true;
            }
        }
        if(!isSwapped)
        {
            break;
        }
    }
}
//worst case:-  O(n^2)
//average case:-  O(n^2)
//best case:-  O(n)


int main()
{
    system("cls");
    int arr2[] = {1, 2, 3, 4};
    int arr[] = {9, 1, 7, 2};
    int n = sizeof(arr)/sizeof(arr[0]);
    int m = sizeof(arr2)/sizeof(arr2[0]);
    printArray(arr, n);
    optimizedBubbleSort(arr, n);
    printArray(arr, n);
    return 0;
}