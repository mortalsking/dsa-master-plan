// 64. Minimum Path Sum
// Link: https://leetcode.com/problems/minimum-path-sum/
// Day 9 of 100 DSA Day Challenge.
// DS Used: Dynamic Programming
// Time Complexity: O(m*n) where m and n are the dimensions of the grid
// Space Complexity: O(m*n) for the dp table

#include <bits/stdc++.h>
using namespace std;

//approach 1: brute force using recursion
int minPathSum(vector<vector<int>>& grid) { return calculatePathSum(grid, 0, 0, 0); }

int calculatePathSum(vector<vector<int>>& grid, int i, int j, int sum) { // Base case: we have reached the bottom right corner 
if (i == grid.size() - 1 && j == grid[0].size() - 1) { return sum + grid[i][j]; }

// Calculate the minimum path sum by moving right and down
int rightSum = INT_MAX;
int downSum = INT_MAX;
    if (i < grid.size() - 1) {
    downSum = calculatePathSum(grid, i + 1, j, sum + grid[i][j]);
    }
    if (j < grid[0].size() - 1) {
    rightSum = calculatePathSum(grid, i, j + 1, sum + grid[i][j]);
    }

// Return the minimum path sum
    return min(rightSum, downSum);
}

//approach 2: tabulation
int minPathSum(vector<vector<int>>& grid) {
    int m = grid.size();
    int n = grid[0].size();

    // Traverse the first row and first column and calculate the sum
    // of each cell by adding the value of the previous cell in the same row or column
    for(int i=1; i<m; i++) {
        grid[i][0] += grid[i-1][0];
    }
    for(int j=1; j<n; j++) {
        grid[0][j] += grid[0][j-1];
    }

    // Traverse the remaining cells and calculate the minimum sum to reach each cell
    for(int i=1; i<m; i++) {
        for(int j=1; j<n; j++) {
            grid[i][j] += min(grid[i-1][j], grid[i][j-1]);
        }
    }

    // Return the minimum sum to reach the last cell
    return grid[m-1][n-1];
}

//approach 3: space optimized tabulation
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<int> pre(m, grid[0][0]);
        vector<int> cur(m, 0);
        for (int i = 1; i < m; i++)
            pre[i] = pre[i - 1] + grid[i][0];
        for (int j = 1; j < n; j++) { 
            cur[0] = pre[0] + grid[0][j]; 
            for (int i = 1; i < m; i++)
                cur[i] = min(cur[i - 1], pre[i]) + grid[i][j];
            swap(pre, cur); 
        }
        return pre[m - 1];
    }
};

//approach 4: space optimized tabulation with single array
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<int> cur(m, grid[0][0]);
        for (int i = 1; i < m; i++)
            cur[i] = cur[i - 1] + grid[i][0]; 
        for (int j = 1; j < n; j++) {
            cur[0] += grid[0][j]; 
            for (int i = 1; i < m; i++)
                cur[i] = min(cur[i - 1], cur[i]) + grid[i][j];
        }
        return cur[m - 1];
    }
};