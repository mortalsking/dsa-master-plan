//day 1 of 100 dsa day challenge.
//DS Used: Array
//leetcode link:https://leetcode.com/problems/container-with-most-water
//Time Complexity: O(n)
//Space Complexity: O(1)

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxArea = 0;
        int left = 0;
        int right = height.size()-1;
        while(left<right){
            maxArea = max(maxArea,(right-left) * min(height[left],height[right]));
            if(height[left]<height[right]){
                left++;
            }else{
                right--;
            }
        }
        return maxArea;
    }
};