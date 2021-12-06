/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;

    Node() {}

    Node(int _val) {
        val = _val;
        next = NULL;
    }

    Node(int _val, Node* _next) {
        val = _val;
        next = _next;
    }
};
*/

class Solution {
public:
    
    bool validPos(int left,int right,int val){
        // val lies bw [left,right] or val lies bw [right,left] 
        if((left<=val && val<=right) || (left>right && (val<=right || left<=val)))return true;
        else return false;
    }

    Node* insert(Node* head, int insertVal) {
        Node* node=new Node(insertVal,nullptr);
        if(head==nullptr){node->next=node;return node;}   //empty node
        
        if(head->next==head){  //one node
            head->next=node;
            node->next=head;
        }
        else{   //more than one node
            
            Node *first=head,*second=head->next;
            
            // find appropriate position to fit in
            while(second!=head)
            {
                if(validPos(first->val,second->val,insertVal))   
                {
                    first->next=node;
                    node->next=second;
                    break;
                }
                first=second;
                second=second->next;
            }
            
            if(second==head){       //no valid place left put in last place
                first->next=node;
                node->next=second;
            }
        }
        
        return head;
    }
};