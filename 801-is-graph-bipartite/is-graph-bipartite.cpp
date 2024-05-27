class Solution {
private:
    bool dfs(int node, int color, vector<int> &visited, vector<vector<int>>& graph){
        visited[node] = color;

        for (auto itr: graph[node]){
            if(visited[itr]==-1){
                if (dfs(itr, !color, visited, graph)==false) return false;
            }
            else if (visited[itr]==color){
                return false;
            }
        }
        return true;
    }

public:
    bool isBipartite(vector<vector<int>>& graph) {
        int m = graph.size();
        vector<int> visited(m, -1);
        for (int i =0; i<m; i++){
            if(visited[i] == -1){
                if(!dfs(i, 0, visited, graph)){return false;}
                
            }
        }
        return true;
    }
};