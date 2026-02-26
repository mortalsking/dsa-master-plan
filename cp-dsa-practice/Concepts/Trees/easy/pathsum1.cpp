//link: https://leetcode.com/problems/path-sum/description/
// Day 5 of 100 DSA Day Challenge.
// DS Used: Tree
// Time Complexity: O(n) where n is the number of nodes in the tree
// Space Complexity: O(h) where h is the height of the tree due to recursive call stack in the worst case (skewed tree)
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
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(!root) return false;
        if(!root->left && !root->right){
            return targetSum - root->val == 0;
        }
        targetSum -= root->val;
        return hasPathSum(root->left,targetSum) + hasPathSum(root->right,targetSum);
    }
};