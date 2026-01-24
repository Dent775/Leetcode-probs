class Solution {
public:
    int minPairSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int l=0;
        int r=nums.size()-1;
        int ans=0;
        while(l<r)
        {
            int sum=nums[l++]+nums[r--];
            ans=max(ans,sum);
        }
        return ans;
    }
};