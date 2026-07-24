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
    vector<int> largestValues(TreeNode* root) {
        vector<int> result;
        if(!root) return result;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int sz=q.size();
            int maxval=INT_MIN;
            while(sz--){
                TreeNode* t=q.front();
                q.pop();
                maxval=max(maxval,t->val);
                if(t->left!=nullptr){
                    q.push(t->left);
                }
                if(t->right!=nullptr){
                    q.push(t->right);
                }
                
            }
            result.push_back(maxval);
        }
        return result;
    }
};