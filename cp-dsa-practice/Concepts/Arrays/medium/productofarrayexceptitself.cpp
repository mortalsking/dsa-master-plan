// Problem Link: https://leetcode.com/problems/product-of-array-except-self/
// Day 1 of 100 DSA Day Challenge.
// DS Used: Array
// Time Complexity: O(n)
// Space Complexity: O(1) (excluding the output array)

#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> output(nums.size(), 1);

        int left = 1;
        for (int i = 0; i < nums.size(); i++) {
            output[i] *= left;
            left *= nums[i];
        }

        int right = 1;
        for (int i = nums.size() - 1; i >= 0; i--) {
            output[i] *= right;
            right *= nums[i];
        }

        return output;        
    }
};