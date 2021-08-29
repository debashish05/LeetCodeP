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
    
    vector <double> sumAndNumberOfNodes(TreeNode* root){
        //return sum and number of nodes and highest value in subtree
        
        if(root==NULL)return {0,0,0};
        vector <double> left={0,0,0},right={0,0,0},answer(3);
        
        if(root->left!=NULL){
            left=sumAndNumberOfNodes(root->left);
        }
        if(root->right!=NULL){
            right=sumAndNumberOfNodes(root->right);
        }
        
        answer[0]=(root->val+left[0]+right[0]);
        answer[1]=(1+left[1]+right[1]);
        
        answer[2]=answer[0]/answer[1];
        
        answer[2]=max(answer[2],left[2]);
        answer[2]=max(answer[2],right[2]);
        
        return answer;
    } 
    
    double maximumAverageSubtree(TreeNode* root) {
        vector<double> answer=sumAndNumberOfNodes(root);
        return answer[2];
    }
};
