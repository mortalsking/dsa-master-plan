// Problem Link: https://leetcode.com/problems/binary-tree-inorder-traversal/
// Day 1 of 100 DSA Day Challenge.
// DS Used: Tree
// Time Complexity: O(n) where n is the number of nodes in the tree
// Space Complexity: O(n) for the recursive call stack in the worst case (skew



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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int>res;
        inorder(root,res);
        return res;
    } 
    void  inorder(TreeNode* node,vector<int>&res){
        if(!node) return;
        inorder(node->left,res);
        res.push_back(node->val);
        inorder(node->right,res);
    }
};