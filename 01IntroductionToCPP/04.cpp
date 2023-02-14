//
#include<iostream>

using namespace std;

void swap(int *v1, int *v2)
{
    int temp = *v1;
    *v1 = *v2;
    *v2 = temp;
}

int main()
{
    system("cls");
    int v1 = 10, v2 = 20;
    cout<<"Before swap "<<v1<<" "<<v2<<endl;
    swap(&v1, &v2);
    cout<<"After swap "<<v1<<" "<<v2<<endl;
    return 0;
}