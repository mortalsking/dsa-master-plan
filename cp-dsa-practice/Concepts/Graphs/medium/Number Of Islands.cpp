// Problem: Number of Islands
// Link: https://leetcode.com/problems/number-of-islands/description/
// Day 12 of 100 DSA Day Challenge.
// DS Used: Graphs
// Time Complexity: O(m*n) where m and n are the dimensions of the grid
// Space Complexity: O(m*n) in the worst case when the grid is filled with land



//Approach: dfs to mark the visited land cells and count the number of islands
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        if (grid.empty() || grid[0].empty()) {
            return 0;
        }
        
        int numIslands = 0;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == '1') {
                    numIslands++;
                    dfs(grid, i, j);
                }
            }
        }
        
        return numIslands;
    }
    
private:
    void dfs(vector<vector<char>>& grid, int i, int j) {
        if (i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size() || grid[i][j] != '1') {
            return;
        }
        
        grid[i][j] = '0'; // mark as visited
        dfs(grid, i + 1, j); // down
        dfs(grid, i - 1, j); // up
        dfs(grid, i, j + 1); // right
        dfs(grid, i, j - 1); // left
    }
};
//Approach: bfs to mark the visited land cells and count the number of islands
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        if (grid.empty() || grid[0].empty()) {
            return 0;
        }
        
        int numIslands = 0;
        int m = grid.size();
        int n = grid[0].size();
        vector<pair<int, int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        
        queue<pair<int, int>> q;
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '1') {
                    numIslands++;
                    q.push({i, j});
                    
                    while (!q.empty()) {
                        auto [x, y] = q.front();
                        q.pop();
                        
                        if (x < 0 || x >= m || y < 0 || y >= n || grid[x][y] != '1') {
                            continue;
                        }
                        
                        grid[x][y] = '0'; // mark as visited
                        
                        for (auto& dir : directions) {
                            int nx = x + dir.first;
                            int ny = y + dir.second;
                            if (nx >= 0 && nx < m && ny >= 0 && ny < n && grid[nx][ny] == '1') {
                                q.push({nx, ny});
                            }
                        }
                    }
                }
            }
        }
        
        return numIslands;
    }
};