// Problem Link: https://leetcode.com/problems/permutation-sequence/
// Day 1 of 100 DSA Day Challenge.
// DS Used: Recursion
// Time Complexity: O(n^2) where n is the input number
// Space Complexity: O(n) for the recursive call stack and the string used to build the result


#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    string getPermutation(int n, int k) {
        int fact=1;
        vector<int> nums;
        for(int i=1;i<n;i++){
            fact=fact*i;
            nums.push_back(i);
        }
        nums.push_back(n);
        k=k-1;
        string ans="";
        while(true){
            ans=ans+to_string(nums[k/fact]);
            nums.erase(nums.begin()+k/fact);
            if(nums.size()==0){
                break;
            }
            k=k%fact;
            fact=fact/nums.size();
        }
        return ans;
    }
};