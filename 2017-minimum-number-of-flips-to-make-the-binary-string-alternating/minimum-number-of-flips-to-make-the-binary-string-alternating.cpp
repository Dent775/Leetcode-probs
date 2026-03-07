class Solution {
public:
    int minFlips(string s) {
        s=s+s;
        int n=s.size();
        int left=0;
        int mis1=0,mis2=0;
        int ans=INT_MAX;
        for(int right=0;right<n;right++)
        {
            if(s[right]!=((right%2)?'1':'0'))
            mis1++;
            if(s[right]!=((right%2)?'0':'1'))
            mis2++;
            
            if(right-left+1>n/2)
            {
                if(s[left]!=((left%2)?'1':'0'))
            mis1--;
                if(s[left]!=((left%2)?'0':'1'))
            mis2--;
            left++;
            }

            if(right-left+1==n/2)
            ans=min(ans,min(mis1,mis2));
        }
        return ans;
    }
};