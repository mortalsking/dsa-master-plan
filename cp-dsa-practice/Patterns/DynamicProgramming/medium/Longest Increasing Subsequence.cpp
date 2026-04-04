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
//Approach: patience sorting
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> tails; // tails[i] = smallest possible tail of increasing subsequence of length i+1
        
        for (int num : nums) {
            auto it = lower_bound(tails.begin(), tails.end(), num);
            
            if (it == tails.end()) {
                // num is greater than all tails, extend LIS
                tails.push_back(num);
            } else {
                // replace the first element >= num to maintain smallest tails
                *it = num;
            }
        }
        
        return tails.size();
    }
};