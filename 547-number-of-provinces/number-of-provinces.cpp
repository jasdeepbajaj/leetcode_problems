class Solution {
private:
    void dfs(int node, vector<vector<int>> &isConnected, vector<int> &vis){
        vis[node] = 1;
        for(int i = 0; i<isConnected.size(); i++){
            if (isConnected[node][i]==1 && !vis[i]){
                dfs(i, isConnected,  vis);
            }
        }
    }

public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int numberofProvinces = 0;
        vector<int> vis(isConnected.size(),0);
        for(int i=0; i<isConnected.size(); i++){
            if (!vis[i]){
                numberofProvinces++;
                dfs(i, isConnected, vis);
            }
        }
        return numberofProvinces;
    }
};