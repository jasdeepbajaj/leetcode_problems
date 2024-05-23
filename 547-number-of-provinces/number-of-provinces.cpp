class Solution {

private:
    void bfs(int node,vector<vector<int>>& isConnected, vector<int> &vis){
        queue<int> q;
        q.push(node);

        while(!q.empty()){
            node = q.front();
            q.pop();
            vis[node] = 1;

            for(int i = 0; i< isConnected.size(); i++){
                if (isConnected[node][i] == 1 and !vis[i]){
                    q.push(i);
                }
            }
        }
    }
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        vector<int> vis(isConnected.size(), 0);
        int numberofProvinces = 0;
        queue<int> q;

        for(int i = 0; i<isConnected.size(); i++){
            if(!vis[i]){
                numberofProvinces++;
                bfs(i, isConnected, vis);
            }

        }
        return numberofProvinces;
    }
};