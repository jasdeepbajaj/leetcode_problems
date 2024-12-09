class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        
        int m = grid.size();
        int n = grid[0].size();
        
        //defining the queue and visited array
        queue<pair<pair<int, int>, int>> q;
        vector<vector<int>> vis(m, vector<int>(n,0));
        
        //initializing the queue and the visited array
        for(int i = 0; i<m; i++){
            for(int j = 0; j<n; j++){
                if(grid[i][j] == 2){
                    q.push({{i,j}, 0});
                    vis[i][j] = 2;
                }
            }
        }

        int time_counter = 0;

        vector<pair<int,int>> movements = {{1,0}, {0,1},{-1,0},{0,-1}}; //down, right, up, left

        while(!q.empty()){
            int time = q.front().second;
            int row = q.front().first.first;
            int col = q.front().first.second;

            time_counter = max(time, time_counter);
            q.pop();


            for(auto movement : movements){
                
                int new_row = row + movement.first;
                int new_col = col + movement.second;

                // if (0 <= new_row < m && 0 <= new_col < n && grid[new_col][new_row] == 1){
                if (new_row >= 0 && new_row<m && new_col>=0 && new_col<n && vis[new_row][new_col] !=2 && grid[new_row][new_col] == 1){
                    q.push({{new_row, new_col}, time + 1});
                    vis[new_row][new_col] = 2;
                }

            }    


        }

        for(int i = 0; i<m; i++){
            for(int j = 0; j<n; j++){
                if(vis[i][j] != 2 && grid[i][j] ==1 ){
                    return -1;
                }
            }
        }

        return time_counter;



    }
};