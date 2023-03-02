//
#include<iostream>

using namespace std;

void permutation(char arr[], int left, int right)
{
    if(left == right)
    {
        cout<<arr<<endl;
        return;
    }
    for(int i = left; i<=right; i++)
    {
        swap(arr[left], arr[i]);
        permutation(arr, left+1, right);
        swap(arr[left], arr[i]);
    }
}

int main()
{
    system("cls");
    char arr[] = "abc";
    permutation(arr, 0, 2);
    return 0;
}