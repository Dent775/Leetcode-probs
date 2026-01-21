class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        int n=nums.size();
        vector<int> ans;
        for(int it:nums)
        {
            if(it==2)
            {
                ans.push_back(-1);
                continue;
            }
            ans.push_back(it-flip(it));
        }
        return ans;
    }

    private:
    int flip(int n)
    {
        int bit=1;
        while(n&bit)
        {
            bit<<=1;
        }
        return bit>>1;
    }
};