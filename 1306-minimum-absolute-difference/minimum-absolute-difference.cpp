class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& nums) {
        vector<vector<int>> ans;
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int mini=INT_MAX;
        for(int i=0;i<n-1;i++)
        {
            mini=min(mini,abs(nums[i]-nums[i+1]));
        }
        for(int i=0;i<n-1;i++)
        {
            int diff=abs(nums[i]-nums[i+1]);
            if(diff==mini)
            {
                ans.push_back({nums[i],nums[i+1]});
            }
        }
        return ans;
    }
};