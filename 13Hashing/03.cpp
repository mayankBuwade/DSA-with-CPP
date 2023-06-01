//
#include<iostream>
#include<unordered_map>


using namespace std;

int main()
{
    system("cls");
    unordered_map<char, int> m;
    m['c'] = 15;
    m.insert(make_pair('e', 10));
    for(auto e:m)
    {
        cout<<e.first<<" "<<e.second<<endl;
    }
    return 0;
}