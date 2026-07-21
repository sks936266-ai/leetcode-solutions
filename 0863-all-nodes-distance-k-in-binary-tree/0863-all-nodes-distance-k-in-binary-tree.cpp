/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> result;
    void addSubtreeNodes(TreeNode* node, int k) {
        if (!node || k < 0) return;
        if (k == 0) {
            result.push_back(node->val);
            return;
        }
        addSubtreeNodes(node->left, k - 1);
        addSubtreeNodes(node->right, k - 1);
    }

    int dfs(TreeNode* node, TreeNode* target, int k) {
        if (!node) return -1;

        if (node == target) {
            addSubtreeNodes(node, k);
            return 1; 
        }

        int leftDist = dfs(node->left, target, k);
        if (leftDist != -1) {
            if (leftDist == k) {
                result.push_back(node->val);
            } else {
                addSubtreeNodes(node->right, k - leftDist - 1);
            }
            return leftDist + 1;
        }

        int rightDist = dfs(node->right, target, k);
        if (rightDist != -1) {
            if (rightDist == k) {
                result.push_back(node->val);
            } else {
                addSubtreeNodes(node->left, k - rightDist - 1);
            }
            return rightDist + 1;
        }

        return -1;
    }

    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        result.clear();
        dfs(root, target, k);
        return result;
    }
};