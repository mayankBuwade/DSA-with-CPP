//anagram
#include<iostream>
#include<unordered_map>

using namespace std;

int main()
{
    system("cls");
    unordered_map<char, int> m;
    string s1 = "race";
    string s2 = "acer";
    bool isAnagagram = true;
    //key value pair
    for(auto ch:s1)
    {
        ++m[ch];
    }
    //checking in other string
    for(auto ch:s2)
    {
        if(m.find(ch) != m.end())
        {
            --m[ch];
        }
        else 
        {
            isAnagagram = false;
            break;
        }
    }

    if(isAnagagram)
    {
        for(auto ele:m)
        {
            if(ele.second != 0) 
            {
                isAnagagram = false;
                break;
            }
        }
    }

    if(isAnagagram)
    {
        cout<<s1<<" and "<<s2<<" are anagram"<<endl;
    }
    else cout<<s1<<" and "<<s2<<" are not anagram"<<endl;
    return 0;
}