//tower of hanoi
//minimum steps:- 2^n - 1
#include<iostream>

using namespace std;

void TOH(int n, char src, char dest, char aux)
{
    if(n == 0) return;
    TOH(n-1, src, aux, dest);
    cout<<"Moving disk "<<n<<" from "<<src<<" "<<" to "<<dest<<endl;
    TOH(n-1, aux, dest, src);
}

int main()
{
    system("cls");
    TOH(4, 'A', 'C', 'B');
    return 0;
}