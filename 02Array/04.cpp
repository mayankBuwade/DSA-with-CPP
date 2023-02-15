//check if palindrome character array
#include<iostream>
#include<cstring>

using namespace std;

bool checkIfPalindrome(char arr[], int n)
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
    char arr[] = "nayan";
    cout<<checkIfPalindrome(arr, strlen(arr));
    return 0;
}