//
#include<iostream>

using namespace std;

void f1();
void f2();
void f3();

void f1()
{
    cout<<"This is f1"<<endl;
    f1();
    cout<<"Back to f1"<<endl;

}

void f2()
{
    cout<<"This is f2"<<endl;
    f3();
    cout<<"Back to f2"<<endl;
}

void f3()
{
    cout<<"This is f3"<<endl;
    f1();
    cout<<"Returning to f2"<<endl;
}


int main()
{
    system("cls");
    cout<<"This is main"<<endl;
    f1();
    cout<<"Back to main"<<endl;
    return 0;
}