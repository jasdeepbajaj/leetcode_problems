class Solution {
private:
    void bfs(int sr, int sc, int color, vector<vector<int>>& image, vector<vector<int>> &visited, int current_val){
        queue<pair<int, int>> q;
        q.push({sr,sc});
        vector<pair<int, int>> movements = {{1,0}, {0,1}, {-1,0}, {0,-1},{0,0}};

        while(!q.empty()){
            int curr_x = q.front().first;
            int curr_y = q.front().second;
            q.pop();

            for(auto itr: movements){
                int new_x = curr_x + itr.first;
                int new_y = curr_y + itr.second;
                if (0 <= new_x && new_x < image.size() && 0 <= new_y && new_y < image[0].size() && (image[new_x][new_y] == current_val) && !visited[new_x][new_y]){
                    q.push({new_x, new_y});
                    image[new_x][new_y] = color;
                    visited[new_x][new_y] = 1;
                }
            }
        } 
    }
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int m = image.size(); 
        int n = image[0].size();
        int curr_pix_val = image[sr][sc];
        vector<vector<int>> visited(m, vector<int>(n, 0));
        bfs(sr, sc, color, image, visited, curr_pix_val);
        return image;
    }
};