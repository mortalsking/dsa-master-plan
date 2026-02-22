// Problem Link: https://leetcode.com/problems/first-missing-positive/
// Day 1 of 100 DSA Day Challenge.
// DS Used: Array   
// Time Complexity: O(n)
// Space Complexity: O(1)
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        for(int i=0;i<nums.size();i++){
            while(nums[i]>0 && nums[i]<=n && nums[nums[i]-1] != nums[i]){
                swap(nums[nums[i]-1],nums[i]);
            }
        }
        for(int i=0;i<nums.size();i++){
            if(nums[i] != i+1){
                return i+1;
            }
        }
        return n+1;
    }
};