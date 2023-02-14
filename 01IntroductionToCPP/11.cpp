//
#include<iostream>
#include<vector>

using namespace std;

int main()
{
    system("cls");
    vector<int>v1(10, 5);
    vector <int> v2(v1.begin(), v1.end());
    for(auto x : v2)
    {
        cout<<x<<" ";
    }
    return 0;
}