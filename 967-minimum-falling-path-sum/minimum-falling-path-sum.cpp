class Solution {
public:
    
    int solve(int i,int j,vector<vector<int>>& matrix,vector<vector<int>>& dp )
    {
        if(j<0||j>=matrix[0].size())
        return 1e9;
        if(i==0)
        {
            return matrix[0][j];
        }
        if(dp[i][j]!=INT_MAX)
        return dp[i][j];
        int top=matrix[i][j]+solve(i-1,j,matrix,dp);
        int top_left=matrix[i][j]+solve(i-1,j-1,matrix,dp);
        int top_right=matrix[i][j]+solve(i-1,j+1,matrix,dp);
        return dp[i][j]=min(top,min(top_left,top_right));
    }
    
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int m=matrix.size();
        int n=matrix[0].size();
        vector<vector<int>> dp(m,vector<int>(n,INT_MAX));
        int mini=1e9;
        for(int j=0;j<n;j++)
        {
            mini=min(mini,solve(m-1,j,matrix,dp));
        }
        return mini;
    }
};