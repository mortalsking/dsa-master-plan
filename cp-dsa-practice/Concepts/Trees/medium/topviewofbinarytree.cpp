// #include <iostream>
// #include <vector>
// #include <queue>
// #include <map>
// using namespace std;

// struct TreeNode {
//     int val;
//     TreeNode *left;
//     TreeNode *right;
//     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
// };

// class Solution {
// public:
//     vector<int> topView(TreeNode* root) {
//         vector<int> result;
//         if (!root) return result;
        
//         // Map to store the first node at each horizontal distance
//         // Key: horizontal distance, Value: node value
//         map<int, int> topNodes;
        
//         // Queue stores pair of (node, horizontal distance)
//         queue<pair<TreeNode*, int>> q;
//         q.push({root, 0});
        
//         while (!q.empty()) {
//             auto [node, hd] = q.front();
//             q.pop();
            
//             // If this horizontal distance is not in map, add it
//             // (this ensures we only store the first node at each HD)
//             if (topNodes.find(hd) == topNodes.end()) {
//                 topNodes[hd] = node->val;
//             }
            
//             // Add children with updated horizontal distances
//             if (node->left) {
//                 q.push({node->left, hd - 1});
//             }
//             if (node->right) {
//                 q.push({node->right, hd + 1});
//             }
//         }
        
//         // Extract values in order of horizontal distance
//         for (auto& pair : topNodes) {
//             result.push_back(pair.second);
//         }
        
//         return result;
//     }
// };
