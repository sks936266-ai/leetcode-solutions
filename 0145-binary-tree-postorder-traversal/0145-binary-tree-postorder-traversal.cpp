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
private:
    void postorderHelper(TreeNode* node,std::vector<int>& result){
        if(!node) return;
        postorderHelper(node->left,result);
        postorderHelper(node->right,result);
        result.push_back(node->val);
    }
public:
    vector<int> postorderTraversal(TreeNode* root) {
        std::vector<int> result;
        postorderHelper(root,result);
        return result;
    }
};