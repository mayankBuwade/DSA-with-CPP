//find the smalles element in the array
#include<iostream> 
#include<climits> 

using namespace std;

int main()
{
    system("cls");
    int arr[] = {5, -1,  7, 9, 1, 4, 0, -99, 8};
    int min = INT_MAX;
    int n = sizeof(arr)/sizeof(arr[0]);

    for(int i = 0; i<n; i++)
    {
        if(min>arr[i])
        {
            min = arr[i];
        }
    }
    cout<<"Min value is "<<min;
    return 0;
}