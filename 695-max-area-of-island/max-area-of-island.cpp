class Solution {
public:
    vector<int> delRow {-1,0,1,0};
    vector<int> delCol {0,1,0,-1};
    
    int bfs(int row, int col, vector<vector<int>> &vis, vector<vector<int>>& grid){
        queue<pair<int, int>> q;
        q.push({row, col});
        vis[row][col] = 1;
        int area = 1;

        while(!q.empty()){
            auto front_node = q.front();
            int r = front_node.first;
            int c = front_node.second;
            q.pop();

            //traverse in neighbors
            for(int i = 0; i<4; i++){
                int nRow = r + delRow[i];
                int nCol = c + delCol[i];
                if (nRow >= 0 && nRow < grid.size() && nCol >= 0 && nCol < grid[0].size() && grid[nRow][nCol] == 1 && !vis[nRow][nCol]){
                    vis[nRow][nCol] = 1;
                    q.push({nRow, nCol});
                    area++;
                }
            }
        }
        return area;
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m = grid.size(); //rows
        int n = grid[0].size(); //cols

        int maxArea = 0;
        int area;
        vector<vector<int>> vis(m, vector<int>(n,0));

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(!vis[i][j] && grid[i][j] == 1){
                    maxArea = max (maxArea, bfs(i,j, vis, grid));
                }
            }
        }

        return maxArea;
    }
};