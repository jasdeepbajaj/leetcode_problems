class Solution {
private:
    bool checkBipartiteForOneComponent(int start, vector<vector<int>> &graph, vector<int> &color){

        queue<int> q;
        int n = graph.size();

        q.push(start);
        color[start] = 0;
        
        while(!q.empty()){
            int node = q.front();
            int curr_node_color = color[node];
            q.pop();

            for (auto it:graph[node]){
                if (color[it] == -1){
                    color[it] = !curr_node_color;
                    q.push(it);
                }
                else if (color[it] == curr_node_color){
                    return false;
                }
                else{
                    continue;
                }
            }
        }

        return true;

    }
public:
    bool isBipartite(vector<vector<int>>& graph) {

        int n = graph.size();
        vector<int> color(n, -1);

        for(int i = 0; i<graph.size(); ++i){
            if (color[i] == -1){
                if (checkBipartiteForOneComponent(i, graph, color) == false) return false;
            }
        }
        return true;
    }
};