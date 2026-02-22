// Problem Link: https://leetcode.com/problems/roman-to-integer/
// Day 1 of 100 DSA Day Challenge.
// DS Used: String
// Time Complexity: O(n) where n is the length of the input string
// Space Complexity: O(1) for the hash map used to store Roman numeral values


#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int romanToInt(string s) {
        int res = 0;
        unordered_map<char, int> roman = {
            {'I', 1},
            {'V', 5},
            {'X', 10}, 
            {'L', 50},
            {'C', 100},
            {'D', 500},
            {'M', 1000}
        };

        for (int i = 0; i < s.size() - 1; i++) {
            if (roman[s[i]] < roman[s[i + 1]]) {
                res -= roman[s[i]];
            } else {
                res += roman[s[i]];
            }
        }

        return res + roman[s[s.size() - 1]];        
    }
};