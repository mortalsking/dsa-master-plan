// Problem Link: https://leetcode.com/problems/binary-tree-maximum-path-sum/
// Day 1 of 100 DSA Day Challenge.
// DS Used: Tree
// Time Complexity: O(n) where n is the number of nodes in the tree
// Space Complexity: O(n) for the recursive call stack in the worst case (skewed tree)

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
    int maxPathSum(TreeNode* root) {
        int maxSum = INT_MIN;
        dfs(root,maxSum);
        return maxSum;
    }
    int dfs(TreeNode*node, int&maxSum){
        if(!node) return 0;
        int left = max(0,dfs(node->left,maxSum));
        int right = max(0,dfs(node->right,maxSum));

        maxSum = max(maxSum,node->val + left + right);
        return node->val + max(left,right);
    }
};