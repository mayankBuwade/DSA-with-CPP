//
#include<iostream>

using namespace std;

int helper(int arr[], int s, int e)
{
    int pivot = arr[e]; //selecting an element as pivot
    int pivotI = s;

    //putting all the elements smaller than pivot
    //to the left and the larger elements to the right
    for(int i = s; i<e; i++)
    {
        if(arr[i]<=pivot)
        {
            swap(arr[i], arr[pivotI]);
            ++pivotI;
        }
    }
    swap(arr[pivotI], arr[e]); //positioning pivot to the right place
    return pivotI;
}

void quickSort(int arr[], int s, int e)
{
    if(s<e)
    {
        int pivotI = helper(arr, s, e); //getting the pivot index
        // recursive call for the left part of pivot
        quickSort(arr, s, pivotI-1);
        // recursive call for the right part of pivot
        quickSort(arr, pivotI+1, e);
    }
}

int main()
{
    system("cls");
     int arr[] = {5, 7, 9, 55, 1, 3, 0};
    const int n = sizeof(arr)/sizeof(arr[0]);

    quickSort(arr, 0,  n-1);
    for(int i = 0; i<n; ++i)
    {
        cout<<arr[i]<<" ";
    }
    return 0;
}