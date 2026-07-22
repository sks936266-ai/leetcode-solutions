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
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        unordered_set<int> todeleteset(to_delete.begin(),to_delete.end());
        vector<TreeNode*> forest;
        root=processNode(root,todeleteset,forest);
        if(root!=nullptr){
            forest.push_back(root);
        }
        return forest;
    }
private:
    TreeNode* processNode(TreeNode* node,unordered_set<int>& todeleteset,vector<TreeNode*>& forest){
        if(node==nullptr){
            return nullptr;
        }
        node->left=processNode(node->left,todeleteset,forest);
        node->right=processNode(node->right,todeleteset,forest);
        if(todeleteset.count(node->val)){
            if(node->left!=nullptr){
                forest.push_back(node->left);
            }
            if(node->right!=nullptr){
                forest.push_back(node->right);
            }
            return nullptr;
        }
        return node;
    }
};