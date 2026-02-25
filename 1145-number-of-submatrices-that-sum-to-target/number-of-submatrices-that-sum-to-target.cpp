class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        int m=matrix.size();
        int n=matrix[0].size();
        int ans=0;
        vector<vector<int>> prefix(m+1,vector<int>(n+1,0));
        for(int i=1;i<=m;i++)
        {
            for(int j=1;j<=n;j++)
            {
                prefix[i][j]=prefix[i-1][j]+prefix[i][j-1]+matrix[i-1][j-1]-prefix[i-1][j-1];
            }
        }
        for(int r1=0;r1<m;r1++)
        {
            for(int c1=0;c1<n;c1++)
            {
                for(int r2=r1;r2<m;r2++)
                {
                    for(int c2=c1;c2<n;c2++)
                    {
                        int sum=prefix[r2+1][c2+1]-prefix[r1][c2+1]-prefix[r2+1][c1]+prefix[r1][c1];
                if(sum==target)
                ans++;
                    }
                }
            }
        }
        return ans;
    }
};