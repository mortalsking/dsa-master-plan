// Problem Link: https://leetcode.com/problems/maximum-non-negative-product-in-a-matrix/
// Day 25 of 100 DSA Day Challenge.
// DS Used: Array
// Time Complexity: O(m*n) where m and n are the dimensions of the grid. We need to fill the mx and mn arrays, which takes O(m*n) time.
// Space Complexity: O(m*n) as we are using two additional 2D arrays mx and mn to store the maximum and minimum products at each cell, which takes O(m*n) space.



#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    int maxProductPath(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        const long long MOD = 1e9 + 7;

        vector<vector<long long >>mx(m,vector<long long>(n,0));
        vector<vector<long long >>mn(m,vector<long long>(n,0));

        mx[0][0] = mn[0][0] = grid[0][0];

        for(int j=1;j<n;j++){
            mx[0][j] = mn[0][j] = mx[0][j-1] * grid[0][j];
        }
        for(int i=1;i<m;i++){
            mx[i][0] = mn[i][0] = mx[i-1][0] * grid[i][0];
        }
        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                long long x = grid[i][j];

                long long a = mx[i-1][j] * x;
                long long b = mn[i-1][j] * x;
                long long c = mx[i][j-1] * x;
                long long d = mn[i][j-1] * x;

                mx[i][j] = max({a,b,c,d});  
                mn[i][j] = min({a,b,c,d});  
            }
        }
        long long ans = mx[m-1][n-1];
        if(ans<0) return -1;
        return ans%MOD;
    }
};