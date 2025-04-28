# Leetcode-684.-Redundant-Connection

# Redundant Connection Problem - Solutions Overview

## Author: Ridham Garg

This repository contains three different approaches to solving the problem of finding a redundant connection in an undirected graph. The redundant connection refers to the first edge in the graph that, if removed, would make the graph a tree (i.e., a connected graph without cycles). The problem is usually represented as a series of edges, where each edge connects two nodes.

### 1. **DFS Approach**
The Depth-First Search (DFS) approach solves the problem by exploring the graph for cycles. The key idea is to perform a DFS traversal, and for each edge, check whether the edge forms a cycle by revisiting a node that has already been visited. If a cycle is detected, the edge that caused the cycle is identified as the redundant connection.

- **Key Components:**
  - DFS traversal to explore all nodes.
  - Detecting cycles during traversal by tracking visited nodes.
  - Storing the redundant edge that forms the cycle.

- **Time Complexity**: O(E + V) where E is the number of edges and V is the number of vertices.
- **Space Complexity**: O(V) for storing the visited nodes.

### 2. **BFS Approach**
The Breadth-First Search (BFS) approach follows a similar logic to DFS but uses a queue to explore the graph level by level. The BFS algorithm is used to check whether an edge forms a cycle. The graph is traversed, and during each traversal, if an edge leads to an already visited node (except for the current edge), a cycle is detected, and the edge is marked as redundant.

- **Key Components:**
  - BFS traversal using a queue to explore nodes.
  - Cycle detection through revisiting nodes during traversal.
  - Storing the first redundant edge that forms a cycle.

- **Time Complexity**: O(E + V), where E is the number of edges and V is the number of vertices.
- **Space Complexity**: O(V) for storing visited nodes and queue.

### 3. **Union-Find (Disjoint Set Union) Approach**
The Union-Find approach uses a data structure called Union-Find (also known as Disjoint Set Union) to efficiently manage and track connected components of the graph. The core idea is to perform a union operation to merge two sets, and if two nodes are already connected (i.e., they belong to the same set), adding the edge would form a cycle. The first such edge is identified as the redundant connection.

- **Key Components:**
  - **Find** operation to determine the root or representative of a set.
  - **Union** operation to merge two sets.
  - Using path compression and union by rank to optimize the find and union operations.

- **Time Complexity**: O(α(V)) per operation, where α is the inverse Ackermann function, which grows very slowly, so the complexity is near constant time.
- **Space Complexity**: O(V) for storing parent and rank arrays.

## Conclusion
These three approaches—DFS, BFS, and Union-Find—provide different methods to solve the redundant connection problem. The DFS and BFS approaches are easier to implement and understand, while the Union-Find approach is highly optimized for this problem, especially when handling large graphs.

Each approach offers a unique perspective on how to traverse and manipulate the graph, with the Union-Find approach being the most efficient in terms of time complexity due to its near constant-time operations for union and find.
