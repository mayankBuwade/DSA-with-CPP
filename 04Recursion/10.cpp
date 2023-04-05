//subsets

#include<iostream>
#include<vector>

using namespace std;

vector<vector<char>> subset(vector<char>& nums)
{
    if(nums.empty()) return {{}};
    char currNum = nums.back();
    nums.pop_back();
    vector<vector<char>> res = subset(nums);
    int n = res.size();
    for(int i = 0; i<n; i++)
    {
        vector<char> temp = res[i];
        temp.push_back(currNum);
        res.push_back(temp);
    }
    return res;
}

int main()
{
    system("cls");
    vector<char> nums{'a', 'd', 'a', 'a'};
    vector<vector<char>> v = subset(nums);
    for(int i = 0; i<v.size(); i++)
    {
        for(int j = 0; j<v[i].size(); j++)
        {
            cout<<v[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}