class Solution {
public:
    vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid) {
        const int MOD=12345;
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>> ans(m,vector<int>(n));
        long long pre=1;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                ans[i][j]=pre;
                pre=(pre*(grid[i][j]%MOD))%MOD;
            }
        }
        long long suf=1;
        for(int i=m-1;i>=0;i--)
        {
            for(int j=n-1;j>=0;j--)
            {
                ans[i][j]=(1LL*ans[i][j]*suf)%MOD;
                suf=(suf*(grid[i][j]%MOD))%MOD;
            }
        }
        return ans;
    }
};