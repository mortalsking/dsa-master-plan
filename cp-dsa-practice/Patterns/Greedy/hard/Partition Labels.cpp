// LeetCode: 763. Partition Labels
//link: https://leetcode.com/problems/partition-labels/description/
// Day 16 of 100 DSA Day Challenge.
// DS Used: Greedy
// Time Complexity: O(n) where n is the length of the input string
// Space Complexity: O(1) as we are using only a constant amount of extra space


#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> partitionLabels(string s) {
        unordered_map<int,int>last_occurrence;
        for(int i=0;i<s.size();i++){
            last_occurrence[s[i]] = i;
        }
        vector<int>result;
        int start = 0,end = 0;
        for(int i=0;i<s.size();i++){
            end = max(end,last_occurrence[s[i]]);
            if(i == end){
                result.push_back(end-start+1);
                start = i+1;
            }
        }
        return result;
    }
};