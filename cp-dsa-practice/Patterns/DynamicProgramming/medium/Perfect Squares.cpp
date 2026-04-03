//link: https://leetcode.com/problems/perfect-squares/description/
// Time Complexity: O(n*sqrt(n)) where n is the input number. We fill a DP table of size n, and for each entry, we iterate up to sqrt(n) to find the minimum count of perfect squares.
// Space Complexity: O(n) for the DP table.
//day 35 of 100 day challenge


#include <bits/stdc++.h>
using namespace std;


//Approach:bottom-up
class Solution {
public:
    int numSquares(int n) {
        vector<int>dp(n+1,INT_MAX);
        dp[0] = 0;
        for(int i=1;i<=n;i++){
            for(int j = 1; j*j <= i;j++){
                dp[i] = min(dp[i],dp[i-j*j]+1);
            }
        }
        return dp[n];
    }
};
//Approach: bfs
class Solution {
public:
    int numSquares(int n) {
        vector<int> squares;
        for (int i = 1; i * i <= n; i++) {
            squares.push_back(i * i);
        }
        
        vector<bool> visited(n + 1, false);
        queue<int> q;
        q.push(0);
        visited[0] = true;
        
        int level = 0;
        while (!q.empty()) {
            int size = q.size();
            level++;
            
            for (int i = 0; i < size; i++) {
                int curr = q.front();
                q.pop();
                
                for (int square : squares) {
                    int next = curr + square;
                    if (next == n) return level;
                    if (next > n) break;
                    if (!visited[next]) {
                        visited[next] = true;
                        q.push(next);
                    }
                }
            }
        }
        
        return level;
    }
};
//Approach: Lagrange's Four Square Theorem)
class Solution {
public:
    int numSquares(int n) {
        // Check if n is a perfect square
        int sqrtN = sqrt(n);
        if (sqrtN * sqrtN == n) return 1;
        
        // Check if n can be expressed as sum of 2 squares
        for (int i = 1; i * i <= n; i++) {
            int remainder = n - i * i;
            int sqrtRem = sqrt(remainder);
            if (sqrtRem * sqrtRem == remainder) return 2;
        }
        
        // Check if n is of form 4^a (8b + 7)
        while (n % 4 == 0) n /= 4;
        if (n % 8 == 7) return 4;
        
        return 3;
    }
};