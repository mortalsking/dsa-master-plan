#include<bits/stdc++.h>
using namespace std;
struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x): val(x), left(nullptr), right(nullptr) {}   
};
int dfs(TreeNode* root) {
    TreeNode* node = root;
    if (node == nullptr) {
        return 0;
    }

    int ans = 0;
    // do logic
    dfs(node->left);
    dfs(node->right);
    return ans;
}
// Alternative using stack
int dfs(TreeNode* root) {
    stack<TreeNode*> stack;
    stack.push(root);
    int ans = 0;

    while (!stack.empty()) {
        TreeNode* node = stack.top();
        stack.pop();
        // do logic
        if (node->left != nullptr) {
            stack.push(node->left);
        }
        if (node->right != nullptr) {
            stack.push(node->right);
        }
    }

    return ans;
}