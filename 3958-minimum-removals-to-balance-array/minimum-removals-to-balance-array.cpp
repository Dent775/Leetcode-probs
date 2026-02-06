class Solution {
public:
    int minRemoval(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int left=0;
        int right=0;
        int ans=0;
        while(right<nums.size())
        {
            while(right<nums.size()&&nums[right]<=(long long)nums[left]*k)
            {
                ans=max(ans,right-left+1);
                right++;
            }
            left++;
        }
        if(ans==0)
        return ans;
        return nums.size()-ans;
    }
};