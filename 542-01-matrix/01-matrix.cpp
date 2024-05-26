class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        vector<vector<int>> vis(m, vector<int>(n,0));
        vector<vector<int>> ans(m, vector<int>(n,INT_MAX));

        vector<pair<int, int>> movements = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

        queue<pair<int,int>> q;
        for(int i = 0; i<m; i++){
            for(int j=0; j<n; j++){
                if (mat[i][j] == 0){
                    vis[i][j] = 1;
                    ans[i][j] = 0;
                    q.push({i,j});
                }
            }
        }

        while(!q.empty()){
            int row = q.front().first;
            int col = q.front().second;
            q.pop();

            for (auto itr: movements){
                int new_row = row + itr.first;
                int new_col = col + itr.second;
                if (new_row>=0 && new_row<m && new_col>=0 && new_col<n && !vis[new_row][new_col]){
                    vis[new_row][new_col] = 1;
                    ans[new_row][new_col] = min(ans[row][col] + 1, ans[new_row][new_col]);
                    q.push({new_row, new_col});
                }
            }


        }
        return ans;
    }
};