class Solution {
public:
    
    int n,m;
    queue <vector<int> > q;
    bool visited[101][101];
    
    bool isvalid(int x,int y){
        if(x>=0 && x<n && y>=0 && y<m)return true;
        else return false;
    }
    
    bool goTillWall(int x,int y,int directx,int directy,vector<vector<int>>& maze,vector<int>& destination){
        
            
        for(int i=x+directx,j=y+directy; ;i+=directx,j+=directy){
            if(!isvalid(i,j) || maze[i][j]){            //hit wall
                if(isvalid(i-directx,j-directy) && !visited[i-directx][j-directy]){
                    
                    if(i-directx==destination[0] && j-directy==destination[1])return true;
                    q.push({i-directx,j-directy});
                    visited[i-directx][j-directy]=true;
                
                }
                break;
            }
        }
        return false;
    }
    
    bool hasPath(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination) {
        
        q.push(start);
        
        n=maze.size();
        m=maze[0].size();
        int x,y;
        
        for(int i=0;i<n;++i){
            for(int j=0;j<m;++j){
                visited[i][j]=false;
            }
        }
        
        visited[start[0]][start[1]]=true;
        
        while(!q.empty()){
            vector <int> node= q.front(); q.pop();
            x=node[0],y=node[1];
            
            if(goTillWall(x,y,-1,0, maze,destination ) || goTillWall(x,y,0,-1,maze,destination) || goTillWall(x,y,0,1,maze,destination) || goTillWall(x,y,1,0,maze,destination))return true;   
            
        }
        
        return false;
    }
};
