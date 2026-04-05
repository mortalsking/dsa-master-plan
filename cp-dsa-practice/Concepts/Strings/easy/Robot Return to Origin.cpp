// Problem Link: https://leetcode.com/problems/robot-return-to-origin/
//day 36 of 100 day dsa challenge
//time complexity: O(n)
//space complexity: O(1)


#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    bool judgeCircle(string moves) {
        int x = 0, y = 0;
        for(char t:moves){
            if(t == 'R') x++;
            else if(t == 'L') x--;
            else if(t == 'U') y++;
            else if(t == 'D') y--;
        }
        return x == 0 && y == 0;
    }
};