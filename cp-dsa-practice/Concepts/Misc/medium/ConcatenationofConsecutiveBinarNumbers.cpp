// Problem Link: https://leetcode.com/problems/concatenation-of-consecutive-binary-numbers/
// Day 7 of 100 DSA Day Challenge.
// DS Used: String  
// Time Complexity: O(n) where n is the input number
// Space Complexity: O(1) as we are using only a constant amount of extra space

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int concatenatedBinary(int n) {
        const int MOD = 1e9 + 7;
        long long res = 0;
        int bits = 0;

        for(int i=1; i<=n; i++){
            if((i & (i-1)) == 0) bits++;
            res = ((res<<bits) | i) % MOD;
        }
        return res;
    }
};