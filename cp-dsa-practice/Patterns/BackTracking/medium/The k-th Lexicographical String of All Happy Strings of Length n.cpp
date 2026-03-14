// Problem Link: https://leetcode.com/problems/the-k-th-lexicographical-string-of-all-happy-strings-of-length-n/description/
// Day 17 of 100 DSA Day Challenge.
// DS Used: Backtracking
// Time Complexity: O(N) where N is the length of the string to be generated, as we are generating one string of length N.
// Space Complexity: O(N) for the recursive call stack in the worst case, where N is the length of the string being generated.


#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    string getHappyString(int n, int k) {

        int total = 3 * (1<<(n-1));
        if(k>total) return "";

        k--;
        string res="";
        char last='\0';

        for(int pos=0;pos<n;pos++){

            int branch=1<<(n-pos-1);

            vector<char> choices;
            for(char c:{'a','b','c'})
                if(c!=last) choices.push_back(c);

            int idx=k/branch;
            res+=choices[idx];
            last=choices[idx];
            k%=branch;
        }

        return res;
    }
};