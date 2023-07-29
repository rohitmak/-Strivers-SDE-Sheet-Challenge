#include <bits/stdc++.h>
using namespace std;

vector<int> majorityElementII(vector<int> &arr)
{
    vector<int> ans;
    map<int, int> mp;

    // last occurrence of the majority element:
    int mini = int(arr.size() / 3) + 1;

    for (int i = 0; i < arr.size(); i++)
    {
        mp[arr[i]]++;
        if (mp[arr[i]] == mini)
            ans.push_back(arr[i]);
        if (ans.size() == 2)
            break;
    }

    return ans;
}