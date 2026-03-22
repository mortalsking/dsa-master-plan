// Problem Link: https://leetcode.com/problems/determine-whether-matrix-can-be-obtained-by-rotation/
// Day 24 of 100 DSA Day Challenge.
// DS Used: Array
// Time Complexity: O(n^2) where n is the size of the matrix. We need to compare the two matrices and perform the rotation operation, which both take O(n^2) time.
// Space Complexity: O(1) as we are performing the rotation in place without using any additional data structures that grow with the input size.



#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    void rotate(vector<vector<int>>& mat){
        int n = mat.size();
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                swap(mat[i][j], mat[j][i]);
            }
        }
        for (int i = 0; i < n; i++) {
            reverse(mat[i].begin(), mat[i].end());
        }
    }
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
       for(int i=0;i<4;i++){
        if(mat == target) return true;
        rotate(mat);
       }
       return false;
    }
};