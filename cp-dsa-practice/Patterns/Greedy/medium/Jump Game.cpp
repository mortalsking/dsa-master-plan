// Problem Link: https://leetcode.com/problems/jump-game/
// Day 13 of 100 DSA Day Challenge.
// DS Used: Greedy
// Time Complexity: O(n) where n is the length of the input vector
// Space Complexity: O(1) as we are using only a constant amount of extra space

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