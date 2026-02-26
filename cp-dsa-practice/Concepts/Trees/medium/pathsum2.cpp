//link: https://leetcode.com/problems/path-sum-ii/description/
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
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>>res;
        vector<int>path;
        findpath(root,sum,path,res);
        return res;
    }
private:
    void findpath(TreeNode*node,int sum,vector<int>&path,vector<vector<int>>&res){
        if(!node) return;
        path.push_back(node->val);
        if(!(node->left) && !(node->right) && sum == node->val)
            res.push_back(path);
        findpath(node->left,sum-node->val,path,res);
        findpath(node->right,sum-node->val,path,res);
        path.pop_back();
    }
};