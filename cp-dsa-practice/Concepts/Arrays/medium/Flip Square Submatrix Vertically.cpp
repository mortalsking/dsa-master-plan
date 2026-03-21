// Problem Link: https://leetcode.com/problems/flip-square-submatrix-vertically/description/
// Day 23 of 100 DSA Day Challenge.
// DS Used: Array
// Time Complexity: O(k^2) where k is the size of the submatrix. We iterate through each element of the k x k submatrix once to perform the vertical flip.
// Space Complexity: O(1) as we are performing the flip in place without using any additional data structures that grow with the input size.


#include <bits/stdc++.h>
using namespace std;

//approach:column wise swap of elements in the submatrix. We iterate through each column of the submatrix and swap the elements from the top and bottom until we reach the middle of the column.
class Solution {
public:
    vector<vector<int>> reverseSubmatrix(vector<vector<int>>& grid, int x, int y, int k) {
        for(int i=0;i<k;i++){
            for(int j = 0;j<k>>1;j++){
                swap(grid[x+j][y+i],grid[x+k-j-1][y+i]);
            }
        }
        return grid;
    }
};

//approach:row wise swap of elements in the submatrix. We iterate through each row of the submatrix and swap the elements from the top and bottom until we reach the middle of the row.
class Solution {
public:
 vector<vector<int>> reverseSubmatrix(vector<vector<int>>& grid, int x, int y, int k) {
 for (int i = 0; i < k >> 1; i++){
 for (int j = 0; j < k; j++){
 swap(grid[x + i][y + j], grid[x + k - 1 - i][y + j]);
 }
}
    return grid;
    }
};