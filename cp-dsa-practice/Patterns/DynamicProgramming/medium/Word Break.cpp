// Problem Link: https://leetcode.com/problems/word-break/
// Day 29 of 100 DSA Day Challenge.
// DS Used - Dynamic Programming
// Time Complexity - O(n*m*k) where n is the length of the input string s, m is the number of words in the wordDict and k is the average length of the words in the wordDict. We are iterating through the input string and for each position, we are iterating through the wordDict and checking if the current word matches with the substring of s.
// Space Complexity - O(n) where n is the length of the input string s. We are using a boolean vector dp of size n+1 to store the results of subproblems, which takes O(n) space.



#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<bool>dp(s.size()+1,false);
        dp[0] = true;
        for(int i=1;i<=s.size();i++){
            for(const string& w: wordDict){
                int start = i-w.length();
                if(start >= 0 && dp[start] && s.substr(start,w.length()) == w){
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[s.size()];
    }
};