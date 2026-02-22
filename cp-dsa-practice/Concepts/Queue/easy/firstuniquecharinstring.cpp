// Problem Link: https://leetcode.com/problems/first-unique-character-in-a-string/
// Day 1 of 100 DSA Day Challenge.
// DS Used: Queue, Hash Map/
// Time Complexity: O(n) where n is the length of the input string
// Space Complexity: O(n) for the hash map and queue used to store character frequencies and

#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int firstUniqChar(string s) {
        int res = -1;
        unordered_map<char,int>mp;
        queue<char>queue;
        for(auto& ch : s){
            mp[ch]++;
            queue.push(ch);
        }
        while(!queue.empty()){
            char c = queue.front();
            if(mp[c]>1){
                queue.pop();
            }else{
                break;
            }
        }
        if(queue.empty()) return -1;

        for(int i = 0 ; i<s.size(); i++){
            if(s[i] == queue.front()) return i;
        }
        
        return -1;
    }
};