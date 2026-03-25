class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        long long m=grid.size();
        long long n=grid[0].size();
        vector<vector<long long>> pre(m+1,vector<long long>(n+1,0));
        for(int i=1;i<=m;i++)
        {
            for(int j=1;j<=n;j++)
            {
                pre[i][j]=pre[i-1][j]+pre[i][j-1]+grid[i-1][j-1]-pre[i-1][j-1];
            }
        }
        for(int i=1;i<=m;i++)
        {
            long long sum=pre[i][n];
            if((pre[m][n]-sum)==sum)
            return true;
        }
        for(int j=1;j<=n;j++)
        {
            long long sum=pre[m][j];
            if((pre[m][n]-sum)==sum)
            return true;
        }
        return false;
    }
};