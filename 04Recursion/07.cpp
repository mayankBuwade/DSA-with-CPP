//
#include<iostream>

using namespace std;

int multi(int v1, int v2)
{
    if(v1 == 0 || v2 == 0) return 0;
    if(v2 == 1) return v1;
    if(v2>v1)
    {
        int temp = v2;
        v2 = v1; 
        v1 = temp;
    }
    return v1 + multi(v1, v2-1);
}

int main()
{
    system("cls");
    cout<<multi(5, 3)<<endl;
    
    return 0;
}