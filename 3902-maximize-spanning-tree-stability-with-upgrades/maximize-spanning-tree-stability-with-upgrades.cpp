class DisjointSet{
    public:
    vector<int> parent,size;
    DisjointSet(int n)
    {
        parent.resize(n);
        size.resize(n,1);
        for(int i=0;i<n;i++)
        {
            parent[i]=i;
        }
    }
    int findUp(int x)
    {
        if(parent[x]==x)
        return x;
    return parent[x]=findUp(parent[x]);
    }

    void unionBySize(int a, int b)
    {
        int upa=findUp(a);
        int upb=findUp(b);
        if(upa==upb)
        return;
        if(size[upa]<size[upb])
        {
            parent[upa]=upb;
            size[upb]+=size[upa];
        }
        else
        {
            parent[upb]=upa;
            size[upa]+=size[upb];
        }
    }
};


class Solution {
public:
    int maxStability(int n, vector<vector<int>>& edges, int k) {
        int ans=INT_MAX;
        DisjointSet ds(n);
        vector<vector<int>> zero;
        vector<int> usedEdges;
        int used=0;
        for(int i=0;i<edges.size();i++)
        {
            if(edges[i][3]==1)
            {
                int u=edges[i][0];
                int v=edges[i][1];
                int wt=edges[i][2];
                if(ds.findUp(u)==ds.findUp(v))
                return -1;
                else
                {
                    ds.unionBySize(u,v);
                    ans=min(ans,wt);
                    used++;
                }
            }
            else
            zero.push_back(edges[i]);
        }
        sort(zero.begin(),zero.end(),[&](vector<int>& a,vector<int>& b){
            return 2*a[2]>2*b[2];
        });

        for(int i=0;i<zero.size();i++)
        {
            
                if(used==n-1)
                break;
                int u=zero[i][0];
                int v=zero[i][1];
                int wt=zero[i][2];
                if(ds.findUp(u)==ds.findUp(v))
                continue;
                ds.unionBySize(u,v);
                used++;
                usedEdges.push_back(wt);
     
        }
        if(used!=n-1)
        return -1;
        sort(usedEdges.begin(),usedEdges.end());
        for(int i=0;i<usedEdges.size()&&k>0;i++)
        {
            usedEdges[i]<<=1;
            k--;
        }
        for(int i=0;i<usedEdges.size();i++)
        {
            ans=min(ans,usedEdges[i]);
        }
        return ans;
    }
};