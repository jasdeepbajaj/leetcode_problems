class Solution {
public:

    int m, n;
    vector<vector<int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

    void dfs(vector<vector<int>>& heights, int r, int c, vector<vector<int>>& vis) {
        vis[r][c] = 1;
        for (auto& d : directions) {
            int newRow = r + d[0];
            int newCol = c + d[1];
            
            if (newRow >= 0 && newRow < m && newCol >= 0 && newCol < n && !vis[newRow][newCol] && heights[newRow][newCol] >= heights[r][c]) dfs(heights, newRow, newCol, vis);
        }
    }
    
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        m = heights.size();
        n = heights[0].size();
        
        vector<vector<int>> vis_pacific(m, vector<int>(n, 0));
        vector<vector<int>> vis_atlantic(m, vector<int>(n, 0));
        

        for (int i = 0; i < m; i++) dfs(heights, i, 0, vis_pacific); //left
        for (int j = 0; j < n; j++) dfs(heights, 0, j, vis_pacific); //top
        for (int i = 0; i < m; i++) dfs(heights, i, n - 1, vis_atlantic); //right
        for (int j = 0; j < n; j++) dfs(heights, m - 1, j, vis_atlantic); //bottom
        
        vector<vector<int>> result;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (vis_pacific[i][j] && vis_atlantic[i][j]) {
                    result.push_back({i, j});
                }
            }
        }
        
        return result;
    }
};
