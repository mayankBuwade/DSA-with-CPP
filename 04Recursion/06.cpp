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


bool isSortedInAsc(int arr[], int n)
{
    if(n-1 == 0) return true;
    if(arr[n-1] < arr[n-2])
    {
        return false;
    }
    return isSortedInAsc(arr, n-1);
}

bool isSortedInDesc(int arr[], int n)
{
    if(n-1 == 0) return true;
    if(arr[n-1] > arr[n-2])
    {
        return false;
    }
    return isSortedInDesc(arr, n-1);
}

int main()
{
    system("cls");
    int arr[] = {5, 4, 3, 2, 1};
    int n = sizeof(arr)/sizeof(arr[0]);
    //cout<<isSortedInDesc(arr, n);
    
    return 0;
}