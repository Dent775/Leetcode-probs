class Solution {
public:
    int minimumPairRemoval(vector<int>& nums) {
        int count =0;
        while(!is_sorted(nums.begin(),nums.end()))
        {
            int idx=find(nums);
            nums[idx]+=nums[idx+1];
            nums.erase(nums.begin()+idx+1);
            count++;
        }
        return count;
    }
    int find(vector<int> &nums)
    {
        int minsum=INT_MAX;
        int idx=0;
        for(int i=0;i<nums.size()-1;i++)
        {
            int sum=nums[i]+nums[i+1];
            if(sum<minsum)
            {
                minsum=sum;
                idx=i;
            }
        }
        return idx;
    }
};