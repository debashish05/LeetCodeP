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
    int finalAns=0;
public:
    int longest(TreeNode* root) {
        
        int ans=1;
        if(root->left!=NULL){
            if(root->left->val==root->val+1)ans=1+longest(root->left);
            else finalAns=max(finalAns,longest(root->left));
        }
        if(root->right!=NULL){
            if(root->right->val==root->val+1)ans=max(ans,1+longest(root->right));
            else finalAns=max(finalAns,longest(root->right));   
        }
        return ans;
    }
    
    int longestConsecutive(TreeNode* root) {
        return max(finalAns,longest(root));
    }
};