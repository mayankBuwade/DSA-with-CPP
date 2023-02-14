//
#include<iostream>

using namespace std;

void fun()
{
    static int a = 10;
    cout<<a<<endl;
    ++a;
}

int main()
{
    system("cls");
    fun();
    fun();
    fun();
    return 0;
}