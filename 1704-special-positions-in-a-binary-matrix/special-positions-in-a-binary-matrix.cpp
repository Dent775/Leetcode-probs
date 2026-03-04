class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
      int rc=0,cc=0;
      int r=mat.size();
      int c=mat[0].size();
      vector<int> row(r,0),col(c,0);
      for(int i=0;i<mat.size();i++)
      {
        for(int j=0;j<mat[0].size();j++)
        {
            if(mat[i][j]==1)
            {
                row[i]++;
                col[j]++;
            }
        }
      }
      int ans=0;
      for(int i=0;i<r;i++)
      {
        for(int j=0;j<c;j++)
        {
            if(row[i]==1&&col[j]==1&&mat[i][j]==1)
            ans++;
        }
      }  
      return ans;
    }
};