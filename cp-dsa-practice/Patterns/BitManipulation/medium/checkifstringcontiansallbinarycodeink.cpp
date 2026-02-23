//Link: https://leetcode.com/problems/check-if-a-string-contains-all-binary-codes-of-size-k/
//day 2 of 100 days of code challenge
//Given a binary string s and an integer k, return true if every binary code of length k is a substring of s. Otherwise, return false.
//Time Complexity: O(n * k)
//Space Complexity: O(2^k * k)


#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool hasAllCodes(string s, int k) {
        unordered_set<string> st;

        for (int i = 0; i + k <= s.size(); i++) {
            st.insert(s.substr(i, k));
        }

        return st.size() == (int)pow(2, k);
    }
};