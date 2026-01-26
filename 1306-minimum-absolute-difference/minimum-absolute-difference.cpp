class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        vector<vector<int>> ans;
        int n=arr.size();
        sort(arr.begin(),arr.end());
        int mini=INT_MAX;
        for(int i=0;i<n-1;i++)
        {
            mini=min(mini,abs(arr[i]-arr[i+1]));
        }
        for(int i=0;i<n-1;i++)
        {
            int diff=abs(arr[i]-arr[i+1]);
            if(diff==mini)
            {
                ans.push_back({arr[i],arr[i+1]});
            }
        }
        return ans;
    }
};