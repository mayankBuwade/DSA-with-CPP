//check if palindrome character array
#include<iostream>

using namespace std;

bool checkIfPalindrome(int arr[], int n)
{
    int left = 0;
    int right = n-1;
    while(left<right)
    {
        if(arr[left] != arr[right])
        {
            return false;
        }
        right--;
        left++;
    }
    return true;
}

int main()
{
    system("cls");
    int arr[] = {1,2, 3, 3, 2, 1};
    int length = sizeof(arr)/sizeof(arr[0]);
    cout<<checkIfPalindrome(arr, length);
    return 0;
}