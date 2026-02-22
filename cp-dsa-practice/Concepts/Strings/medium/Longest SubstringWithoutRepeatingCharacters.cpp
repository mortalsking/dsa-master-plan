// Problem Link: https://leetcode.com/problems/longest-substring-without-repeating-characters/
// Day 1 of 100 DSA Day Challenge.
// DS Used: String
// Time Complexity: O(n) where n is the length of the input string
// Space Complexity: O(min(m, n)) where m is the size of the character set and n is the length of the input string


#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int left = 0;
        int maxLength = 0;
        unordered_set<char> charSet;

        for (int right = 0; right < s.length(); right++) {
            while (charSet.find(s[right]) != charSet.end()) {
                charSet.erase(s[left]);
                left++;
            }

            charSet.insert(s[right]);
            maxLength = max(maxLength, right - left + 1);
        }

        return maxLength;        
    }
};