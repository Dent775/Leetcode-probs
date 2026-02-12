class Solution {
public:
    int longestBalanced(string s) {
        vector<int> freq(26,0);
        int ans=0;
        int common=0;
        for(int i=0;i<s.size();i++)
        {
            freq.assign(26,0);

            for(int j=i;j<s.size();j++)
            {   
                int count=0;
                freq[s[j]-'a']++;
                common=freq[s[j]-'a'];
                for(int i=0;i<26;i++)
                {
                    if(freq[i]==0)
                    continue;
                    if(freq[i]==common)
                    continue;
                    count++;
                }
                if(count==0)
                ans=max(ans,j-i+1);
            }
        }
        return ans;
    }
};