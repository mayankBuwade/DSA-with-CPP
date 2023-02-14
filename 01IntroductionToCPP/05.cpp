//
#include<iostream>

using namespace std;

void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

int main()
{
    system("cls");
    int v1 = 10, v2 = 20;
    cout<<"Before swap "<<v1<<" "<<v2<<endl;
    swap(v1, v2);
    cout<<"After swap "<<v1<<" "<<v2<<endl;
    return 0;
}