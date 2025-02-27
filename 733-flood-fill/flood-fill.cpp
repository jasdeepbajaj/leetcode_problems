class Solution {
public:
    vector<int> delRow {-1,0,1,0};
    vector<int> delCol {0,1,0,-1};
    int m, n;

    void dfs(int sr, int sc, int origColor, int newColor, vector<vector<int>> &vis, vector<vector<int>> &image) {
        vis[sr][sc] = 1;
        image[sr][sc] = newColor;

        for(int i = 0; i < 4; i++){
            int nRow = sr + delRow[i];
            int nCol = sc + delCol[i];
            if (nRow >= 0 && nRow < m && nCol >= 0 && nCol < n && !vis[nRow][nCol] && image[nRow][nCol] == origColor) {
                dfs(nRow, nCol, origColor, newColor, vis, image);
            }
        }
    }
    
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        m = image.size();
        n = image[0].size();
        int origColor = image[sr][sc];
        if(origColor == color) return image;  // no need to process if the color is the same

        vector<vector<int>> vis(m, vector<int>(n, 0));
        dfs(sr, sc, origColor, color, vis, image);

        return image;
    }
};