class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int ans=INT_MAX;
        int left=0;
        int right=k-1;
        while(right<n)
        {
            ans=min(ans,nums[right]-nums[left]);
            right++;
            left++;
        }
        return ans;
    }
};