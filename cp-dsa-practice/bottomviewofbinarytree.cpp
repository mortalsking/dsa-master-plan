#include <iostream>
#include <vector>
#include <queue>
#include <map>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class BinaryTreeViews {
public:
    // TOP VIEW
    vector<int> topView(TreeNode* root) {
        vector<int> result;
        if (!root) return result;
        
        map<int, int> nodes;  // HD -> node value
        queue<pair<TreeNode*, int>> q;
        q.push({root, 0});
        
        while (!q.empty()) {
            auto [node, hd] = q.front();
            q.pop();
            
            // Only insert if HD not seen before (first node)
            if (nodes.find(hd) == nodes.end()) {
                nodes[hd] = node->val;
            }
            
            if (node->left) q.push({node->left, hd - 1});
            if (node->right) q.push({node->right, hd + 1});
        }
        
        for (auto& p : nodes) result.push_back(p.second);
        return result;
    }
    
    // BOTTOM VIEW
    vector<int> bottomView(TreeNode* root) {
        vector<int> result;
        if (!root) return result;
        
        map<int, int> nodes;  // HD -> node value
        queue<pair<TreeNode*, int>> q;
        q.push({root, 0});
        
        while (!q.empty()) {
            auto [node, hd] = q.front();
            q.pop();
            
            // Always update (last node at this HD)
            nodes[hd] = node->val;
            
            if (node->left) q.push({node->left, hd - 1});
            if (node->right) q.push({node->right, hd + 1});
        }
        
        for (auto& p : nodes) result.push_back(p.second);
        return result;
    }
};

// Helper function to create test tree
TreeNode* createTestTree() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);
    return root;
}

int main() {
    TreeNode* root = createTestTree();
    BinaryTreeViews views;
    
    vector<int> top = views.topView(root);
    vector<int> bottom = views.bottomView(root);
    
    cout << "Top View: ";
    for (int val : top) cout << val << " ";
    cout << endl;
    
    cout << "Bottom View: ";
    for (int val : bottom) cout << val << " ";
    cout << endl;
    
    return 0;
}
