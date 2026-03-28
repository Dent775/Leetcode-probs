class Solution {
public:
    int m,n;
    int dfs(int i,int j, int xori,vector<vector<int>>& grid, vector<vector<vector<int>>>& dp)
    {
        if(i>=m||j>=n)
        return INT_MAX;
        xori=xori^grid[i][j];
        if(i==m-1&&j==n-1)
        return xori;
        if(dp[i][j][xori]!=-1)
        return dp[i][j][xori];
        int right=dfs(i,j+1,xori,grid,dp);
        int down=dfs(i+1,j,xori,grid,dp);
        return dp[i][j][xori]=min(right,down);
    }
    
    
    int minCost(vector<vector<int>>& grid) {
        m=grid.size();
        n=grid[0].size();
        vector<vector<vector<int>>> dp(m,vector<vector<int>>(n,vector<int>(1024,-1)));
        return dfs(0,0,0,grid,dp);
    }
};