class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> InDegree(numCourses, 0);
        vector<int> topoSort;

        vector<vector<int>> adj(numCourses);

        for (const auto& pre : prerequisites) {
            adj[pre[1]].push_back(pre[0]);
            InDegree[pre[0]]++; 
        }

        queue<int> q;


        for (int i = 0; i < numCourses; i++) {
            if (InDegree[i] == 0) q.push(i);
        }

        while (!q.empty()) {
            int node = q.front();
            q.pop();
            topoSort.push_back(node);

            for (auto neighbor : adj[node]) {
                InDegree[neighbor]--;
                if (InDegree[neighbor] == 0) q.push(neighbor);
            }
        }

        if (topoSort.size() == numCourses) return topoSort;
        return {};        
    }
};