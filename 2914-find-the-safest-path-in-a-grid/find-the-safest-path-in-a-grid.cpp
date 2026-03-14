class Solution {
public:
    int dr[4]={1,-1,0,0};
    int dc[4]={0,0,-1,1};
    
    void bfs(queue<pair<int,int>>& q,vector<vector<int>>& grid,vector<vector<int>>& minDist)
    {
        int n=grid.size();
        while(!q.empty())
        {
            int sz=q.size();
            auto [i,j]=q.front();
            q.pop();
                for(int k=0;k<4;k++)
                {
                    int nr=i+dr[k];
                    int nc=j+dc[k];
                    if(nr>=0&&nc>=0&&nr<n&&nc<n)
                    {
                        if(minDist[nr][nc]>minDist[i][j]+1)
                        {
                            minDist[nr][nc]=minDist[i][j]+1;
                            q.push({nr,nc});
                        }
                    }
                }
        }
    }

    int maximumSafenessFactor(vector<vector<int>>& grid) {
        int n=grid.size();
        vector<vector<int>> minDist(n,vector<int>(n,INT_MAX));
        queue<pair<int,int>> q;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]==1)
                {
                    minDist[i][j]=0;
                    q.push({i,j});
                }
            }
        }
        bfs(q,grid,minDist);
        vector<vector<int>> vis(n,vector<int>(n,0));
        priority_queue<pair<int,pair<int,int>>> pq;
        pq.push({minDist[0][0],{0,0}});
        while(!pq.empty())
        {
            int ans=pq.top().first;
            auto cd=pq.top().second;
            pq.pop();
            auto[i,j]=cd;
            if(i==n-1&&j==n-1)
            return ans;
            for(int k=0;k<4;k++)
                {
                    int nr=i+dr[k];
                    int nc=j+dc[k];
                    if(nr>=0&&nc>=0&&nr<n&&nc<n&&!vis[nr][nc])
                    {
                        int a=min(ans,minDist[nr][nc]);
                        pq.push({a,{nr,nc}});
                        vis[nr][nc]=1;
                    }
                }
        }
        return -1;
    }
};