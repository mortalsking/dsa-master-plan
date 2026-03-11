// Link: https://leetcode.com/problems/complement-of-base-10-integer/description/
// Day 16 of 100 DSA Day Challenge.
// DS Used: Bit Manipulation
//  Time Complexity: O(log n) where n is the input number
// Space Complexity: O(1) as we are using only a constant amount of extra space

#include<bits/stdc++.h>
using namespace std;


// Approach: bit manipulation
class Solution {
public:
    int bitwiseComplement(int n) {
        int mask = 1;
        while(mask<n){
            mask<<=1;
            mask++;
        }
        return mask^n;
    }
};
// Approach: bit manipulation (optimized)
class Solution {
public:
    int bitwiseComplement(int n) {
        if(n == 0) return 1 ; 
        int mask = (1 << (32 - __builtin_clz(n))) - 1; 
        return n ^ mask ;
    }
};