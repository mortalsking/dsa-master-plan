// Problem Link: https://leetcode.com/problems/matrix-similarity-after-cyclic-shifts/description/
//day 28 of 100 DSA day challenge
// DS Used: Array
// Time Complexity: O(m*n) where m and n are the dimensions of the matrix. We need to check each element of the matrix against its corresponding element after the cyclic shift, which takes O(m*n) time.
// Space Complexity: O(1) as we are using only a constant amount of extra space for variables and no additional data structures that grow with input size.


#include <bits/stdc++.h>    
using namespace std;



class Solution {
public:
    bool areSimilar(vector<vector<int>>& mat, int k) {
        int m = mat.size();
        int n = mat[0].size();
        k%=n;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(i%2 == 0 ){
                    if(mat[i][j] != mat[i][(j+k)%n])
                    return false;
                }else{
                    if(mat[i][j] != mat[i][(j-k+n)%n])
                    return false;
                }
            }
        }
        return true;
    }
};