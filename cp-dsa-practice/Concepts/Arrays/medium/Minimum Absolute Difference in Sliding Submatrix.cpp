//link: https://leetcode.com/problems/minimum-absolute-difference-in-sliding-submatrix/description/
// Day 22 of 100 DSA Day Challenge.
// DS Used: Array
// Time Complexity: O(m*n*k^2*log(k^2)) where m and n are the dimensions of the grid, and k is the size of the submatrix. We iterate through each possible starting point of the submatrix (m-k+1)*(n-k+1) and for each submatrix, we collect its elements (k^2) and sort them (k^2*log(k^2)) to find the minimum absolute difference.
// Space Complexity: O(k^2) for storing the elements of the current submatrix before sorting. The output space is O((m-k+1)*(n-k+1)) for the result matrix, but this is not considered extra space as it is required for the output.




#include <bits/stdc++.h>    
using namespace std;



class Solution {
public:
    vector<vector<int>> minAbsDiff(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> ans(m - k + 1, vector<int>(n - k + 1));

        for (int i = 0; i <= m - k; i++) {
            for (int j = 0; j <= n - k; j++) {
                vector<int> v;
                for (int x = i; x < i + k; x++)
                    for (int y = j; y < j + k; y++)
                        v.push_back(grid[x][y]);

                sort(v.begin(), v.end());
                v.erase(unique(v.begin(), v.end()), v.end());

                if (v.size() <= 1) {
                    ans[i][j] = 0;
                } else {
                    int mn = INT_MAX;
                    for (int p = 0; p < (int)v.size() - 1; p++)
                        mn = min(mn, v[p+1] - v[p]);
                    ans[i][j] = mn;
                }
            }
        }
        return ans;
    }
};