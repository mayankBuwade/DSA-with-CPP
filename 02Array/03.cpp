//reverse array
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

void reverseArray(int arr[], int n)
{
    int left = 0;
    
    int right = n-1;

    while(left<right)
    {
        int temp = arr[left];
        arr[left] = arr[right];
        arr[right] = temp;
        ++left;
        --right;
    }
}

int main()
{
    system("cls");
    int arr[] = {1, 2, 3, 4, 5};
    int n = sizeof(arr)/sizeof(arr[0]);
    printArray(arr, n);
    reverseArray(arr, n);
    printArray(arr, n);
    return 0;
}