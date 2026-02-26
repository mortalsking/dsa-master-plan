//link: https://leetcode.com/problems/binary-tree-left-side-view/description/
// Day 4 of 100 DSA Day Challenge.
// Time Complexity: O(n) where n is the number of nodes in the tree
// Space Complexity: O(n) for the queue in the worst case (when the tree is completely unbalanced)

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<int> leftSideView(TreeNode* root) {
        vector<int> result;
        if (!root) return result;
        
        queue<TreeNode*> q;
        q.push(root);
        
        while (!q.empty()) {
            int levelSize = q.size();
            
            // Process all nodes at current level
            for (int i = 0; i < levelSize; i++) {
                TreeNode* current = q.front();
                q.pop();
                
                // For left view: add first node of each level
                if (i == 0) {
                    result.push_back(current->val);
                }
                
                // Add children to queue
                if (current->left) q.push(current->left);
                if (current->right) q.push(current->right);
            }
        }
        return result;
    }
    
    vector<int> rightSideView(TreeNode* root) {
        vector<int> result;
        if (!root) return result;
        
        queue<TreeNode*> q;
        q.push(root);
        
        while (!q.empty()) {
            int levelSize = q.size();
            
            // Process all nodes at current level
            for (int i = 0; i < levelSize; i++) {
                TreeNode* current = q.front();
                q.pop();
                
                // For right view: add last node of each level
                if (i == levelSize - 1) {
                    result.push_back(current->val);
                }
                
                // Add children to queue
                if (current->left) q.push(current->left);
                if (current->right) q.push(current->right);
            }
        }
        return result;
    }
};

//Approach 2

class Solution {
public:
    vector<int> leftSideView(TreeNode* root) {
        vector<int> result;
        leftViewHelper(root, 0, result);
        return result;
    }
    
    void leftViewHelper(TreeNode* node, int level, vector<int>& result) {
        if (!node) return;
        
        // If this is the first node we're seeing at this level
        if (level == result.size()) {
            result.push_back(node->val);
        }
        
        // For left view: traverse left first, then right
        leftViewHelper(node->left, level + 1, result);
        leftViewHelper(node->right, level + 1, result);
    }
    
    vector<int> rightSideView(TreeNode* root) {
        vector<int> result;
        rightViewHelper(root, 0, result);
        return result;
    }
    
    void rightViewHelper(TreeNode* node, int level, vector<int>& result) {
        if (!node) return;
        
        // If this is the first node we're seeing at this level
        if (level == result.size()) {
            result.push_back(node->val);
        }
        
        // For right view: traverse right first, then left
        rightViewHelper(node->right, level + 1, result);
        rightViewHelper(node->left, level + 1, result);
    }
};

