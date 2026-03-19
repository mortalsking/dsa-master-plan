// Problem Link: https://leetcode.com/problems/count-submatrices-with-equal-frequency-of-x-and-y/description/
// Day 21 of 100 DSA Day Challenge.
// DS Used: Array
// Time Complexity: O(r*c) where r and c are the dimensions of the grid. We iterate through each cell of the grid once to calculate the prefix sums and count the submatrices, resulting in a time complexity of O(r*c).
// Space Complexity: O(c) where c is the number of columns in the grid. We use two additional arrays of size c to store the cumulative counts of 'X' and 'Y' for each column, resulting in a space complexity of O(c).




#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numberOfSubmatrices(vector<vector<char>>& grid) {
        int rows = grid.size(), cols = grid[0].size();
        vector<int> sumX(cols, 0);
        vector<int> sumY(cols, 0);
        int res = 0;

        for (int i = 0; i < rows; i++) {
            int rx = 0, ry = 0;

            for (int j = 0; j < cols; j++) {
                if (grid[i][j] == 'X') rx++;
                else if (grid[i][j] == 'Y') ry++;
                sumX[j] += rx;
                sumY[j] += ry;
                if (sumX[j] > 0 && sumX[j] == sumY[j]) res++;
            }
        }

        return res;
    }
};