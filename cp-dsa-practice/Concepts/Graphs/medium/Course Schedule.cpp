// Problem Link: https://leetcode.com/problems/course-schedule/description/
// Day 13 of 100 DSA Day Challenge.
// DS Used: Graphs
// Time Complexity: O(V+E) where V is the number of courses and E is the number of prerequisites
// Space Complexity: O(V+E) for the adjacency list and O(V) for the visited and path arrays






#include<bits/stdc++.h>
using namespace std;


//Approach: dfs
class Solution {
private:
    bool dfs(int node,const vector<vector<int>>&adj,vector<bool>&vis,vector<bool>&path){
        vis[node] = path[node] = true;
        for(int next:adj[node]){
            if(!vis[next]){
                if(dfs(next,adj,vis,path)) return 1;
            }else if(path[next]){
                return 1;
            }
        }
        path[node] = false;
        return false;
    }
public:    
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
       vector<vector<int>> adj(numCourses);
       for(const auto& pre: prerequisites){
            adj[pre[1]].push_back(pre[0]);
       }
       vector<bool>vis(numCourses,false);
       vector<bool>path(numCourses,false);

       for(int i=0;i<numCourses;++i){
        if(!vis[i]){
            if(dfs(i,adj,vis,path)) return false;
        }
       }
       return true;
    }
};
//Approach: bfs
class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        vector<int> indegree(numCourses, 0);

        for (const auto& pre : prerequisites) {
            adj[pre[1]].push_back(pre[0]);
            indegree[pre[0]]++;
        }

        queue<int> q;
        for (int i = 0; i < numCourses; ++i) {
            if (indegree[i] == 0) q.push(i);
        }

        int count = 0;
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            count++;

            for (int next : adj[node]) {
                indegree[next]--;
                if (indegree[next] == 0) q.push(next);
            }
        }

        return count == numCourses;
    }
};