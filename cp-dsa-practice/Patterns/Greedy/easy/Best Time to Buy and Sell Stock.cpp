// Problem Link: https://leetcode.com/problems/best-time-to-buy-and-sell-stock/
// Day 15 of 100 DSA Day Challenge.
// DS Used: Greedy
// Time Complexity: O(n) where n is the length of the input vector
// Space Complexity: O(1) as we are using only a constant amount of extra space
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int todayprice = prices[0];
        int profit = 0;
        for(int i=1;i<prices.size();i++){
            if(todayprice>prices[i]) todayprice = prices[i];
            profit = max(profit,prices[i]-todayprice);
        }
        return profit;
    }
};