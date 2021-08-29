
struct node{
    long rank;
    long data;
    node* parent;
};      

class DisjointSet{

    unordered_map <long,node*> u;

public:

    void makeNode(long val)
    {
        node* root=new node;
        root->data=val;
        root->parent=root;  
        root->rank=0;       //max. path from root to leaf
        u[val]=root;
    }

    void unionSet(long data1,long data2)        //
    {
        node* first=u[data1];
        node* second=u[data2];

        first=findset(data1);     //find leader of set1
        second=findset(data2);     //find leader of set2

        if(first==second)return; //both have same leader

        if(first->rank>=second->rank){
            second->parent=first;
            first->rank=max(first->rank,second->rank+1);
        }    
        else{
            first->parent=second;
            second->rank=max(second->rank,first->rank+1);
        }
    }

    node* findset(long key)       //represnt representative of of node root
    {
        node* root=u[key];
        node *temp=root;
        while(root->parent!=root)root=root->parent;
        temp->parent=root;
        return root;
    }

};

class Solution {
public:
    
    static bool acompare(vector <int>& a, vector <int>& b){
        return a[2]<b[2];
    }

    int minimumCost(int n, vector<vector<int>>& connections) {
        //minimum spanning tree
        
        sort(connections.begin(),connections.end(),acompare);   //sorting edge based on weight
        
        DisjointSet disjointset;

        for(int i=1;i<=n;++i)disjointset.makeNode(i);

        long u=0,v=0,cost=0,numOfNodesinMST=0;
        
        for(int i=0;i<connections.size();++i){
            
            u=connections[i][0];
            v=connections[i][1];
            
            if(disjointset.findset(u)!=disjointset.findset(v))
            {
                // u and v are element of two disjoint set
                disjointset.unionSet(u,v);
                cost+=connections[i][2];
                numOfNodesinMST++;
                //cout << u <<" "<< v <<std::endl;
            }
        }
        if(numOfNodesinMST==n-1)return cost;
        return -1;
    }
};
