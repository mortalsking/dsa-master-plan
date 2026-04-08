// Problem Link: https://leetcode.com/problems/xor-after-range-multiplication-queries-i/description/
// Day 39 of 100 day DSA challenge
// Time Complexity: O(n + q) where n is the size of the nums array and q is the number of queries
// Space Complexity: O(1) as we are modifying the nums array in place and using only constant extra space



#include <bits/stdc++.h>
using namespace std;


class Solution {
    const int mod = 1000000007;
    #define ll long long
public:
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        for(auto &t: queries){
            int l = t[0];
            int r = t[1];
            int k = t[2];
            int v = t[3];
            int idx = l;
            while(idx <= r){
                ll temp = nums[idx];
                nums[idx] = (temp*v)%mod;
                idx+=k;
            }
        }
        int ans = 0;
        for(int num:nums){
            ans ^= num;
        }
        return ans;
    }
};