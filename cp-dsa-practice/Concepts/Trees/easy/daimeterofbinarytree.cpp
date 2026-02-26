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
    int ans = 0;
public:
    int helper(TreeNode*root){
        if(root == NULL) return 0;
        int left = helper(root->left);
        int right = helper(root->right);

        ans = max(ans,left+right);
        return 1+max(left,right);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        helper(root);
        return ans;
    }
};