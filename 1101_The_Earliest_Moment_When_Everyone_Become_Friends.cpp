// Disjoint Set solution
class Solution {    
public:
    bool static compare(vector<int>& lhs,vector<int>& rhs)\
    {
    	return lhs[0]<rhs[0];
    }
    
    int earliestAcq(vector<vector<int>>& logs, int n) {
        
        int parent[n];
        int count=n-1;
        for(int i=0;i<n;++i)parent[i]=i;
        
        sort(logs.begin(),logs.end(),compare);

    	for(int i=0;i<logs.size();++i)
    	{
    		int u=logs[i][1],v=logs[i][2];
    		int depthu=0,depthv=0;

    		while(parent[u]!=u){
    			depthu++;
    			u=parent[u];
    		}

			while(parent[v]!=v){
    			depthv++;
    			v=parent[v];
    		}

    		if(u!=v){
    			//different parents
    			count--;
    			if(depthv>depthu){
    				parent[u]=v;
                    u=v;
    			}
    			else{
                    parent[v]=u;	
    			}
    		}
    		//path compression
    		parent[logs[i][1]]=u;
    		parent[logs[i][2]]=u;

    		if(count==0)return logs[i][0];
	    }
	    return -1;
    }
};