#include <bits/stdc++.h>
using namespace std;

int LongestSubsetWithZeroSum(vector<int> arr)
{
    int n = arr.size();
    unordered_map<int, int> mp;
    int maxE = 0;
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
        if (sum == 0)
        {
            maxE = i + 1;
        }
        else
        {
            if (mp.find(sum) != mp.end())
                maxE = max(maxE, i - mp[sum]);
            else
                mp[sum] = i;
        }
    }
    return maxE;
}