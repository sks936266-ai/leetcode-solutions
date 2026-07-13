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
    int maxCount=0;
    int currCount=0;
    TreeNode* prev=nullptr;
    vector<int> result;
    void Inorder(TreeNode* node){
        if(!node) return;
        Inorder(node->left);
        if(prev && prev->val== node->val){
            currCount++;
        }
        else{
            currCount=1;
        }
        if(currCount>maxCount){
            maxCount=currCount;
            result.clear();
            result.push_back(node->val);
        }
        else if(currCount==maxCount){
            result.push_back(node->val);
        }
        prev=node;
        Inorder(node->right);
    }
public:
    vector<int>findMode(TreeNode* root){
        Inorder(root);
        return result;
    }
};