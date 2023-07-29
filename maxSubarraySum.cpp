#include <bits/stdc++.h>
using namespace std;

long long maxSubarraySum(int arr[], int n)
{
    long long maxE = 0;
    long long sum = 0;

    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
        maxE = max(maxE, sum);

        if (sum < 0)
            sum = 0;
    }

    return maxE;
}