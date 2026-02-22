// Problem Link: https://leetcode.com/problems/single-number/
// Day 1 of 100 DSA Day Challenge.
// DS Used: Array
// Time Complexity: O(n) where n is the size of the input array
// Space Complexity: O(1)




#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    int singleNumber(vector<int>& nums) { 
       int ans=0;
	   for(auto x:nums)
	   ans^=x;
	   return ans;
    }
};