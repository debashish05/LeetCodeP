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
    vector<vector<int>> traversal;
public:
    
    
    pair<int,int> bfs(TreeNode *root,int pos)
    {
        if(root==nullptr)return {0,-1};
        queue <pair<TreeNode *,int>> q;
        q.push({root,pos});
        TreeNode* node=nullptr;
        pair <int,int> range={201,0};
        
        while(!q.empty())
        {
            pair<TreeNode *,int> curr=q.front();
            q.pop();
            
            pos=curr.second;
            node=curr.first;
            
            traversal[pos].push_back(node->val);
            range.first=min(range.first,pos);
            range.second=max(range.second,pos);
            
            
            if(node->left!=nullptr)
                q.push({node->left,pos-1});
            
            if(node->right!=nullptr)
                q.push({node->right,pos+1});
        }
        return range;
    }
    
    
    vector<vector<int>> verticalOrder(TreeNode* root) {
        int SIZE=202;
        traversal.resize(SIZE);
        pair<int,int> range=bfs(root,SIZE/2);
        
        return vector<vector<int>> (traversal.begin()+range.first,traversal.begin()+range.second+1);
    }
};