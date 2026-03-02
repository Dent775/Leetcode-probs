class Solution {
public:
    int minSwaps(vector<vector<int>>& grid) {
        vector<int> copy;
        for(int i=0;i<grid.size();i++)
        {
            int pos=-1;
            for(int j=grid[0].size()-1;j>=0;j--)
            {
                if(grid[i][j]==1)
                {
                   pos=j;
                    break;
                }
            }
            copy.push_back(pos);
        }
        int ans=0;
        int n=copy.size();
        for(int i=0;i<n;i++)
        {
            int j=i;
            while(j<n&&copy[j]>i)
            j++;
            if(j==n)
            return -1;
            while(j>i)
            {
                    swap(copy[j],copy[j-1]);
                    ans++;
                    j--;
            }
        }
        return ans;
    }
};