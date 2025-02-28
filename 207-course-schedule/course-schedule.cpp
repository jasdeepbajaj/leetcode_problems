class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> InDegree(numCourses, 0);
        vector<int> topoSort;

        // Create the adjacency list with the correct size
        vector<vector<int>> adj(numCourses);

        // Build the graph from prerequisites
        for (const auto& pre : prerequisites) {
            adj[pre[1]].push_back(pre[0]);
            InDegree[pre[0]]++; // Update in-degree while building the graph
        }

        queue<int> q;

        // Push nodes with in-degree 0 into the queue
        for (int i = 0; i < numCourses; i++) {
            if (InDegree[i] == 0) q.push(i);
        }

        // Perform topological sort using Kahn's algorithm
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            topoSort.push_back(node);

            for (auto neighbor : adj[node]) {
                InDegree[neighbor]--;
                if (InDegree[neighbor] == 0) q.push(neighbor);
            }
        }

        // Check if the topological sort includes all courses
        return topoSort.size() == numCourses;
    }
};
