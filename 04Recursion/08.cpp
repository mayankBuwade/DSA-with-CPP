//power of two
#include<iostream>

using namespace std;

bool isPowerOfTwo(int x)
{
    if(x == 1 || x == 0) return x;
    if(x%2) return false;
    return isPowerOfTwo(x/2);
}

bool isPowerOfTwoUsingLoop(int x)
{
    while(x)
    {
        if(x == 1) return true;
        if(x%2) return false;
        x = x/2;
    }
    return x;
}

int main()
{
    system("cls");
    cout<<isPowerOfTwoUsingLoop(64);
    return 0;
}