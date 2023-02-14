//
#include<iostream>

using namespace std;

int v1 = 20;

void add(int a)
{
    cout<<"This will work when you pass one arg of type int\n and a is "<<a<<endl;
}

void add(int v1, int v2) 
{
    cout<<"This is working because you passsed two integet type value"<<endl;
    cout<<"Sum is "<<v1+v2<<endl;
}

void add(double v1, double v2)
{
    cout<<"This is working because you passsed two double type value"<<endl;
    cout<<"Sum is "<<v1+v2<<endl;
}

void add(float v1, float v2)
{
    cout<<"This is working because you passsed two float type value"<<endl;
    cout<<"Sum is "<<v1+v2<<endl;
}



int main()
{
    system("cls");
    add(5.5);
    return 0;
}