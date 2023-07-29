#include <bits/stdc++.h>
using namespace std;

vector<vector<long long int>> printPascal(int n)
{
    vector<vector<long long int>> pascal(n, vector<long long int>(0));

    for (int i = 0; i < n; i++)
        pascal[i].push_back(1);

    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j < i; j++)
        {
            pascal[i].push_back(pascal[i - 1][j - 1] + pascal[i - 1][j]);
        }
        pascal[i].push_back(1);
    }

    return pascal;
}
