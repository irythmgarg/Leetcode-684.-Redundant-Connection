// Author -Ridham Garg
class Solution {
public:
    vector<int> parent, rank;

    // Find the representative of the set that contains 'x' using path compression
    int find(int x) {
        if (parent[x] != x) 
            parent[x] = find(parent[x]);  // Recursively find the parent and apply path compression
        return parent[x];
    }

    // Union of two sets, 'x' and 'y', using union by rank
    void unite(int x, int y) {
        int px = find(x);  // Find the parent of 'x'
        int py = find(y);  // Find the parent of 'y'
        
        if (px == py) 
            return;  // If both elements have the same parent, they are already in the same set
        
        // Union by rank: Attach the tree with the smaller rank under the tree with the larger rank
        if (rank[px] > rank[py])
            parent[py] = px;  // Attach 'y' under 'x'
        else if (rank[px] < rank[py])
            parent[px] = py;  // Attach 'x' under 'y'
        else {
            parent[py] = px;  // If both have the same rank, attach 'y' under 'x'
            rank[px]++;  // Increase the rank of the root of the new tree
        }
    }

    // Function to find the redundant connection (i.e., the first edge that forms a cycle)
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        vector<int> ans;  // This will store the redundant edge
        
        // Initialize 'parent' and 'rank' for Union-Find structure
        int n = edges.size() + 1;  // Number of nodes is one more than the number of edges
        parent.resize(n);
        rank.resize(n);

        // Initially, each node is its own parent (disjoint sets) and has rank 0
        for (int i = 0; i < n; i++) {
            parent[i] = i;  // Each node is its own parent initially
            rank[i] = 0;  // Initial rank is 0
        }

        // Iterate through all edges to find the redundant one
        for (auto edge : edges) {
            int from = edge[0];
            int to = edge[1];

            // If both nodes belong to the same set, the edge is redundant (forms a cycle)
            if (parent[find(from)] == parent[find(to)]) {
                ans = edge;  // Store the redundant edge
                break;  // No need to check further, as we've found the redundant edge
            } else {
                unite(from, to);  // Union the sets containing 'from' and 'to'
            }
        }

        return ans;  // Return the redundant edge
    }
};
