class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        int cn=connections.size();
        vector<vector<int>> adj(n);
        vector<int> vis(n,0);
        for(auto it:connections)
        {
            int curr=it[0];
            int nxt=it[1];
            adj[curr].push_back(nxt);
            adj[nxt].push_back(curr);
        }
        if((n-1)>cn)
        return -1;
        int count=0;
        for(int i=0;i<n;i++)
        {
            if(vis[i]==0)
            {
            bfs(i,adj,vis);
            count++;
            }
        }
        return count-1;
    }

    void bfs(int i, vector<vector<int>> & adj,vector<int>& vis)
    {
        vis[i]=1;
        for(auto j:adj[i])
        {
            if(!vis[j])
            {
                bfs(j,adj,vis);
            }
        }
    }
};