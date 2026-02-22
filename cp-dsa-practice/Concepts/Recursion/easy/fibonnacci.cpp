// Problem Link: https://leetcode.com/problems/fibonacci-number/
// Day 1 of 100 DSA Day Challenge.
// DS Used: Recursion
// Time Complexity: O(2^n) where n is the input number
// Space Complexity: O(n) for the recursive call stack




#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int fib(int n) {
        if (n == 0 || n == 1)
            return n;

        return fib(n - 1) + fib(n - 2);
    }
};
