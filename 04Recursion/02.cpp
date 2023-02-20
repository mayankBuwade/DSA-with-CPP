//sum of first n terms
#include<iostream>

using namespace std;

int sumOfFirstNTerms(int n)
{
    if(n == 1) return 1;
    return n + sumOfFirstNTerms(n-1);
}

int main()
{
    system("cls");
    cout<<sumOfFirstNTerms(5)<<endl;
    return 0;
}