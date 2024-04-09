#pragma once
#include "graph.h"

class LinearProcess
{
public:
    // Function to determine whether the given graph is linear (a path graph) starting from the specified startNode
    std::unordered_set<int> isLinear(Graph& graph, int startNode)
    {
        // Get the number of vertices in the graph
        int numVertices = graph.get_count_of_vertices();
        
        // Create an unordered set to keep track of visited nodes and a queue for BFS traversal
        std::unordered_set<int> visited;
        std::queue<int> queue;
        
        // Push the startNode onto the queue and mark it as visited
        queue.push(startNode);
        visited.insert(startNode);
        
        // Perform BFS traversal until the queue is empty
        while (!queue.empty())
        {
            // Retrieve the front element of the queue (the current node) and remove it from the queue
            int node = queue.front();
            queue.pop();
            
            // Iterate through all neighbors of the current node
            for (int neighbor = 0; neighbor < numVertices; ++neighbor)
            {
                // Check if there is an edge between the current node and the neighbor, and if the neighbor has not been visited yet
                if (graph[node][neighbor] && visited.find(neighbor) == visited.end())
                {
                    // Push the neighbor onto the queue and mark it as visited
                    queue.push(neighbor);
                    visited.insert(neighbor);
                }
            }
        }
        
        // Return the set of visited nodes,representing the connected component in the graph reachable from the startNode
        return visited;
    }
};



