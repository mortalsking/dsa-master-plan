// C++ program to find the top and bottom view of a binary tree
// Time Complexity: O(n log n) due to map insertion
// Space Complexity: O(n) for the queue and map
// Note: The code includes both top view and bottom view functions for a binary tree.

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
        q.push(make_pair(root, 0));

        while (!q.empty()) {
            pair<TreeNode*, int> front = q.front();
            TreeNode* node = front.first;
            int hd = front.second;
            q.pop();

            // Only insert if HD not seen before (first node)
            if (nodes.find(hd) == nodes.end()) {
                nodes[hd] = node->val;
            }

            if (node->left) q.push(make_pair(node->left, hd - 1));
            if (node->right) q.push(make_pair(node->right, hd + 1));
        }

        for (map<int,int>::iterator it = nodes.begin(); it != nodes.end(); ++it) {
            result.push_back(it->second);
        }
        return result;
    }

    // BOTTOM VIEW
    vector<int> bottomView(TreeNode* root) {
        vector<int> result;
        if (!root) return result;

        map<int, int> nodes;  // HD -> node value
        queue<pair<TreeNode*, int>> q;
        q.push(make_pair(root, 0));

        while (!q.empty()) {
            pair<TreeNode*, int> front = q.front();
            TreeNode* node = front.first;
            int hd = front.second;
            q.pop();

            // Always update (last node at this HD)
            nodes[hd] = node->val;

            if (node->left) q.push(make_pair(node->left, hd - 1));
            if (node->right) q.push(make_pair(node->right, hd + 1));
        }

        for (map<int,int>::iterator it = nodes.begin(); it != nodes.end(); ++it) {
            result.push_back(it->second);
        }
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
    for (size_t i = 0; i < top.size(); i++) cout << top[i] << " ";
    cout << endl;

    cout << "Bottom View: ";
    for (size_t i = 0; i < bottom.size(); i++) cout << bottom[i] << " ";
    cout << endl;

    return 0;
}