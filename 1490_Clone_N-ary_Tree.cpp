/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    Node* cloneTree(Node* root) {
        if(root==nullptr)return nullptr;
        
        queue <pair<Node*,Node*>> q;
        Node* clone=new Node(root->val);
        q.push({root,clone});
        
        while(!q.empty())
        {
            pair<Node*,Node*> curr=q.front(); q.pop();
            int size=(curr.first)->children.size();
            
            for(int i=0;i<size;++i)
            {
                Node *currClone=new Node((curr.first)->children[i]->val);
                (curr.second)->children.push_back(currClone);
                q.push({(curr.first)->children[i],currClone});
            }
        }
        return clone;
    }
};