class LogSystem {
    
    //yyyymmddhhmmss
    map<string,vector<int>> m; 

    public:
    LogSystem() {
        
    }
    
    void put(int id, string timestamp) {
        m[timestamp].push_back(id);      
    }
    
    vector<int> retrieve(string start, string end, string granularity) {

        if(granularity=="Year"){
            start[5]='0';start[6]='1';
            end[5]='1';end[6]='2';
            granularity="Month";
        }
        if(granularity=="Month"){
            start[8]='0';start[9]='1';
            end[8]='3';end[9]='1';
            granularity="Day";
        }
        if(granularity=="Day"){
            start[11]='0';start[12]='0';
            end[11]='2';end[12]='3';
            granularity="Hour";
        }
        if(granularity=="Hour"){
            start[14]='0';start[15]='0';
            end[14]='5';end[15]='9';
            granularity="Minute";
        }
        if(granularity=="Minute"){
            start[17]='0';start[18]='0';
            end[17]='5';end[18]='9';
            granularity="Second";
        }
        
        auto it1=m.lower_bound(start);
        auto it2=m.upper_bound(end);
        vector <int> ans;
        if(it2==m.begin())return ans;   //no timestamp

        for(auto it=it1;it!=it2;++it){

            for(auto itr=it->second.begin();itr!=it->second.end();++itr)
                ans.push_back(*itr);
                    
        }
        return ans;
    }
};

/**
 * Your LogSystem object will be instantiated and called as such:
 * LogSystem* obj = new LogSystem();
 * obj->put(id,timestamp);
 * vector<int> param_2 = obj->retrieve(start,end,granularity);
 */