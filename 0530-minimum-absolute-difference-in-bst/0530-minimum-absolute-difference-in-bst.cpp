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
    int minDifference=INT_MAX;
    TreeNode* prev=nullptr;
    void Inorder(TreeNode* node){
        if(node==nullptr) return;
        Inorder(node->left);
        if(prev!=nullptr){
            int currDifference=(node->val-prev->val);
            if(currDifference<minDifference){
                minDifference=currDifference;
            }
        }
        prev=node;
        Inorder(node->right);
    }
public:
    int getMinimumDifference(TreeNode* root) {
        minDifference=INT_MAX;
        prev=nullptr;
        Inorder(root);
        return minDifference;
    }
};