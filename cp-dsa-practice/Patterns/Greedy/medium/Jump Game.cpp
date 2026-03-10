// Problem Link: https://leetcode.com/problems/jump-game/
// Day 13 of 100 DSA Day Challenge.
// DS Used: Greedy
// Time Complexity: O(n) where n is the length of the input vector
// Space Complexity: O(1) as we are using only a constant amount of extra space





// Approach: greedy

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int goal  = nums.size()-1;
        for(int i=nums.size()-2;i>=0;i--){
            if(i + nums[i] >= goal){
                goal = i;
            }
        }
        return goal == 0;
    }
};
// Approach: backtracking (TLE)
class Solution {
    public:
    bool canJump(vector<int>& nums) {
              return solve(0,nums); 
    }
    bool solve(int i,vector<int> nums){
        
        if(i==nums.size()-1) return true;
        int reachable=i+nums[i];
        
        for(int k=i+1;k<=reachable;k++){
                  if(solve(k,nums)){
                return true;
            }      
        }
        return false;
    }
};

// Approach: dynamic programming (TLE)
class Solution {
    vector<int> memo;
    public:
    bool canJump(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n,0);
        dp[0]=true;
        
        for(int i=1;i<n;i++){
             for(int j=i-1;j>=0;j--){
                 if(dp[j] && j+nums[j]>=i){
                     dp[i]=true;
                     break;
                 }       
             }           
        }
        return dp[n-1];
  }
};