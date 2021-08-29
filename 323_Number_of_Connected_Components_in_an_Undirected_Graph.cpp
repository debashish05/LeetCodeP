class Solution {
public:  
    int countComponents(int n, vector<vector<int>>& edges) {
        
        queue <int> q;
        bool visited[n];
        for(int i=0;i<n;++i)visited[i]=false;
        
        vector <int> graph[n];
        
        for(int i=0;i<edges.size();++i){
            graph[edges[i][0]].push_back(edges[i][1]);
            graph[edges[i][1]].push_back(edges[i][0]);
        }
        
        
        int current_city=0,answer=0;
        
        
        while(current_city<n){
            
            if(visited[current_city]){
                current_city++; continue;
            }
            
            q.push(current_city);     //if not visited
            visited[current_city]=true;
            
            
            while(!q.empty()){
            
                int node=q.front();
                q.pop();
                
                for(int j=0;j<graph[node].size();++j){
                    
                    if(!visited[graph[node][j]]){
                        q.push(graph[node][j]);
                        visited[graph[node][j]]=true;
                    }
                }
            
            }
            current_city++;
            answer++;
            
        }
        
        return answer;
    }
};
