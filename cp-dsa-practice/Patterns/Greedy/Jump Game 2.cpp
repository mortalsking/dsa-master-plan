// Problem Link: https://leetcode.com/problems/jump-game-ii/
// Day 16 of 100 DSA Day Challenge.
// DS Used: Greedy
// Time Complexity: O(n) where n is the length of the input vector
// Space Complexity: O(1) as we are using only a constant amount of extra space


#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    int jump(vector<int>& nums) {
        int near = 0,far = 0,jumps = 0;
        while(far<nums.size()-1){
            int farthest = 0;
            for(int i=near;i<=far;i++){
                farthest = max(farthest,i+nums[i]);
            }
            near = far+1;
            far = farthest;
            jumps++;
        }
        return jumps;
    }
};