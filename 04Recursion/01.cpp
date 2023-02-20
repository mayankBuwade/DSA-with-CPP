//factorial using recursion
#include<iostream>

using namespace std;

int factorial(int n)
{
    if(n == 0) return 1;
    return n * factorial(n-1);
}

int factorialUsingLoop(int n)
{
    int fact = 1;
    for(int i = 1; i<=n; i++)
    {
        fact = fact*i;
    }
    return fact;
}

int main()
{
    system("cls");
    cout<<factorial(5)<<endl;
    return 0;
}