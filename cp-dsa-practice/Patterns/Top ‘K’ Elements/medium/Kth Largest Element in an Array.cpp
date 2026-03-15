// Problem Link: https://leetcode.com/problems/kth-largest-element-in-an-array/
// Day 17 of 100 DSA Day Challenge.
// DS Used: Min Heap (Priority Queue)
// Time Complexity: O(N log K) where N is the number of elements in the input array and K is the value of k, as we are pushing each element into the min heap and maintaining its size at most K.
// Space Complexity: O(K) for the min heap that stores at most K elements.

// Approach 1: Min Heap (Priority Queue)
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int,vector<int>, greater<int>>pq;
        for(int num:nums){
            pq.push(num);
            if(pq.size()>k){
                pq.pop();
            }
        }
        return pq.top();
    }
};
// Approach 2: Sorting

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        return nums[nums.size() - k];
    }
};