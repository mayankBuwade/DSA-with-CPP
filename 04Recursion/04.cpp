//count in reverse order
#include<iostream>

using namespace std;

void countInReverseOrder(int n)
{
    if(n == 1)
    {
        cout<<1<<endl;
        return;
    }
    cout<<n<<" ";
    return countInReverseOrder(n-1);
}

int main()
{
    system("cls");
    countInReverseOrder(5);
    return 0;
}