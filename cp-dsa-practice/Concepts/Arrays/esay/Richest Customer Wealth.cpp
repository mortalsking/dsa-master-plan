// 1672. Richest Customer Wealth
// https://leetcode.com/problems/richest-customer-wealth/description/
// Day 7 of 100 DSA Day Challenge.
// DS Used: Array
// Time Complexity: O(m*n) where m is the number of customers and n is the number of accounts per customer
// Space Complexity: O(1)

#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int result = 0;
        for(int i=0;i<accounts.size();i++){
            int sum = 0;
            for(int j=0;j<accounts[0].size();j++){
                sum += accounts[i][j];
                result = max(result,sum);
            }
        }
        return result;
    }
};