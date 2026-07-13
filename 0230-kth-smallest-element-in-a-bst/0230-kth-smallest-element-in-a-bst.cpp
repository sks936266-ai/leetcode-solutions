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
    void inorder(TreeNode* node,int& k,int& result){
        if(!node) return;
        inorder(node->left,k,result);
        k--;
        if(k==0){
            result=node->val;
            return;
        }
        if(result!=-1) return;
        inorder(node->right,k,result);
    }
public:
    int kthSmallest(TreeNode* root, int k) {
        int result=-1;
        inorder(root,k,result);
        return result;
    }
};