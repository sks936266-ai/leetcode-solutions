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
    void findDepth(TreeNode* node,int currentcount,int& max_Depth){
        if(node==nullptr){
            max_Depth=max(max_Depth,currentcount);
            return;
        }
        findDepth(node->left,currentcount+1,max_Depth);
        findDepth(node->right,currentcount+1,max_Depth);
    }
public:
    int maxDepth(TreeNode* root) {
        int max_Depth=0;
        findDepth(root,0,max_Depth);
        return max_Depth;

    }
};