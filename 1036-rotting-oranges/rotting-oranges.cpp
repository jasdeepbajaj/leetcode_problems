class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        int time_counter = 0;

        vector<pair<int,int>> movements = {{1,0}, {0,1}, {-1,0}, {0,-1}};
        
        // {{row,col},time}
        queue<pair<pair<int, int>, int>> q;
        
        vector<vector<int>> vis(m, vector(n, 0));
        for(int i=0; i<m; i++){
            for (int j = 0; j<n; j++){
                if (grid[i][j] == 2){
                    q.push({{i,j},0});
                    vis[i][j] = 2;

                }
            }
        }
        while(!q.empty()){
            int row = q.front().first.first;
            int col = q.front().first.second;
            int time = q.front().second;
            time_counter = max(time, time_counter);
            q.pop();

            for(auto itr: movements){
                int new_row = row + itr.first;
                int new_col = col + itr.second;
                if (new_row >= 0 && new_row<m && new_col>=0 && new_col<n && vis[new_row][new_col] !=2 && grid[new_row][new_col] == 1){
                    vis[new_row][new_col] = 2;
                    q.push({{new_row, new_col}, time + 1});
                }
            }

        

        }
        for(int i=0; i<m; i++){
            for (int j = 0; j<n; j++){
                if (vis[i][j] != 2 && grid[i][j] == 1){
                    return -1;
                }
            }
        }

        return time_counter;
            
         

    }
};