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

    vector <int> traversal;
    vector <int> rightreverse;
public:

    void leftBoundary(TreeNode *root){ 
    //left boundary

        if(root==nullptr)return;
        
        if(root->left || root->right)traversal.push_back(root->val);   
        
        if(root->left!=nullptr)leftBoundary(root->left);
        else leftBoundary(root->right);
    }

    void rightBoundary(TreeNode *root){ 
    //right denotes

        if(root==nullptr)return;
        
        if(root->left || root->right)rightreverse.push_back(root->val);
        
        if(root->right!=nullptr)rightBoundary(root->right);
        else rightBoundary(root->left);
    }

    void leaf(TreeNode *root){
        if(root==nullptr)return;
        leaf(root->left);
        if(!(root->left || root->right))traversal.push_back(root->val);
        leaf(root->right);
    }

    vector<int> boundaryOfBinaryTree(TreeNode* root) {
        
        traversal.push_back(root->val);
        if(root->left!=nullptr)leftBoundary(root->left);
        
        if((root->left || root->right))leaf(root);
    
        if(root->right!=nullptr)rightBoundary(root->right);

        for(int i=rightreverse.size()-1;i>=0;--i)
            traversal.push_back(rightreverse[i]);

        return traversal;
    }
};