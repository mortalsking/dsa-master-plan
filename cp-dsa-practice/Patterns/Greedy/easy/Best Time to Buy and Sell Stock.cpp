// Problem Link: https://leetcode.com/problems/best-time-to-buy-and-sell-stock/
// Day 15 of 100 DSA Day Challenge.
// DS Used: Greedy
// Time Complexity: O(n) where n is the length of the input vector
// Space Complexity: O(1) as we are using only a constant amount of extra space
#include<bits/stdc++.h>
using namespace std;


// Approach: greedy
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
// Approach: brute force (TLE)
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size(), maxProfit = 0;
        for(int i=0; i<n-1; i++){
            for(int j=i+1; j<n; j++){
                if(prices[j] - prices[i] > maxProfit){
                    maxProfit = prices[j] - prices[i];
                }
            }
        }
        return maxProfit;
    }
};
// Approach: dynamic programming (TLE)
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size(), maxProfit = 0;
        for(int i=0; i<n-1; i++){
            for(int j=i+1; j<n; j++){
                if(prices[j] - prices[i] > maxProfit){
                    maxProfit = prices[j] - prices[i];
                }
            }
        }
        return maxProfit;
    }
};
// Approach: greedy (optimized)
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int buyAtPrice = INT_MAX;
        int maxProfit = 0;
        for(int i=0; i<n; i++){
            buyAtPrice = min(buyAtPrice, prices[i]);
            maxProfit = max(maxProfit, prices[i] - buyAtPrice); 
        }
        return maxProfit;
    }
};