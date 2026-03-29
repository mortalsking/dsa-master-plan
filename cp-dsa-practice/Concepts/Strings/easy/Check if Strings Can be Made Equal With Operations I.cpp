// Problem Link: https://leetcode.com/problems/check-if-strings-can-be-made-equal-with-operations-i/description/
// Day 31 of 100 DSA Day Challenge.
// DS Used - Strings
// Time Complexity - O(1) as we are only comparing 4 characters of the input strings.
// Space Complexity - O(1) as we are not using any extra space to store the results, we are only using a few variables to compare the characters of the input strings.


#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool canBeEqual(string s1, string s2) {
        return ((s1[0] == s2[0] && s1[2] == s2[2]) ||
                (s1[0] == s2[2] && s1[2] == s2[0])) &&
                ((s1[1] == s2[1] && s1[3] == s2[3]) ||
                (s1[1] == s2[3] && s1[3] == s2[1]));
    }
};