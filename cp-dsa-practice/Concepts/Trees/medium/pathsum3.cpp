// LeetCode: 437. Path Sum III
//link: https://leetcode.com/problems/path-sum-iii/description/
// Day 7 of 100 DSA Day Challenge.
// DS Used: Tree
// Time Complexity: O(n^2) in the worst case (skewed tree) where n is the number of nodes in the tree. Each node is visited once and for each node, we check all its ancestors which can take O(n) time.
// Space Complexity: O(h) where h is the height of the tree due to recursive call stack in the worst case (skewed tree) and O(h) for the path vector, resulting in O(h) overall.
#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };
 
class Solution {
public:
    int count = 0;

    int pathSum(TreeNode* root, int targetSum) {
        vector<int> path;
        helperPathSum(root, targetSum, path);
        return count;
    }

    void helperPathSum(TreeNode* root, int targetSum, vector<int>& path) {
        if (!root) return;

        path.push_back(root->val);
        long long int sum = 0;

        // Check all prefix sums
        for (int i = path.size() - 1; i >= 0; i--) {
            sum += path[i];
            if (sum == targetSum) count++;
        }

        helperPathSum(root->left, targetSum, path);
        helperPathSum(root->right, targetSum, path);

        // Backtrack
        path.pop_back();
    }
};