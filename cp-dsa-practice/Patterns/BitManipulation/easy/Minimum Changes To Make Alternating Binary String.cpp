//Minimum Changes To Make Alternating Binary String.cpp
//link: https://leetcode.com/problems/minimum-changes-to-make-alternating-binary-string/description/
// Day 10 of 100 DSA Day Challenge.
// DS Used: Strings
// Time Complexity: O(n) where n is the length of the string
// Space Complexity: O(1) as we are using only a constant amount of extra space


#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    int minOperations(string s) {
        int count = 0;
        int n = s.length();
        for(int i=0;i<s.length();i++){
            count += (s[i] ^i) & 1;
        }
        return min(count,n-count);
    }
};