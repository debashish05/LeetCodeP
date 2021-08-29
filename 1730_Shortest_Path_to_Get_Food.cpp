class Solution {
public:
    
    int m,n;
    
    bool isValid(int i,int j){
        if(i>=0 && i<m && j>=0 && j<n)return true;
        else return false;
    }
    
    int getFood(vector<vector<char>>& grid) {
        
        int sourcex,sourcey;        // start location
        m=grid.size();n=grid[0].size();
        
        vector < vector < bool> > visited(m, vector < bool > (n));
        
        for(int i=0;i<m;++i){
            for(int j=0;j<n;++j){
                if(grid[i][j]=='*'){sourcex=i;sourcey=j;}
                visited[i][j]=false;
            }
        }
        
        queue <vector<int> > q;           // x,y coordinated, depth
        q.push({sourcex,sourcey,0});
        int x,y;
        visited[sourcex][sourcey]=true;
        
        while(!q.empty()){
            
            vector <int> node =q.front(); q.pop();
            x=node[0];y=node[1];
            
            if(isValid(x+1,y) && grid[x+1][y]!='X' && !visited[x+1][y]){
                if(grid[x+1][y]=='#')return node[2]+1;
                q.push({x+1,y,node[2]+1});
                visited[x+1][y]=true;
            }
            if(isValid(x-1,y) && grid[x-1][y]!='X' && !visited[x-1][y]){
                if(grid[x-1][y]=='#')return node[2]+1;
                q.push({x-1,y,node[2]+1});
                visited[x-1][y]=true;
            }
            if(isValid(x,y+1) && grid[x][y+1]!='X' && !visited[x][y+1]){
                if(grid[x][y+1]=='#')return node[2]+1;
                q.push({x,y+1,node[2]+1});
                visited[x][y+1]=true;
            }
            if(isValid(x,y-1) && grid[x][y-1]!='X' && !visited[x][y-1]){
                if(grid[x][y-1]=='#')return node[2]+1;
                q.push({x,y-1,node[2]+1});
                visited[x][y-1]=true;
            }
        }
        
        return -1;
        
    }
};
