class Solution {
public:

    int solve(int n, vector<int>& nums,vector<int>& dp)
    {
        if(n==0)
        return nums[0];
        if(n<0)
        return 0;
        if(dp[n]!=-1)
        return dp[n];
        int pick=nums[n]+solve(n-2,nums,dp);
        int npick=0+solve(n-1,nums,dp);
        return dp[n]=max(pick,npick);
    }

    int rob(vector<int>& nums) {
        if(nums.size()==1)
        return nums[0];
        vector<int> n1(nums.begin()+1,nums.end());
        vector<int> n2(nums.begin(),nums.end()-1);
        int s1=n1.size();
        int s2=n2.size();
        vector<int> dp(s1,-1);
        vector<int> dp1(s2,-1);
        return max(solve(s1-1,n1,dp),solve(s2-1,n2,dp1));
    }
};