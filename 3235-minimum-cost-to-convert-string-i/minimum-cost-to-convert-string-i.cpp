class Solution {
public:
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        vector<vector<pair<char,int>>> adj(26);
        int arr[26][26];
        const int INF = 0x3f3f3f3f;
        memset(arr, 0x3f, sizeof(arr));
        int n=original.size();
        for(int i=0;i<n;i++)
        {
            int src=original[i]-'a';
            int dst=changed[i]-'a';
            int edw=cost[i];
            arr[src][dst]=min(edw,arr[src][dst]);
        }
        for(int i=0;i<26;i++)
        arr[i][i] = 0;

        for(int k=0;k<26;k++)
        {
            for(int i=0;i<26;i++)
            {
                for(int j=0;j<26;j++)
                {
                    if(arr[i][k]<INF && arr[k][j]<INF)
                    arr[i][j]=min(arr[i][j],(arr[i][k]+arr[k][j]));
                }
            }
        }
        long long ans=0;
        for(int i=0;i<source.size();i++)
        {
            int src=source[i]-'a';
            int dst=target[i]-'a';
            int val=arr[src][dst];
            if(val==INF)
            return -1;
            ans+=val;
        }
        return ans;
    }
};