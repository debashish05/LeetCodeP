class Solution {
public:
    
    bool check(int f[])
    {
        for(int i=0;i<26;++i){
            if(f[i]>1)return false;
        }
        return true;
    }
    
    int numKLenSubstrNoRepeats(string s, int k) {
        int f[26]={0};
        int ans=0;
        for(int i=0;i<k && i<s.length();++i)
        {
            f[s[i]-'a']++;
        }
        
        if(s.length()>=k && check(f))ans++;
        
        for(int i=k;i<s.length();++i)
        {
            f[s[i-k]-'a']--;
            f[s[i]-'a']++;
            if(check(f))ans++;
        }
        
        return ans;
    }
};