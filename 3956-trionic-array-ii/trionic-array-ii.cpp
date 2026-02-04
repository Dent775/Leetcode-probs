class Solution {
public:
    long long maxSumTrionic(vector<int>& nums) {

        int n = nums.size();
        long long ans = LLONG_MIN;

        for (int i = 1; i < n - 2; i++) {

            int l = i, r = i;
            long long midSum = nums[i];

            while (r + 1 < n && nums[r + 1] < nums[r])
                midSum += nums[++r];

            if (r == i) continue;

            int midEnd = r;

            long long bestL = LLONG_MIN, bestR = LLONG_MIN;
            long long curL = 0, curR = 0;

            while (l - 1 >= 0 && nums[l - 1] < nums[l]) {
                curL += nums[--l];
                bestL = max(bestL, curL);
            }

            if (l == i) continue;

            while (r + 1 < n && nums[r + 1] > nums[r]) {
                curR += nums[++r];
                bestR = max(bestR, curR);
            }

            if (r == midEnd) continue;

            i = r - 1;
            ans = max(ans, bestL + midSum + bestR);
        }

        return ans;
    }
};