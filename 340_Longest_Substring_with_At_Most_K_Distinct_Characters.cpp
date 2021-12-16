class Solution {
public:
    int lengthOfLongestSubstringKDistinct(string s, int k) {

        unordered_map <char,int> u;
        int sindex=0,ans=0;

        for(int i=0;i<s.length();++i)
        {
            u[s[i]]++;

            while(u.size()>k && sindex<=i){
                u[s[sindex]]--;
                if(u[s[sindex]]==0)u.erase(s[sindex]);
                sindex++;
            }
            ans=max(ans,i-sindex+1);
        }
        return ans;
    }
};