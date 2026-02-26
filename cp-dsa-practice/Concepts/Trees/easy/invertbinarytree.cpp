//link: https://leetcode.com/problems/invert-binary-tree/description/
// Day 5 of 100 DSA Day Challenge.
// Time Complexity: O(n) where n is the number of nodes in the tree
// Space Complexity: O(h) where h is the height of the tree due to recursive call stack
//Approach 1
//DFS approach to invert the binary tree


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
    TreeNode* invertTree(TreeNode* root) {
        if(!root) return nullptr;
        TreeNode* temp = root->left;
        root->left = root->right;
        root->right = temp;
        invertTree(root->left);
        invertTree(root->right);

    return root;        
    }
};

//Approach 2 
// Time Complexity: O(n) where n is the number of nodes in the tree
// Space Complexity: O(n) for the queue in the worst case (when the tree is completely unbalanced)
//BFS approach to invert the binary tree
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if (!root) return root;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            TreeNode*curr = q.front();
            q.pop();
            
            swap(curr->left,curr->right);
            if(curr->left) q.push(curr->left);
            if(curr->right) q.push(curr->right);
        }
        return root;
    }
};