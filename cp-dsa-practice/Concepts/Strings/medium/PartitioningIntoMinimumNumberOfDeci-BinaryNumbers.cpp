// 1689. Partitioning Into Minimum Number Of Deci-Binary Numbers
//link: https://leetcode.com/problems/partitioning-into-minimum-number-of-deci-binary-numbers/description/
// Day 7 of 100 DSA Day Challenge.
// DS Used: String
// Time Complexity: O(n) where n is the length of the input string
// Space Complexity: O(1) as we are using only a constant amount of extra space


#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minPartitions(string n) {
        int ans = 0;
        for(char& c:n) ans = max(ans,c - '0');
        return ans;
    }
};

// Alternative using STL max_element
class Solution {
public:
    int minPartitions(string n) {
        return *max_element(n.begin(),n.end()) - '0';
	}
};