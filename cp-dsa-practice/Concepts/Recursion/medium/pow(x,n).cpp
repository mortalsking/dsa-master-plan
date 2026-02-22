// Problem Link: https://leetcode.com/problems/powx-n/
// Day 1 of 100 DSA Day Challenge.
// DS Used: Recursion
// Time Complexity: O(log n) where n is the exponent
// Space Complexity: O(1) for the iterative approach, O(log n) for the


#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    double myPow(double x, int n) {
        
        if(n < 0) {
            x = 1 / x;
        } 
        
        long num = labs(n);
        
        double pow = 1;
        
        while(num){ // equivalent to while(num != 0)
            if(num & 1) { // equivalent to if((num & 1) != 0)
                pow *= x;
            }
            
            x *= x;
            num >>= 1;
        }
        
        return pow;
    }
};