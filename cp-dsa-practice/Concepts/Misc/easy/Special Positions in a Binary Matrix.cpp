// Problem: https://leetcode.com/problems/special-positions-in-a-binary-matrix/
// Day 10 of 100 DSA Day Challenge.
// DS Used: Arrays
// Time Complexity: O(m*n) where m and n are the dimensions of the matrix
// Space Complexity: O(1) as we are using only a constant amount of extra space

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        int special = 0;

        for (const auto& row : mat) {
            if (accumulate(row.begin(), row.end(), 0) == 1) {
                int colIdx = distance(row.begin(), find(row.begin(), row.end(), 1));
                special += getColumnSum(mat, colIdx) == 1;
            }
        }

        return special;        
    }

private:
    int getColumnSum(const vector<vector<int>>& mat, int colIdx) {
        int sum = 0;
        for (const auto& row : mat) {
            sum += row[colIdx];
        }
        return sum;
    }
};