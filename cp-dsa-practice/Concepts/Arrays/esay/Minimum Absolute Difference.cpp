// 1200. Minimum Absolute Difference
//link: https://leetcode.com/problems/minimum-absolute-difference/description/
// Day 17 of 100 DSA Day Challenge.
// DS Used: Sorting
// Time Complexity: O(N log N) due to sorting the array
// Space Complexity: O(1) if we don't consider the output array, otherwise O(N) in the worst case if all pairs have the same minimum absolute difference




#include <bits/stdc++.h>
using namespace std;



class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        vector<vector<int>>res;
        int minabsdiff = INT_MAX;
        for(int i=1;i<arr.size();i++){
            int diff = arr[i]-arr[i-1];
            if(diff < minabsdiff){
                minabsdiff = diff;
                res = {};
                res.push_back({arr[i-1],arr[i]});
            }else if(diff == minabsdiff){
                res.push_back({arr[i-1],arr[i]});
            }
        }
        return res;
    }
};