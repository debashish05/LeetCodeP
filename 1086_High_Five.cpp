class Solution {
public:
    vector<vector<int>> highFive(vector<vector<int>>& items) {
        
        map <int,vector<int>> m; 
        
        for(int i=0;i<items.size();++i){
            int len=m[items[i][0]].size();
            if(len<5){
                m[items[i][0]].push_back(items[i][1]);
            }
            else{
                int index=0;
                for(int k=1;k<5;++k){
                    if(m[items[i][0]][k]<m[items[i][0]][index])index=k;
                }
                m[items[i][0]][index]=max(m[items[i][0]][index],items[i][1]);
            }
        }
        
        vector <vector <int>> ans;
        for(auto itr=m.begin();itr!=m.end();++itr){
            int sum=0;
            
            for(int i=0;i<5;++i)sum+=(itr->second)[i];
            
            ans.push_back({itr->first,sum/5});
        }
        return ans;
    }
};
