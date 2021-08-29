class Solution {
public:
    static bool acompare(vector <int> &a, vector <int> &b){
        if(a[0]!=b[0])return a[0]<b[0];
        return a[1]<b[1];
    }
    int minMeetingRooms(vector<vector<int>>& intervals) {
        
        sort(intervals.begin(),intervals.end(),acompare);
        
        int count=0;
        
        multiset <int> m;
        
        for(int i=0;i<intervals.size();++i){
            
            m.insert(intervals[i][1]-1);
            auto itr=m.lower_bound(intervals[i][0]);
            
            if(itr!=m.begin()){
                m.erase(m.begin(),itr);
            }
            if(m.size()>count)count=m.size();
        }
        return count;
        
    }
};
