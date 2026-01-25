class Solution {
public:

    void dfs(vector<vector<int>>& stones, int i,
             vector<bool>& visited, int n) {

        visited[i] = true;

        for (int j = 0; j < n; j++) {
            if (!visited[j] &&
                (stones[i][0] == stones[j][0] ||
                 stones[i][1] == stones[j][1])) {

                dfs(stones, j, visited, n);
            }
        }
    }

    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();
        vector<bool> visited(n, false);
        int components = 0;

        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                dfs(stones, i, visited, n);
                components++;
            }
        }
        return n - components;
    }
};