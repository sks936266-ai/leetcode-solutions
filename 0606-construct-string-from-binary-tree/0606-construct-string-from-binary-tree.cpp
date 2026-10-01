/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    string tree2str(TreeNode* root) {
        if (!root) return "";
        
        // Base case: leaf node
        if (!root->left && !root->right) {
            return to_string(root->val);
        }
        
        // If there is no right child, only include the left child
        if (!root->right) {
            return to_string(root->val) + "(" + tree2str(root->left) + ")";
        }
        
        // If there is no left child, include empty parentheses for the left child
        if (!root->left) {
            return to_string(root->val) + "()(" + tree2str(root->right) + ")";
        }
        
        // If both children exist
        return to_string(root->val) + "(" + tree2str(root->left) + ")(" + tree2str(root->right) + ")";
    }
};