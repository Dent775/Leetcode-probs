class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();

        vector<vector<int>> dist(n, vector<int>(n, 1e9));
        int dr[4] = {0,0,1,-1};
        int dc[4] = {1,-1,0,0};

        using T = pair<int,pair<int,int>>;
        priority_queue<T, vector<T>, greater<T>> pq;

        dist[0][0] = grid[0][0];
        pq.push({grid[0][0], {0,0}});

        while(!pq.empty()) {
            auto [time, pos] = pq.top();
            auto [r, c] = pos;
            pq.pop();

            if(r == n-1 && c == n-1)
                return time;

            if(time > dist[r][c]) continue;

            for(int k=0;k<4;k++) {
                int nr = r + dr[k];
                int nc = c + dc[k];

                if(nr>=0 && nc>=0 && nr<n && nc<n) {
                    int newTime = max(time, grid[nr][nc]);

                    if(newTime < dist[nr][nc]) {
                        dist[nr][nc] = newTime;
                        pq.push({newTime, {nr,nc}});
                    }
                }
            }
        }
        return -1;
    }
};
