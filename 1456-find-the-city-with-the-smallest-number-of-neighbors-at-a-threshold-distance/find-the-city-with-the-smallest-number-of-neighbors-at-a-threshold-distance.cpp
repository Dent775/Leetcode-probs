class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int dt) {
       int mini=INT_MAX;
       int ans=0;
       vector<vector<pair<int,int>>> adj(n);

       for(auto it: edges)
       {
        int nxt=it[1];
        int curr=it[0];
        int edw=it[2];
        adj[curr].push_back({nxt,edw});
        adj[nxt].push_back({curr,edw});
       }
       for(int k=0;k<n;k++)
       {
        vector<int> vis(n,1e9);
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        pq.push({0,k});
        vis[k]=0;
        while(!pq.empty())
        {
            auto[dist,node]=pq.top();
            pq.pop();
            if(dist>dt)
            continue;
            for(auto it:adj[node])
            {
                int edw=it.second;
                int nnode=it.first;
                if(dist+edw<vis[nnode])
                {
                    pq.push({(dist+edw),nnode});
                    vis[nnode]=dist+edw;
                }
            }
        }
        int count=0;
        for(int i=0;i<vis.size();i++)
        {
            if(i!=k&&vis[i]<=dt)
            count++;
        }
        if(count<mini || (count==mini && k>ans))
        {
            mini=count;
            ans=k;
        }
       }
       return ans; 
    }
};