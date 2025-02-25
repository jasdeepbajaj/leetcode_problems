class Solution {
public:
    // vector<vector<int>> movement{{-1,0}, 
    //                              {0 ,1},
    //                              {1, 0},
    //                              {0, -1}} //up, right, down, left
    vector<int> delRow {-1,0,1,0};
    vector<int> delCol {0,1,0,-1};
    
    void bfs(int row, int col, vector<vector<int>> &vis, vector<vector<char>>& grid){
        queue<pair<int, int>> q;
        q.push({row, col});
        vis[row][col] = 1;

        while(!q.empty()){
            auto front_node = q.front();
            int r = front_node.first;
            int c = front_node.second;
            q.pop();

            //traverse in neighbors
            for(int i = 0; i<4; i++){
                int nRow = r + delRow[i];
                int nCol = c + delCol[i];
                if (nRow >= 0 && nRow < grid.size() && nCol >= 0 && nCol < grid[0].size() && grid[nRow][nCol] == '1' && !vis[nRow][nCol]){
                    vis[nRow][nCol] = 1;
                    q.push({nRow, nCol});
                }
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size(); //rows
        int m = grid[0].size(); //cols

        int count = 0;
        vector<vector<int>> vis(n, vector<int>(m,0));

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(!vis[i][j] && grid[i][j] == '1'){
                    bfs(i,j, vis, grid);
                    count++;
                }
            }
        }

        return count;

    }
};