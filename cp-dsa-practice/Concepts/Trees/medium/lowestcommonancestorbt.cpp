//link: https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/description/
// Day 5 of 100 DSA Day Challenge.
// Time Complexity: O(n) where n is the number of nodes in the tree
// Space Complexity: O(h) where h is the height of the tree due to recursive call stack

#include<bits/stdc++.h>
using namespace std;

 struct TreeNode {
     int val;
    TreeNode *left;
    TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };
 
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
       if(!root) return nullptr;
       if(root == p || root == q){
        return root;
       }
        TreeNode*left = lowestCommonAncestor(root->left,p,q);
        TreeNode*right = lowestCommonAncestor(root->right,p,q);

        if(left && right) return root;

        return left ? left:right;
    }
};