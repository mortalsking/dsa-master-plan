// Problem Link: https://leetcode.com/problems/fizz-buzz/
// Day 7 of 100 DSA Day Challenge.
// DS Used: Array
// Time Complexity: O(n) where n is the input number
// Space Complexity: O(n) where n is the input number


#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    vector<string> fizzBuzz(int n) {
        vector<string> ans;

        for (int i = 1; i <= n; i++) {
            ans.push_back(
                (i % 15 == 0) ? "FizzBuzz" :
                (i % 5 == 0)  ? "Buzz" :
                (i % 3 == 0)  ? "Fizz" :
                to_string(i)
            );
        }

        return ans;
    }
};