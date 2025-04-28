// Author -> Ridham Garg

class Solution {
public:
    // Depth First Search (DFS) function to traverse the graph and mark visited nodes
    void dfs(int i, unordered_map<int, vector<int>>& mp, vector<bool>& visited, vector<int>& edge) {
        visited[i] = true;  // Mark the current node as visited
        // Traverse the neighbors of the current node
        for(int a: mp[i]) {
            // Skip the current edge (which is being checked for redundancy)
            if((a == edge[0] && i == edge[1]) || (a == edge[1] && i == edge[0])) 
                continue;
            // If the neighbor has not been visited, perform DFS on it
            if(visited[a] == false) {
                dfs(a, mp, visited, edge);
            }
        }
    }

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        vector<int> ans;  // This will store the redundant edge
        unordered_map<int, vector<int>> mp;  // Adjacency list to represent the graph
        
        // Construct the graph using the edges
        for (auto edge : edges) {
            int from = edge[0];
            int to = edge[1];
            mp[from].push_back(to);
            mp[to].push_back(from);  // As the graph is undirected, add both directions
        }
        
        int n = mp.size();  // Number of nodes in the graph
        // Iterate over all edges to find the redundant one
        for (auto edge : edges) {
            vector<bool> visited(n + 1, false);  // Initialize visited array for the current DFS traversal
            
            // Start DFS from node 1 and try to detect the cycle created by removing the current edge
            dfs(1, mp, visited, edge);
            
            int i = 1;
            // Find the first unvisited node, which means it is not reachable with the current edge
            while (i <= n) {
                if (visited[i] == false)
                    break;
                i++;
            }
            
            // If all nodes are visited, it means this edge was redundant and part of a cycle
            if (i == n + 1) {
                ans = edge;  // The current edge is redundant
            }
        }
        
        return ans;  // Return the redundant edge
    }
};
