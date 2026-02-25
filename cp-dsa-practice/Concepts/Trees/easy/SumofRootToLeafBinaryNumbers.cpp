// 1022. Sum of Root To Leaf Binary Numbers
//link: https://leetcode.com/problems/sum-of-root-to-leaf-binary-numbers/description/
// Day 3 of 100 DSA Day Challenge.
//time: O(n) where n is the number of nodes in the tree
//space: O(h) where h is the height of the tree due to recursive call stack

#include <bits/stdc++.h>
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
    int sumRootToLeaf(TreeNode* root) {
        return dfs(root,0);
    }
private:
    int dfs(TreeNode*node,int curr){
        if(!node) return 0;
        curr = curr*2 + node->val;
        if(!node->left && !node->right)
            return curr;
        return dfs(node->left,curr) + dfs(node->right,curr);
    }
};