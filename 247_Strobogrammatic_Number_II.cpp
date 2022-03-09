class Solution {
public:
    vector<string> findStrobogrammatic(int n) {
        
        vector<string> one={"0","1","8"};
        vector<string> two={"11","69","96","88","00"};
        vector<string> prevo={"0","1","8"};
        vector<string> preve={"11","69","96","88"};
        
        for(int i=3;i<=n;i++){
            
            vector <string> buff=preve;
            if(i%2==1)
            {
                prevo.clear();
                for(int j=0;j<3;++j)        // for 0,1,8
                {
                    for(int k=0;k<buff.size();++k)
                    {
                        if(j==0)buff[k].insert(i/2,one[j]);
                        else buff[k][i/2]=one[j][0];
                    }
                    prevo.insert(prevo.end(),buff.begin(),buff.end());    
                }
            }                
            else{
                preve.clear();
                for(int j=0;j<5;++j)        // for "11","69","96","88","00"
                {
                    for(int k=0;k<buff.size();++k)
                    {
                        if(j==0)buff[k].insert(i/2-1,two[j]);
                        else {
                            
                            buff[k][i/2-1]=two[j][0];
                            buff[k][i/2]=two[j][1];
                        }
                    }
                    preve.insert(preve.end(),buff.begin(),buff.end());    
                }
            }            
        }
        if(n%2==1)return prevo;
        return preve;
    }
};