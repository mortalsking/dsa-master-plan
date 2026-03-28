// Problem Link: https://leetcode.com/problems/edit-distance/
// Day 29 of 100 DSA Day Challenge.
// DS Used: Dynamic Programming
// Time Complexity: O(m*n) where m and n are the lengths of the two input strings. We need to fill a 2D DP table of size (m+1) x (n+1), which takes O(m*n) time.
// Space Complexity: O(m*n) as we are using a 2D DP table to store the results of subproblems, which takes O(m*n) space.


#include <bits/stdc++.h>
using namespace std;

//approacch 1: Recursion with memoization
class Solution {
public:
    int minDistance(string word1, string word2) {
        int m = word1.size();
        int n = word2.size();
        vector<vector<int>>dp(m+1,vector<int>(n+1,0));
        for(int i=0;i<=m;i++){
            dp[i][0] = i;
        }
        for(int j=0;j<=n;j++){
            dp[0][j] = j;
        }
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                if(word1[i-1] == word2[j-1]){
                    dp[i][j] = dp[i-1][j-1];
                }else{
                    dp[i][j] = min({
                        dp[i-1][j] + 1,
                        dp[i][j-1] + 1,
                        dp[i-1][j-1] +1
                    });
                }
            }
        }
        return dp[m][n];
    }
};
//approach 2: Space optimized DP
class Solution {
public:
    int minDistance(string word1, string word2) {
        int m = word1.size();
        int n = word2.size();
        vector<int>prev(n+1),curr(n+1);
        for(int j=0;j<=n;j++){
            prev[j] = j;
        }
        for(int i=1;i<=m;i++){
            curr[0] = i;
            for(int j=1;j<=n;j++){
                if(word1[i-1] == word2[j-1]){
                    curr[j] = prev[j-1];
                }else{
                    curr[j] = min({
                        prev[j-1] + 1,
                        curr[j-1] + 1,
                        prev[j] + 1
                    });
                }
            }
            swap(prev,curr);
        }
        return prev[n];
    }
};
