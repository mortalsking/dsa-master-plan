// Link: https://leetcode.com/problems/equal-sum-grid-partition/description/
// DS Used: Array
//day 26 of 100 DSA day challenge
// Time Complexity: O(m*n) where m and n are the dimensions of the grid. We need to calculate the total sum and then check for possible partitions, which takes O(m*n) time.
// Space Complexity: O(1) as we are using only a constant amount of extra space to store the total sum, target sum, and the current sum while checking for partitions.



#include <bits/stdc++.h>
using namespace std;



class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        long long total = 0;
        
        for (auto &row : grid)
            for (int x : row)
                total += x;
        
        if (total % 2) return false;
        
        long long target = total / 2, sum = 0;
        
        for (int i = 0; i < m - 1; i++) {
            for (int j = 0; j < n; j++)
                sum += grid[i][j];
            if (sum == target) return true;
        }
        
        sum = 0;
        
        for (int j = 0; j < n - 1; j++) {
            for (int i = 0; i < m; i++)
                sum += grid[i][j];
            if (sum == target) return true;
        }
        
        return false;
    }
};