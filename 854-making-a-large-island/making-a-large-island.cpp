class DisjointSet{
    public:
    vector<int> parent, size;
    DisjointSet(int n)
    {
        parent.resize(n);
        size.resize(n);
        for(int i=0;i<n;i++)
        {
            parent[i]=i;
            size[i]=1;
        }
    }
    int find(int x)
    {
        if(parent[x]==x)
        return x;
        return parent[x]=find(parent[x]);
    }
    void unionSize(int a,int b)
    {
        int upa=find(a);
        int upb=find(b);
        if(upa==upb)
        return;
        else if(size[upa]<size[upb])
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
    int largestIsland(vector<vector<int>>& grid) {
        int n=grid.size();
        DisjointSet ds(n*n);
        int dr[2]={0,1};
        int dc[2]={1,0};
        int maxi=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]==1)
                {
                    for(int k=0;k<2;k++)
                    {
                        int nr=i+dr[k];
                        int nc=j+dc[k];
                        if(nr>=0&&nc>=0&&nr<n&&nc<n&&
                        grid[nr][nc]==1)
                        {
                            ds.unionSize((i*n+j),(nr*n+nc));
                            maxi=max(maxi,
                            ds.size[ds.find(i*n+j)]);
                        }   
                    }
                }
            }
        }
        int rd[4]={0,0,1,-1};
        int cd[4]={1,-1,0,0};
        int lsum;
        bool zero=false;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]==0)
                {
                    zero=true;
                    lsum=1;
                    unordered_set<int> set;
                    for(int k=0;k<4;k++)
                    {
                        int rn=i+rd[k];
                        int cn=j+cd[k];
                        if(rn>=0&&cn>=0&&rn<n&&cn<n&&
                        grid[rn][cn]==1)
                        {
                           set.insert(ds.find(rn*n+cn));
                        }
                    }
                    for(auto it:set)
                    {
                        lsum+=ds.size[it];
                    }
                    maxi=max(maxi,lsum);
                }
            }
        }
        return zero?maxi:n*n;
    }
};