class Solution {
public:
    int minimumCost(vector<int>& nums) {
        int sum=nums[0];
        bool val=true;
        int count=1;
        vector<int>  arr(nums.begin(),nums.end());
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size();i++)
        {
            if(count==3)
            break;
            if(val&&nums[i]==arr[0])
            {
                val=false;
            continue;
            }
            sum+=nums[i];
            count++;
        }
        return sum;
    }
};