class Solution {
public:
    int connectSticks(vector<int>& sticks) {
        
        priority_queue <int> q;     
        for(int i=0;i<sticks.size();++i){
            q.push(sticks[i]*(-1));
        }
        
        int answer=0,x,y;
        
        while(q.size()!=1){
            x=q.top(); q.pop();
            y=q.top(); q.pop();
            answer+=(x+y);
            q.push(x+y);
        }
        return (-1)*answer;
    }
};
