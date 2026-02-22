// Problem Link: https://leetcode.com/problems/valid-parentheses/
// Day 1 of 100 DSA Day Challenge.
// DS Used: Stack
// Time Complexity: O(n) where n is the length of the input string
// Space Complexity: O(n) for the stack used to store opening parentheses


#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for (char ch : s) {
            if (ch == '(' || ch == '[' || ch == '{') {
                st.push(ch);
            } else {
                if (st.empty()) {
                    return false;
                }
                char top = st.top();
                st.pop();
                if (ch == ')' && top != '(') return false;
                if (ch == ']' && top != '[') return false;
                if (ch == '}' && top != '{') return false;
            }
        }
        return st.empty();
    }
};