// Problem Link: https://leetcode.com/problems/rotting-oranges/
// Day 12 of 100 DSA Day Challenge.
// DS Used: Graphs
//Time Complexity: O(m*n) where m and n are the dimensions of the grid
// Space Complexity: O(m*n) in the worst case when all oranges are rotten and we have to put all of them in the queue  

#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        if(grid.empty())    return 0;
        int countFreshOranges = 0;
        int m = grid.size();
        int n = grid[0].size();

        queue<pair<int,int>>q;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j] == 1)
                countFreshOranges++;
                else if(grid[i][j] == 2)
                q.push({i,j});
            }
        }
        int time = 0;
        vector<pair<int,int>>dirs = {{0,1},{1,0},{-1,0},{0,-1}};
        while(countFreshOranges != 0 && !q.empty())
        {
            int qsize = q.size();
            for(int i=0;i<qsize;i++){
                int rotrow = q.front().first;
                int rotcol = q.front().second;
                q.pop();
                for(auto d:dirs)
                {
                    int newX = rotrow + d.first;
                    int newY = rotcol + d.second;

                    if(newX >=0 && newX < m && newY>=0 && newY<n && grid[newX][newY] == 1){
                        grid[newX][newY] = 2;
                        countFreshOranges--;
                        q.push({newX,newY});
                    }
                }
            }
            time++;
        }
    return countFreshOranges == 0? time: -1;
    }
};