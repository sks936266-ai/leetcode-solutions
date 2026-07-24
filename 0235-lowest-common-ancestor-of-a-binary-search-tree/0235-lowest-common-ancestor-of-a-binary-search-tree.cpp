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
private:
    TreeNode* answer=nullptr;
    int counttargets(TreeNode* root, TreeNode* p, TreeNode* q){
        if(root==nullptr){
            return 0;
        }
        int left=counttargets(root->left,p,q);
        int right=counttargets(root->right,p,q);
        int self=0;
        if(root==p || root==q){
            self=1;
        }
        int total=left+self+right;
        if(total==2 && answer==nullptr){
            answer=root;
        }
        return total;
    }
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        answer=nullptr;
        counttargets(root,p,q);
        return answer;
    }
};