class Solution {
private:
    int delr[4] = {-1, 0, +1, 0};
    int delc[4] = {0, +1, 0, -1};
    void dfs(vector<vector<int>>& height, int i, int j,
             vector<vector<int>>& vis, vector<vector<bool>>& pac) {

        vis[i][j] = 1;
        for (int k = 0; k < 4; k++) {
            int nr = i + delr[k];
            int nc = j + delc[k];
            if (nr >= 0 && nr < height.size() && nc >= 0 &&
                nc < height[0].size() && !vis[nr][nc] &&
                height[nr][nc] >= height[i][j]) {
                dfs(height, nr, nc, vis, pac);
            } else
                pac[i][j] = true;
        }
    }

public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();
        vector<vector<bool>> pac(n, vector<bool>(m, false));
        vector<vector<bool>> atl(n, vector<bool>(m, false));
        vector<vector<int>> visited(n, vector<int>(m, 0));
        for (int i = 0; i < n; i++){
            dfs(heights, i, 0, visited, pac);
        }
        for (int i = 0; i < m; i++){
            dfs(heights, 0, i, visited, pac);
        }
        vector<vector<int>> vis2(n, vector<int>(m, 0));
        for (int i = 0; i < n; i++) {
            dfs(heights, i, m - 1, vis2, atl);
        }
        for (int i = 0; i < m; i++) {
            dfs(heights, n - 1, i, vis2, atl);
        }
        vector<vector<int>> ans;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (pac[i][j] && atl[i][j])
                    ans.push_back({i, j});
            }
        }
        return ans;
    }
};
