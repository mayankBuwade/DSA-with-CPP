//Selection Sort
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

void selectionSort(int arr[], int n) {

    int min;
    for(int i = 0; i<n-1; i++) 
    {
        min = i;
        for(int j = i+1; j<n; j++)
        {
            if(arr[min] > arr[j])
            {
                min = j;
            }
        }
        //swap
        if(i!=min) {
            int temp = arr[min];
            arr[min] = arr[i];
            arr[i] = temp;
        }

    }
}

//worst case, best case, average case:- O(n^2)



int main()
{
    system("cls");
    int arr[] = {4, 7 , 1, 2};
    int n = sizeof(arr)/sizeof(arr[0]);
    printArray(arr, n);
    selectionSort(arr, n);
    return 0;
}