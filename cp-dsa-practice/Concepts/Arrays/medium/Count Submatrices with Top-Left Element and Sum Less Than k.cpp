//link: https://leetcode.com/problems/count-submatrices-with-top-left-element-and-sum-less-than-k/description/
// Day 20 of 100 DSA Day Challenge.
// DS Used: Array
// Time Complexity: O(r*c) where r and c are the dimensions of the grid. We iterate through each cell of the grid once to calculate the prefix sums and count the submatrices, resulting in a time complexity of O(r*c).
// Space Complexity: O(1) if we don't consider the input grid as extra space, since we are modifying the input grid in place to store the prefix sums. If we consider the input grid as extra space, then the space complexity is O(r*c) due to the input grid itself.


#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    static int countSubmatrices(vector<vector<int>>& grid, int k) {
        const int r=grid.size(), c=grid[0].size();
        int cnt=0, brCol=c;
        if (grid[0][0]>k) return 0;// early stop
        cnt++;
        for(int j=1; j<c; j++){
            int& x=grid[0][j];
            x+=grid[0][j-1];
            if(x>k)// no need for computing for the rest cols
                { brCol=j; break;}
            cnt++;
        }
        for(int i=1; i<r; i++){
            grid[i][0]+=grid[i-1][0];
            if (grid[i][0]>k) break;
            cnt++;
            for(int j=1; j<brCol; j++){
                int& x=grid[i][j];
                x+=grid[i-1][j]+grid[i][j-1]-grid[i-1][j-1];
                if (x>k){
                    brCol=j; break;
                }
                cnt++;
            }
        }
        return cnt;
    }
};