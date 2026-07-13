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
    void inorderHelper(TreeNode* node,std::vector<int>& result){
        if(!node) return;
        inorderHelper(node->left,result);
        result.push_back(node->val);
        inorderHelper(node->right,result);
    }
    vector<int> inorderTraversal(TreeNode* root) {
        std::vector<int> result;
        inorderHelper(root,result);
        return result;
    }
};