// Problem Link: https://leetcode.com/problems/flatten-binary-tree-to-linked-list/
// Day 2 of 100 DSA Day Challenge.
// DS Used: Tree
// Time Complexity: O(n) where n is the number of nodes in the tree
// Space Complexity: O(1) as we are modifying the tree in place without using any extra space




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
    void flatten(TreeNode* root) {
        TreeNode* curr = root;
        while(curr){
            if(curr->left){
                TreeNode*temp = curr->left;
                while(temp->right){
                    temp = temp->right;
                }
                temp->right = curr->right;
                curr->right = curr->left;
                curr->left = nullptr;
            }
            curr = curr->right;
        }
    }
};