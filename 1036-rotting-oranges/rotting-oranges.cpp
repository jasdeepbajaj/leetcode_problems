class Solution {
public:
    vector<int> delRow {-1,0,1,0};
    vector<int> delCol {0,1,0,-1};

    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size(); //rows
        int n = grid[0].size(); //cols
        vector<vector<int>> vis(m, vector<int>(n,0));

        queue<pair<pair<int,int>,int>> q; //{{row, col}, time}
        int time_final = 0;


        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 2){
                    q.push({{i,j}, 0});
                    vis[i][j] = 2;
                }
            }
        }
        while(!q.empty()){
            auto front_node = q.front();
            int r = front_node.first.first;
            int c = front_node.first.second;
            int t = front_node.second;
            time_final = max(t, time_final);
            q.pop();

            //traverse in neighbors
            for(int i = 0; i<4; i++){
                int nRow = r + delRow[i];
                int nCol = c + delCol[i];
                if (nRow >= 0 && nRow < grid.size() && nCol >= 0 && nCol < grid[0].size() && grid[nRow][nCol] == 1 && vis[nRow][nCol] != 2){
                    vis[nRow][nCol] = 2;
                    q.push({{nRow, nCol}, t + 1});
                }
            }
        }
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 1 && !vis[i][j]){
                    return -1;
                }
            }
        }

        return time_final;

    }
};