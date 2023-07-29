#include <bits/stdc++.h>
using namespace std;

pair<int, int> missingAndRepeating(vector<int> &arr, int n)
{
    int xr = 0;
    for (int i = 0; i < n; i++)
    {
        xr = xr ^ arr[i];
        xr = xr ^ (i + 1);
    }

    int number = xr & ~(xr - 1);

    int zero = 0;
    int one = 0;
    for (int i = 0; i < n; i++)
    {
        if ((arr[i] & number) != 0)
        {
            one = one ^ arr[i];
        }
        else
        {
            zero = zero ^ arr[i];
        }
    }

    for (int i = 1; i <= n; i++)
    {
        if ((i & number) != 0)
        {
            one = one ^ i;
        }
        else
        {
            zero = zero ^ i;
        }
    }

    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == zero)
            count++;
    }

    pair<int, int> MR;

    if (count == 2)
    {
        MR = make_pair(one, zero);
        return MR;
    }
    else
    {
        MR = make_pair(zero, one);
        return MR;
    }
}
