//link: https://leetcode.com/problems/longest-increasing-subsequence/description/
// Time Complexity: O(n^2) where n is the length of the input array. We have two nested loops to fill the DP table.
// Space Complexity: O(n) for the DP table.
//day 35 of 100 day challenge




#include <bits/stdc++.h>
using namespace std;


//Approach: bottom-up
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;
        
        // dp[i] = length of LIS ending at index i
        vector<int> dp(n, 1);
        int maxLength = 1;
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (nums[j] < nums[i]) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
            maxLength = max(maxLength, dp[i]);
        }
        
        return maxLength;
    }
};