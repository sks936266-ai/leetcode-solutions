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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> result;
        if (!root) {
            return result;
        }

        queue<TreeNode*> q;
        q.push(root);
        bool leftToRight = true;

        while (!q.empty()) {
            int sz = q.size();
            vector<int> temp(sz); 

            int first = 0;        
            int last = sz - 1;

            while (sz--) {
                TreeNode* t = q.front();
                q.pop();

                
                if (leftToRight) {
                    temp[first] = t->val;
                    first++;
                } else {
                    temp[last] = t->val;
                    last--;
                }

                if (t->left != nullptr) {
                    q.push(t->left);
                }
                if (t->right != nullptr) {
                    q.push(t->right);
                }
            }

            result.push_back(temp);
            leftToRight = !leftToRight; 
        }

        return result;
    }
};