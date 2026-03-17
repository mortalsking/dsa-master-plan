// Largest Submatrix With Rearrangements
//link: https://leetcode.com/problems/largest-submatrix-with-rearrangements/description/
// Day 19 of 100 DSA Day Challenge.
// DS Used: Array
// Time Complexity: O(m*n*log(n)) where m and n are the dimensions of the matrix. We iterate through each cell to calculate the heights, which takes O(m*n) time. Then, for each row, we sort the heights, which takes O(n*log(n)) time. Therefore, the overall time complexity is O(m*n*log(n)).
// Space Complexity: O(1) if we don't consider the input matrix as extra space, since we are modifying the input matrix in place to store the heights. If we consider the input matrix as extra space, then the space complexity is O(m*n) due to the input matrix itself.





#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& matrix) {
        auto m = matrix.size(), n = matrix[0].size();
        int res = 0;

        for (int i = 1; i < m; i++)
            for (int j = 0; j < n; j++)
                if (matrix[i][j] == 1)
                    matrix[i][j] += matrix[i - 1][j];

        for (int i = 0; i < m; i++) {
            sort(matrix[i].rbegin(), matrix[i].rend());
            for (int j = 0; j < n; j++)
                res = max(res, matrix[i][j] * (j + 1));
        }

        return res;
    }
};