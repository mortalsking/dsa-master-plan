// Problem Link: https://leetcode.com/problems/contains-duplicate/
// Day 1 of 100 DSA Day Challenge.
// Time Complexity: O(n)
// Space Complexity: O(n)
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int,int> seen;
        for(int num:nums){
            if(seen[num]>=1)
                return true;
            seen[num]++;
        }
        return false;
    }
};