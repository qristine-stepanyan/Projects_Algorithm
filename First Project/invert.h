#pragma once
#include "graph.h"

class InvertGraph
{
public:
    // _graph (the original graph) and inverted_graph (the graph to store the inverted result)
    void Invert_Graph(Graph& _graph, Graph& inverted_graph) {
        // Retrieve the number of vertices in the original graph _graph
        int numVertices = _graph.get_count_of_vertices();

        for (int i = 0; i < numVertices; ++i)
        {
            for (int j = 0; j < numVertices; ++j)
            {
                // Check if there is an edge from vertex i to vertex j in the original graph _graph
                if (_graph[i][j])
                {
                    // If there is an edge from vertex i to vertex j in the original graph _graph,
                    // add an edge from vertex j to vertex i in the inverted graph inverted_graph.
                    inverted_graph.addEdge(j, i);
                }
            }
        }
    }
};
