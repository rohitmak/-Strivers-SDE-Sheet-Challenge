#include <bits/stdc++.h>
using namespace std;

int subarraysXor(vector<int> &arr, int x)
{
    int n = arr.size();
    int XOR = 0;
    map<int, int> mp;
    mp[XOR]++;
    int count = 0;

    for (int i = 0; i < n; i++)
    {
        XOR = XOR ^ arr[i];

        int k = XOR ^ x;

        count += mp[k];

        mp[XOR]++;
    }

    return count;
}