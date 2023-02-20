//Program for Fibonacci numbers
//F0 F1 F2 F3 ..... Fn
//0   1  1 2 .......Fn
//0 1 1 2 3 5 8 13 21
#include<iostream>

using namespace std;

int fib(int n)
{
    if(n == 0 || n ==1) return n;
    return fib(n-1) + fib(n-2);
}

int main()
{
    system("cls");
    cout<<fib(6);
    return 0;
}