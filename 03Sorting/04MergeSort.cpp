//
#include<iostream>

using namespace std;

void Merge(int arr[], int left, int mid, int right)
{
    int subArrayOne = mid-left+1; //max size of temp arr 1
    int subArrayTwo = right-mid; //max size of temp arr 2

    int *leftArr = new int[subArrayOne];
    int *rightArr = new int[subArrayTwo];

    //copying data from main array to temp arrays
    for(int i = 0; i<subArrayOne; i++)
    {
        leftArr[i] = arr[left+i];
    }
    for(int i = 0; i<subArrayTwo; i++)
    {
        rightArr[i] = arr[mid+1+i];
    }

    //merging to orignal array
    int leftArrI = 0, 
        rightArrI = 0,
        mainArrI = left;

    while(leftArrI<subArrayOne && rightArrI<subArrayTwo)
    {
        if(leftArr[leftArrI] < rightArr[rightArrI])
        {
            arr[mainArrI] = leftArr[leftArrI];
            ++leftArrI;
        }
        else
        {
            arr[mainArrI] = rightArr[rightArrI];
            ++rightArrI;
        }
        ++mainArrI;
    }

    while(leftArrI<subArrayOne)
    {
        arr[mainArrI] = leftArr[leftArrI];
        ++leftArrI;
        ++mainArrI;
    }

    while(rightArrI<subArrayTwo)
    {
        arr[mainArrI] = rightArr[rightArrI];
        ++rightArrI;
        ++mainArrI;
    }
    
}

void MergeSort(int arr[], int begin, int end)
{
    if(begin>=end) return;
    int mid = begin + (end-begin)/2;
    MergeSort(arr, begin, mid);
    MergeSort(arr, mid+1, end);
    Merge(arr, begin, mid, end);
}

int main()
{
    system("cls");
    int arr[] = {5, 7, 9, 55, 1, 3, 0};
    int n = sizeof(arr)/sizeof(arr[0]);
    MergeSort(arr, 0, n-1);
    // print
    for(int i = 0; i<n; ++i)
    {
        cout<<arr[i]<<" ";
    }
    return 0;
}