class Solution {
public:
    bool isOneEditDistance(string s, string t) {
        
        int slen=s.length(),tlen=t.length();
        bool ans=false;
        
        if(slen==tlen){
            int count=0;
            for(int i=0;i<tlen && count<2;++i)
            {
                if(s[i]!=t[i])count++;
            }
            if(count==1){ans=true;}
        }
        else if(abs(slen-tlen)==1){
        
            
            if(slen<tlen)ans=isOneEditDistance(t,s);
            else{
                int count=0,j=0;
                slen=s.length();
            
                for(int i=0;i<slen && count<2;++i,++j)
                {
                    if(s[i]!=t[j]){--j;count++;}
                }
                if(count<2)ans=true;
            }
        }
        
        return ans;
        
    }
};