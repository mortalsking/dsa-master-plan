// 1545. Find Kth Bit in Nth Binary String
// Link: https://leetcode.com/problems/find-kth-bit-in-nth-binary-string/
// Day 9 of 100 DSA Day Challenge.
// DS Used: Recursion
// Time Complexity: O(n) where n is the value of n in the input
// Space Complexity: O(n) due to recursive call stack

class Solution {
public:
    char findKthBit(int n, int k) {
        if(n == 1) return '0';
        int len = (1<<n) - 1;
        int mid = len/2 + 1;
        if(k == mid) return '1';
        if(k<mid) return findKthBit(n-1,k);
        return findKthBit(n-1,len-k+1) == '0' ? '1' : '0';
    }
};