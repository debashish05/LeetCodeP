class FirstUnique {
public:
                        
    list <int> q;   // begin is front and end is tail
    unordered_map <int, list <int>:: iterator > u;
    list <int>:: iterator sink;
    
    FirstUnique(vector<int>& nums) {
        
        for(int i=0;i<nums.size();++i){
            
            auto itr= u.find(nums[i]);
            if(itr!=u.end()){
                if(itr->second!=sink){
                    q.erase(itr->second);   //remove from unique element lists
                    u[nums[i]]=sink;
                }
            }
            else{
                q.push_back(nums[i]);
                auto itr=q.end();--itr;
                u[nums[i]]=itr;
            }    
        }
    }
    
    int showFirstUnique() {
        if(q.empty())return -1;
        else return q.front();
    }
    
    void add(int value) {
        auto itr= u.find(value);
        if(itr!=u.end()){
            
            if(itr->second!=sink){
                q.erase(itr->second);   //remove from unique element lists
                u[value]=sink;
            }
        }
        else{
            q.push_back(value);
            auto itr=q.end();--itr;
            u[value]=itr;
        }  
    }
};

/**
 * Your FirstUnique object will be instantiated and called as such:
 * FirstUnique* obj = new FirstUnique(nums);
 * int param_1 = obj->showFirstUnique();
 * obj->add(value);
 */
