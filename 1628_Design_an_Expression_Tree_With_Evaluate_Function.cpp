/**
 * This is the interface for the expression tree Node.
 * You should not remove it, and you can define some classes to implement it.
 */

class Node {
public:
    Node *left,*right;
    int val;
    char operation;
    int evaluate(){
        return val;
    }
};

/**
 * This is the TreeBuilder class.
 * You can treat it as the driver code that takes the postinfix input 
 * and returns the expression tree represnting it as a Node.
 */

class TreeBuilder {
public:
    Node* buildTree(vector<string>& postfix) {
        
        stack <Node*> s;
        for(int i=0;i<postfix.size();++i)
        {
            Node *node=new Node;
            if(postfix[i][0]>='0' && postfix[i][0]<='9'){   //number
                
                node->left=NULL;
                node->right=NULL;
                node->operation='#'; //no operation
                
                int val=0;
                for(int j=0;j<postfix[i].length();++j){
                    val=val*10+(postfix[i][j]-'0');
                }
                
                node->val=val;
            }
            else{       //operator
                Node* node1=s.top();s.pop();
                Node* node2=s.top();s.pop();
                
                node->left=node2;
                node->right=node1;
                node->operation=postfix[i][0]; //operation
                
                if(postfix[i][0]=='+')node->val=node2->val+node1->val;
                else if(postfix[i][0]=='-')node->val=node2->val-node1->val;
                else if(postfix[i][0]=='*')node->val=node2->val*node1->val;
                else node->val=node2->val/node1->val;
            }
            s.push(node);
        }
        return s.top();
    }
};


/**
 * Your TreeBuilder object will be instantiated and called as such:
 * TreeBuilder* obj = new TreeBuilder();
 * Node* expTree = obj->buildTree(postfix);
 * int ans = expTree->evaluate();
 */
