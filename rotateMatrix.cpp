#include <bits/stdc++.h>
using namespace std;

void rotateMatrix(vector<vector<int>> &mat, int n, int m)
{
    int left = 0, right = m - 1, top = 0, bottom = n - 1;

    while (left < right && top < bottom)
    {
        int temp = mat[top][left];

        for (int col = left + 1; col <= right; col++)
        {
            int t = mat[top][col];
            mat[top][col] = temp;
            temp = t;
        }
        top++;

        for (int row = top; row <= bottom; row++)
        {
            int t = mat[row][right];
            mat[row][right] = temp;
            temp = t;
        }
        right--;

        for (int col = right; col >= left; col--)
        {
            int t = mat[bottom][col];
            mat[bottom][col] = temp;
            temp = t;
        }
        bottom--;

        for (int row = bottom; row >= top; row--)
        {
            int t = mat[row][left];
            mat[row][left] = temp;
            temp = t;
        }
        left++;

        mat[top - 1][left - 1] = temp;
    }
}