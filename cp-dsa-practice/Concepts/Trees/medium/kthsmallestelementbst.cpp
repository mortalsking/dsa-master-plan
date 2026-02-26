//link: https://leetcode.com/problems/kth-smallest-element-in-a-bst/description/
// Day 5 of 100 DSA Day Challenge.
// Time Complexity: O(n) in the worst case (when the tree is skewed)
// Space Complexity: O(h) where h is the height of the tree due to recursive call stack






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
    void solve(TreeNode* root,int &cnt,int &ans,int k){
        if(!root) return;
        solve(root->left,cnt,ans,k);
        cnt++;
        if(cnt == k){
            ans = root->val;
            return;
        }
        solve(root->right,cnt,ans,k);
    }
    int kthSmallest(TreeNode* root, int k) {
        int cnt = 0;
        int ans;
        solve(root,cnt,ans,k);
        return ans;
    }
};