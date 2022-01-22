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
    TreeNode* findNearestRightNode(TreeNode* root, TreeNode* u) {
        
        queue <TreeNode*> q;
        q.push(root);
        q.push(nullptr);
        int prev=-1;

        while(!q.empty()){
            TreeNode* curr=q.front();
            q.pop();
            if(prev==u->val)return curr;
            if(curr==nullptr){
                q.push(nullptr);
                continue;
            }
            prev=curr->val;
            if(curr->left!=nullptr)q.push(curr->left);
            if(curr->right!=nullptr)q.push(curr->right);
        }
        return nullptr;
    }
};