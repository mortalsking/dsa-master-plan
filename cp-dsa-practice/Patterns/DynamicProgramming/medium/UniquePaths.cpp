// LeetCode 62. Unique Paths
// link: https://leetcode.com/problems/unique-paths/description/
// Day 7 of 100 DSA Day Challenge.
// DS Used: Dynamic Programming
// Time Complexity: O(m*n) where m and n are the dimensions of the grid
// Space Complexity: O(m*n) for the memoization table

#include <bits/stdc++.h>
using namespace std;

//brute force
class Solution {
public:
    int uniquePaths(int m, int n, int i = 0, int j = 0) {
        if(i >= m || j >= n) return 0;                                    // reached out of bounds - invalid
        if(i == m-1 && j == n-1) return 1;                                // reached the destination - valid solution
        return uniquePaths(m, n, i+1, j) + uniquePaths(m, n, i, j+1);     // try both down and right
    }
};

//memoization
class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n));
        return dfs(dp, 0, 0);
    }
    int dfs(vector<vector<int>>& dp, int i, int j) {
        if(i >= dp.size() || j >= dp[0].size())   return 0;     // out of bounds - invalid
        if(i == dp.size()-1 && j == dp[0].size()-1) return 1;     // reached end - valid path
        if(dp[i][j]) return dp[i][j];                           // directly return if already calculated
        return dp[i][j] = dfs(dp, i+1, j) + dfs(dp, i, j+1);    // store the result in dp[i][j] and then return
    }
};

//tabulation
class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, 1));
        for(int i = 1; i < m; i++)
            for(int j = 1; j < n; j++)
                dp[i][j] = dp[i-1][j] + dp[i][j-1];   // sum of unique paths ending at adjacent top and left cells
        return dp[m-1][n-1];         // return unique paths ending at cell (m-1, n-1)
    }
};
//space optimized tabulation
class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(2, vector<int>(n,1));
        for(int i = 1; i < m; i++)
            for(int j = 1; j < n; j++)
                dp[i & 1][j] = dp[(i-1) & 1][j] + dp[i & 1][j-1];   // <- &  used to alternate between rows
        return dp[(m-1) & 1][n-1];
    }
};
// combinatorial solution
class Solution {
public:
    int uniquePaths(int m, int n) {
        long ans = 1;
        for(int i = m+n-2, j = 1; i >= max(m, n); i--, j++) 
            ans = (ans * i) / j;
        return ans;
    }
};