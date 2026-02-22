// Problem Link: https://leetcode.com/problems/sort-colors/
// Day 1 of 100 DSA Day Challenge.
// Time Complexity: O(n) where n is the size of the input array
// Space Complexity: O(1)


#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int low = 0,mid = 0,high = nums.size()-1;
        while(mid<=high){
            if(nums[mid] == 0){
                swap(nums[low],nums[mid]);
                low++;
                mid++;
            }
            else if(nums[mid] == 1){
                mid++;
            }else{
                swap(nums[mid],nums[high]);
                high--;
            }
        }
    }
};