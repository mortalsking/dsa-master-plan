// Minimum Operation to Equalize a Binary String
//link: https://leetcode.com/problems/minimum-operation-to-equalize-a-binary-string/description/
// Day 6 of 100 DSA Day Challenge.
// DS Used: String
// Time Complexity: O(n) where n is the length of the string
// Space Complexity: O(1) as we are using only a constant amount of extra space


#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minOperations(string s, int k) {
        int zero = 0;
        int len = s.length();

        for (int i = 0; i < len; i++)
            zero += ~s[i] & 1;

        if (!zero)
            return 0;

        if (len == k)
            return ((zero == len) << 1) - 1;

        int base = len - k;

        int odd = max(
            (zero + k - 1) / k,
            (len - zero + base - 1) / base
        );

        odd += ~odd & 1;

        int even = max(
            (zero + k - 1) / k,
            (zero + base - 1) / base
        );

        even += even & 1;

        int res = INT_MAX;

        if ((k & 1) == (zero & 1))
            res = min(res, odd);

        if (~zero & 1)
            res = min(res, even);

        return res == INT_MAX ? -1 : res;
    }
};