// Problem Link - https://leetcode.com/problems/find-the-string-with-lcp/description/
// Day 30 of 100 DSA Day Challenge.
// DS Used - Dynamic Programming
// Time Complexity - O(n^2) where n is the size of the input lcp
// Space Complexity - O(n) where n is the size of the input lcp. We are using a string to store the result, which takes O(n) space.


#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    string findTheString(vector<vector<int>>& lcp) {
        int n = lcp.size();
        string word(n,'\0');
        char current = 'a';
        for(int i=0;i<n;i++){
            if(word[i] == '\0'){
                if(current > 'z'){
                    return "";
                }
                word[i] = current;
                for(int j=i+1;j<n;j++){
                    if(lcp[i][j]>0){
                        word[j] = word[i];
                    }
                }
                current++;
            }
        }
        for(int i=n-1;i>=0;i--){
            for(int j=n-1;j>=0;j--){
                if(word[i] != word[j]){
                    if(lcp[i][j]){
                        return "";
                    }
                }else{
                    if(i == n-1 || j == n-1){
                        if(lcp[i][j] != 1){
                            return "";
                        }
                    }else{
                        if(lcp[i][j] != lcp[i+1][j+1] + 1){
                            return "";
                        }
                    }
                }
            }
        }
        return word;
    }
};