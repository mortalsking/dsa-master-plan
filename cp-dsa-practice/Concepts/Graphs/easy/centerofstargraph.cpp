// Problem Link: https://leetcode.com/problems/find-center-of-star-graph/
//day 1 of 100 dsa day challenge
// DS Used: Graph
// Time Complexity: O(1)
// Space Complexity: O(1)

#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        return (edges[0][0] == edges[1][0] || edges[0][0] == edges[1][1]) ? edges[0][0] : edges[0][1];
    }
};