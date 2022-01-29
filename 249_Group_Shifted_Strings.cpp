class Solution {
public:
    vector<vector<string>> groupStrings(vector<string>& strings) {
    
        unordered_map<string,vector<string>> u;
        string diff;
        
        for(int i=0;i<strings.size();++i)
        {
            diff="";
            int len=strings[i].length();
            
            for(int j=1;j<len;++j)
            {
                diff+=to_string(((strings[i][j]-strings[i][j-1]+26)%26))+"*";
                // without * 1 from one iteration and 1 from another iteration will be 11 and
                // 11 from single iteration will match with it and result in wrong answer
            }
            u[diff].push_back(strings[i]);
        }
        
        vector<vector<string>> ans;
        for(auto x:u)ans.push_back(x.second);
        
        return ans;
    }
};