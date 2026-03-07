// Problem Link: https://leetcode.com/problems/check-if-binary-string-has-at-most-one-segment-of-ones/description/
// Check if Binary String Has at Most One Segment of Ones.cpp
// Day 11 of 100 DSA Day Challenge.
// DS Used: Strings
// Time Complexity: O(n) where n is the length of the string
// Space Complexity: O(1) as we are using only a constant amount of extra space

#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    bool checkOnesSegment(string s) {
        for(int i=1;i<s.size();i++){
            if(s[i] == '1' && s[i-1] == '0') return false;
        }
        return true;
    }
};