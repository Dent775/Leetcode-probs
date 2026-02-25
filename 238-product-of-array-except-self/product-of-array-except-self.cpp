class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size();
        vector<int> prefix(n),suffix(n);
        int pre=1,suff=1;
        vector<int> ans;
        int val=0;
        for(int i=0;i<n;i++)
        {
            pre*=nums[i];
            prefix[i]=pre;
            suff*=nums[n-i-1];
            suffix[n-i-1]=suff;
        }
        for(int i=0;i<n;i++)
        {
            val=1;
            if(i-1>=0)
            val*=prefix[i-1];
            if(i+1<n)
            val*=suffix[i+1];
            ans.push_back(val);
        }
        return ans;
    }
};