//count first n terms
#include<iostream>

using namespace std;

void countFirstNTerms(int n)
{
    if(n == 1)
    {
        cout<<1<<" ";
        return;
    }
    countFirstNTerms(n-1);
    cout<<n<<" ";
}

int main()
{
    system("cls");
    countFirstNTerms(5);
    return 0;
}