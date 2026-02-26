//link: https://leetcode.com/problems/number-of-steps-to-reduce-a-number-in-binary-representation-to-one/description/
// Day 5 of 100 DSA Day Challenge.
// Time Complexity: O(n) where n is the number of bits in the binary representation of the number
// Space Complexity: O(1) as we are using only a constant amount of space



#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    int numSteps(string s) {
        int steps = 0, carry = 0;
        for (int i = s.length() - 1; i > 0; i--) {
            if ((s[i] & 1) + carry == 1) {
                steps += 2;
                carry = 1;
            } else
                steps += 1;
        }
        
        return steps + carry;
    }
};