class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int m=triangle.size();
        vector<int> next(m,0);
        for(int i=0;i<m;i++)
        {
            next[i]=triangle[m-1][i];
        }
        for(int i=m-2;i>=0;i--)
        {
            vector<int> curr(m,0);
            for(int j=i;j>=0;j--)
            {
                int d=triangle[i][j]+next[j];
                int dg=triangle[i][j]+next[j+1];
                curr[j]=min(d,dg);
            }
            next=curr;
        }
        return next[0];
    }
};