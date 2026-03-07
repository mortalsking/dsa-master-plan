// Minimum Number of Flips to Make the Binary String Alternating
//link: https://leetcode.com/problems/minimum-number-of-flips-to-make-the-binary-string-alternating/description/
// Day 12 of 100 DSA Day Challenge.
// DS Used: String
// Time Complexity: O(n) where n is the length of the string
// Space Complexity: O(1) as we are using only a constant amount of extra space




#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    int minFlips(string s) {
        int n = s.length();
        int res = n;
        int op[2] = {0,0};
        for(int i=0;i<n;i++){
            op[(s[i] ^i) & 1]++;
        }
        for(int i=0;i<n;i++){
            op[(s[i]^i) & 1]--;
            op[(s[i]^(n+i)) & 1]++;
            res = min(res,min(op[0],op[1])); 
        }
        return res;
    }
};