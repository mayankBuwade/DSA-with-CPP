//subsets

#include<iostream>
#include<vector>

using namespace std;

vector<vector<int>> subset(vector<int>& nums)
{
    if(nums.empty()) return {{}};
    int currNum = nums.back();
    nums.pop_back();
    vector<vector<int>> res = subset(nums);
    int n = res.size();
    for(int i = 0; i<n; i++)
    {
        vector<int> temp = res[i];
        temp.push_back(currNum);
        res.push_back(temp);
    }
    return res;
}

int main()
{
    system("cls");
    vector<int> nums{1, 2, 3};
    vector<vector<int>> v = subset(nums);
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