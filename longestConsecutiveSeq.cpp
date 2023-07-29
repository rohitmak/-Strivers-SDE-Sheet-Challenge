#include <bits/stdc++.h>
using namespace std;

int lengthOfLongestConsecutiveSequence(vector<int> &arr, int n)
{
    sort(arr.begin(), arr.end());
    int ans = 1;
    int curr = 1;
    int prev = arr[0];

    for (int i = 1; i < n; i++)
    {
        if (arr[i] == prev + 1)
            curr++;
        else if (arr[i] != prev)
            curr = 1;
        prev = arr[i];
        ans = max(ans, curr);
    }

    return ans;
}