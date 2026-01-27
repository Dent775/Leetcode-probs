class Solution {
public:
    int minCost(int n, vector<vector<int>>& edges) {
        vector<vector<pair<int,int>>> adj(n);
        vector<int> path(n,1e9);
        for(auto it:edges)
        {
            int curr=it[0];
            int nxt=it[1];
            int wt=it[2];
            adj[curr].push_back({nxt,wt});
            adj[nxt].push_back({curr,2*wt});
        }
        using t=pair<int,int>;
        priority_queue<t,vector<t>,greater<t>> pq;
        pq.push({0,0});
        path[0]=0;
        while(!pq.empty())
        {
            auto[dist,node]=pq.top();
            pq.pop();
            if(node==n-1)
            return dist;
            if(dist>path[node])
            continue;
            for(auto it:adj[node])
            {
                int nnode=it.first;
                int edw=it.second;
                if(dist+edw<path[nnode])
                {
                    pq.push({dist+edw,nnode});
                    path[nnode]=dist+edw;
                }
            }
        }
        return -1;
    }   
};