class Solution {

private:
    void dfs(int row, int col, vector<vector<int>> &vis, vector<vector<char>>& board){
        int m = board.size();
        int n = board[0].size();
        vis[row][col] = 1;

        vector<pair<int, int>> movements = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

        for (auto itr: movements){
            int new_row = row + itr.first;
            int new_col = col + itr.second;
            if (new_row>=0 && new_col>=0 && new_row<m && new_col <n && board[new_row][new_col]=='O' && !vis[new_row][new_col]){
                dfs(new_row, new_col, vis, board);
            }
            
        }
        return;
    }

public:
    void solve(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();
        
        
        vector<vector<int>> vis(m, vector<int>(n,0));

        for (int i=0; i<m; i++){
            for (int j=0 ; j<n; j++){
                if (board[i][j] == 'O' && (i==0 || j==0 || i == (m-1)|| j == (n-1))){
                    dfs(i, j, vis, board);
                }
            }
        }
        for (int i=0; i<m; i++){
            for (int j=0 ; j<n; j++){
                if (!vis[i][j] && board[i][j] == 'O'){
                    board[i][j] = 'X';
                }
            }
        }


    }
};