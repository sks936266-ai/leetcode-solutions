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
    void findPaths(TreeNode* root, string currentPath, vector<string>& result) {
        if (root == nullptr) return;

        currentPath += to_string(root->val);

        if (root->left == nullptr && root->right == nullptr) {
            result.push_back(currentPath);
            return;
        }

        currentPath += "->";
        findPaths(root->left, currentPath, result);
        findPaths(root->right, currentPath, result);
    }

    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> result;
        string currentPath = "";
        
        findPaths(root, currentPath, result);
        
        return result;
    }
};