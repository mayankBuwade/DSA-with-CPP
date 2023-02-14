//find the largest element in the array
#include<iostream> 
#include<climits> 

using namespace std;

int main()
{
    system("cls");
    int arr[] = {5, -1,  7, 9, 1, 4, 0, -99, 8};
    int max = INT_MIN;
    int n = sizeof(arr)/sizeof(arr[0]);

    for(int i = 0; i<n; i++)
    {
        if(max<arr[i])
        {
            max = arr[i];
        }
    }
    cout<<"Max value is "<<max;
    return 0;
}