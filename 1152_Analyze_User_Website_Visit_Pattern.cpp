class Solution {
public:
    static bool acompare(vector<string>& a,vector<string>& b){
        return stoi(a[1])<stoi(b[1]);
    }
    vector<string> mostVisitedPattern(vector<string>& username, vector<int>& timestamp, vector<string>& website) {
        
        unordered_map <string, vector<string> > u;  //name sites visited
        vector <vector<string>> v(username.size(),vector<string>(3));
        
        for(int i=0;i<username.size();++i){
            v[i][0]=username[i];
            v[i][1]=to_string(timestamp[i]);
            v[i][2]=website[i];
        }
        
        
        
        sort(v.begin(),v.end(),acompare);
        
        for(int i=0;i<v.size();++i){
            u[v[i][0]].push_back(v[i][2]);
        }
        
        vector <string> seq(3);
        map<vector<string>,int> m;  //3 seq corresponding visit
        
        for(auto itr=u.begin();itr!=u.end();++itr){
            //for every user
            set<vector<string>> se;
            vector <string> sites=itr->second;
            for(int i=0;i<sites.size();++i){
                for(int j=i+1;j<sites.size();++j){
                    for(int k=j+1;k<sites.size();++k){
                        //m[{sites[i],sites[j],sites[k]}]++;
                        se.insert({sites[i],sites[j],sites[k]});
                    }
                }
            }
            for(auto itr=se.begin();itr!=se.end();++itr){
                m[*itr]++;
            }
        }
        
        map<vector<string>,int>::iterator it,ans=m.begin();
        int count=0;
        
        for (it=m.begin();it!=m.end();it++){
            if(it->second>count){
                ans=it; count=it->second;
            }
            else if(it->second==count){
                //choose lexicographically smallest 
                bool modify=true;
                int i,j;
                for(i=0;i<3;++i){   //for 3 seq website
                    for(j=0;j<min((it->first)[i].length(),(ans->first)[i].length());++j)
                    {
                        if((it->first)[i][j]<(ans->first)[i][j]){cout<<"hi";modify=false;break;}
                        else if((it->first)[i][j]>(ans->first)[i][j]){break;}
                    }
                    if(j<min((it->first)[i].length(),(ans->first)[i].length()))break;
                    if(!modify || ((it->first)[i].length()<(ans->first)[i].length())) {ans=it;break;}
                }
                
            }
            //cout<<ans->second<<" ";for(int i=0;i<3;++i)cout<<(ans->first)[i]<<" ";cout<<"\n";
        }
        
        return ans->first;
    }
};
