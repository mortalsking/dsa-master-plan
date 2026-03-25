//link: https://practice.geeksforgeeks.org/problems/construct-product-matrix/1
// DS Used: Array
//day 25 of 100 DSA Day Challenge
// Time Complexity: O(n*m) where n and m are the dimensions of the grid. We need to fill the ans, xx and yy arrays, which takes O(n*m) time.
// Space Complexity: O(n*m) as we are using three additional 2D arrays ans, xx and yy to store the product values at each cell, which takes O(n*m) space.




#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid) {
    int n = grid.size();
    int m = grid[0].size();

    vector<vector<int>>ans(n,vector<int>(m));   
    vector<vector<int>>xx(n,vector<int>(m));   
    vector<vector<int>>yy(n,vector<int>(m));

    int mod =   12345;
    long long p = 1;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            xx[i][j] = p;
            p *= grid[i][j];
            p %= mod;
        }
    }
    p = 1;
    for(int i=n-1;i>=0;i--){
        for(int j=m-1;j>=0;j--){
            yy[i][j] = p;
            p *= grid[i][j];
            p %= mod;
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            long long mul = xx[i][j] * yy[i][j];

            ans[i][j] = mul % mod;
        }
    }
    return ans;
    }
};