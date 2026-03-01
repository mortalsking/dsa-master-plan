// 1480. Running Sum of 1d Array
// https://leetcode.com/problems/running-sum-of-1d-array/description/
// Day 7 of 100 DSA Day Challenge.
// DS Used: Array
// Time Complexity: O(n) where n is the size of the input array
// Space Complexity: O(1)

#include <vector>
using namespace std;

class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        for(int i=1;i<nums.size();i++){
            nums[i] = nums[i] + nums[i-1];
        }
        return nums;
    }
};