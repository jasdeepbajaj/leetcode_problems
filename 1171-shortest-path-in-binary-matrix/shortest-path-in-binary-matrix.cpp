class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {

        int m = grid.size();
        int n = grid[0].size();
        if(grid[0][0] == 1 || grid[m-1][n-1] == 1) return -1;
        if(m==1 && n==1) return 1;

        vector<vector<int>> dist(m, vector<int> (n,1e6));
        dist[0][0] = 1;
        queue<pair<int, pair<int, int>>> q;
        q.push({1, {0,0}});

        vector<pair<int, int>> movements = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}, {1,1}, {1,-1}, {-1,1}, {-1,-1}};
        while(!q.empty()){
            int dis = q.front().first;
            int cr = q.front().second.first; 
            int cc = q.front().second.second;
            q.pop();

            for(auto move : movements){
                int nr = cr + move.first;
                int nc = cc + move.second;

                if (nr >= 0 && nr < m && nc >= 0 && nc < n && grid[nr][nc] == 0 && dis + 1 < dist[nr][nc]){
                    dist[nr][nc] = dis + 1;
                    if(nr == m-1 && nc == n-1){
                        return dist[nr][nc];
                    }
                    q.push({dis + 1, {nr, nc}});
                }
            }


        }

        return -1;
    }
};