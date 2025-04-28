//Author -Ridham Garg
class Solution {
public:
    // BFS function to traverse the graph and mark visited nodes, excluding the current edge
    void bfs(int i, unordered_map<int, vector<int>>& mp, vector<bool>& visited, vector<int>& edge) {
        visited[i] = true;  // Mark the starting node as visited
        queue<int> q;  // Queue for BFS traversal
        q.push(i);  // Add the starting node to the queue

        // Perform BFS to explore all reachable nodes, except the edge being tested for redundancy
        while (q.size()) {
            int top = q.front();  // Get the front element of the queue
            q.pop();  // Remove the front element

            // Traverse all the neighbors of the current node
            for (int a : mp[top]) {
                // Skip the current edge (the one being checked for redundancy)
                if ((top == edge[0] && a == edge[1]) || (top == edge[1] && a == edge[0])) 
                    continue;

                // If the neighbor has not been visited, add it to the queue and mark as visited
                if (visited[a] == false) {
                    q.push(a);
                    visited[a] = true;  // Mark the neighbor as visited
                }
            }
        }
    }

    // Function to find the redundant connection in the graph
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        vector<int> ans;  // This will store the redundant edge
        unordered_map<int, vector<int>> mp;  // Adjacency list to represent the graph
        
        // Build the graph by adding edges to the adjacency list
        for (auto edge : edges) {
            int from = edge[0];
            int to = edge[1];
            mp[from].push_back(to);  // Add edge in both directions for an undirected graph
            mp[to].push_back(from);
        }

        int n = mp.size();  // Number of nodes in the graph

        // Iterate over all edges to check if they form a cycle (redundant edge)
        for (auto edge : edges) {
            vector<bool> visited(n + 1, false);  // Initialize visited array for each edge

            // Perform BFS from node 1 and check if all nodes can be reached without the current edge
            bfs(1, mp, visited, edge);

            int i = 1;
            // Find the first unvisited node, indicating it is not reachable with the current edge
            while (i <= n) {
                if (visited[i] == false)  // If a node is unvisited, break the loop
                    break;
                i++;
            }

            // If all nodes are visited, it means this edge is redundant and part of a cycle
            if (i == n + 1) {
                ans = edge;  // Set the redundant edge
            }
        }

        return ans;  // Return the redundant edge
    }
};
