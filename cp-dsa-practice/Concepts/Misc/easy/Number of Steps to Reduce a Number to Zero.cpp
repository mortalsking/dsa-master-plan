// 1342. Number of Steps to Reduce a Number to Zero
// https://leetcode.com/problems/number-of-steps-to-reduce-a-number-to-zero/description/
// Day 7 of 100 DSA Day Challenge.
// DS Used: Bit Manipulation
// Time Complexity: O(log n) where n is the input number
// Space Complexity: O(1)

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numberOfSteps(int num) {
        int count = 0;
        while(num){
            num = num & 1 ? num-1:num>>1;
            count++;
        }
        return count;
    }
};