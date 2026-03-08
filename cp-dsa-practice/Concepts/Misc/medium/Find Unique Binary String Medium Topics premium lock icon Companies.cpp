// https://leetcode.com/problems/find-unique-binary-string/description/
// Day 13 of 100 DSA Day Challenge.
// DS Used: Misc
// Time Complexity: O(n) where n is the number of binary strings in the input vector
// Space Complexity: O(n) for storing the answer string which is of length n


#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        string ans = "";
        for(int i=0;i<nums.size();i++)
            ans += nums[i][i] == '0'? '1' : '0';
        return ans;
    }
};