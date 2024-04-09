#pragma once
#include "graph.h"
#include "invert.h"

class StronglyConnectedComponents
{
private:
    // Reference to the original graph
    Graph& graph; 
    
    // Number of vertices in the graph
    int num_of_vertices; 
    
    // Vector to keep track of visited vertices during DFS
    std::vector<bool> visited; 

    // Stack to store vertices in order of their finishing times during DFS
    std::stack<int> my_stack; 

    // Recursive function to perform the first depth-first search
    void FirstDFS(int vertex)
    {
        // Mark the current vertex as visited
        visited[vertex] = true; 
        // Traverse all adjacent vertices of the current vertex
        for (int i = 0; i < num_of_vertices; ++i)
        {
            // If there is an edge from the current vertex to vertex i and vertex i is not visited, recursively call FirstDFS
            if (graph[vertex][i] && !visited[i])
            {
                FirstDFS(i);
            }
        }
        // Push the current vertex onto the stack after all its adjacent vertices have been visited
        my_stack.push(vertex); 
    }

    // Recursive function to perform the second depth-first search to find components
    void SecondDFS(int vertex, std::vector<int>& component)
     {
        visited[vertex] = true;
        // Add the current vertex to the current component
        component.push_back(vertex);
        for (int i = 0; i < num_of_vertices; ++i)
        {
            // If there is an edge from vertex i to the current vertex and vertex i is not visited, recursively call SecondDFS
            if (graph[i][vertex] && !visited[i])
            {
                SecondDFS(i, component);
            }
        }
    }

    // Function to reset the visited vector
    void cleanVisited()
    {
        for (int i = 0; i < num_of_vertices; ++i)
        {
            // Mark all vertices as not visited
            visited[i] = false; 
        }
    }

public:
    // Constructor to initialize the StronglyConnectedComponents object with the number of vertices and the reference to the original graph
    StronglyConnectedComponents(int _vertices, Graph& _graph) : num_of_vertices(_vertices), graph(_graph)
    {
        // Resize and initialize the visited vector with 'false' for each vertex
        visited.resize(num_of_vertices, false); 
    }

    // Function to find strongly connected components in the graph
    std::vector<std::vector<int>> findSCC()
    {
        // Vector to store the strongly connected components
        std::vector<std::vector<int>> components; 
        // Reset the visited vector
        cleanVisited();

        // First pass of depth-first search to fill the stack with vertices in order of their finishing times
        for (int i = 0; i < num_of_vertices; ++i)
        {
            // If the current vertex is not visited, perform DFS on it
            if (!visited[i])
            { 
                FirstDFS(i);
            }
        }

        InvertGraph graphInverter; 
        Graph inverted_graph(num_of_vertices); 
        // Invert the original graph to obtain the inverted graph
        graphInverter.Invert_Graph(graph, inverted_graph);
        // Reset the visited vector
        cleanVisited(); 

        // Second pass of depth-first search to find the strongly connected components
        while (!my_stack.empty())
        {
            // Get the top vertex from the stack
            int vertex = my_stack.top(); 
            // Pop the vertex from the stack
            my_stack.pop(); 

            if (!visited[vertex])
            { 
                // If the vertex is not visited, it represents a new strongly connected component

                // Vector to store the current strongly connected component
                std::vector<int> component; 
                // Perform DFS on the current vertex to find the component
                SecondDFS(vertex, component); 
                // Add the component to the list of components
                components.push_back(component); 
            }
        }
        // Return the vector of strongly connected components
        return components; 
    }
};
