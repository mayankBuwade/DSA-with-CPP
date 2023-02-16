//insertion sort
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

// void insertionSort(int arr[], int n)
// {
//     for(int i = 1; i<n; i++)
//     {

//         int j = i;
//         while(j>=1 && arr[j-1] > arr[j])
//         {
//             int temp = arr[j-1];
//             arr[j-1] = arr[j];
//             arr[j] = temp;
//             --j;
//         }

//     }
// }


void insertionSort(int arr[], int n)
{
    int temp, j;
    for(int i = 1; i<n; i++)
    {
        temp = arr[i];
        j = i;
        while(j>=1 && arr[j-1]>temp)
        {
            arr[j] = arr[j-1];
            --j;
        }
        arr[j] = temp;
    }
}




int main()
{
    system("cls");
    int arr[] = {2, 1, 9, 7};
    int n = sizeof(arr)/sizeof(arr[0]);
    printArray(arr, n);
    insertionSort(arr, n);
    printArray(arr, n);
    return 0;
}