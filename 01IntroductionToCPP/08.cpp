//
#include<iostream>

using namespace std;

template <typename T>
T add(T a, T b)
{
    return a + b;
}

template <typename T, typename U>
T add(T a, U b)
{
    return a + b;
}


int main()
{
    system("cls");
    cout<<add(5, 7)<<endl;
    cout<<add(5, 7.7)<<endl;
    return 0;
}