class Solution {
public:
    int longestBalanced(string s) {
        int freq[26];
        memset(freq,0,sizeof(freq));
        int ans=0;
        for(int i=0;i<s.size();i++)
        {
            memset(freq,0,sizeof(freq));
            int maxfreq=0,uniq=0;
            for(int j=i;j<s.size();j++)
            {   
                if(freq[s[j]-'a']==0)
                uniq++;
                freq[s[j]-'a']++;
                maxfreq=max(maxfreq,freq[s[j]-'a']);
                if(maxfreq*uniq==(j-i+1))
                ans=max(ans,j-i+1);
            }
        }
        return ans;
    }
};