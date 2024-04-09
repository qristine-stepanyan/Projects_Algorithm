#pragma once
#include <iostream>
#include <unordered_set>
#include <queue>
#include <vector>
#include <stack>
#include <unordered_map>
#include <string>

class Graph
{
private:
    // Pointer to a matrix to represent the adjacency matrix
    bool** adjMatrix;

    // Number of vertices in the graph
    int numVertices; 

public:
    // Initialize the matrix to zero
    // Constructor to initialize the Graph object
    Graph(int numVertices)
    {
        // Assign the number of vertices
        this->numVertices = numVertices;

        // Allocate memory for rows of the adjacency matrix 
        adjMatrix = new bool* [numVertices];
        
        // Loop through rows
        for (int i = 0; i < numVertices; i++)
        { 
            adjMatrix[i] = new bool[numVertices];
            for (int j = 0; j < numVertices; j++)
            {   
                // Initialize all cells to false (no edges)
                adjMatrix[i][j] = false; 
            }
        }
    }

    // Add edges
    void addEdge(int i, int j)
    { 
        // Set the cell value to true to represent an edge between vertices i and j
        adjMatrix[i][j] = true; 
    }

    // Remove edges
    void removeEdge(int i, int j)
    {
        // Set the cell value to false to remove the edge between vertices i and j
        adjMatrix[i][j] = false; 
    }

    // Get the count of vertices
    int get_count_of_vertices()
    { 
        return numVertices; 
    }

    // Print the adjacency matrix
    void Print()
    { 
        std::cout << "    "; 
        for (int i = 0; i < numVertices; i++)
        {   
            // Print column indices
            std::cout << i << " "; 
        }
        std::cout << "\n\n";
        for (int i = 0; i < numVertices; i++)
        {   
            // Print row index
            std::cout << i << " : "; 
            for (int j = 0; j < numVertices; j++)
            { 
                // Print the value of the cell (true or false)
                std::cout << adjMatrix[i][j] << " "; 
            }
            std::cout << "\n"; 
        }
    }

    // Operator overloading for accessing elements of the adjacency matrix
    bool* operator[](int index)
    {   
        // Check if index is out of bounds
        if (index < 0 || index >= numVertices)
        { 
            std::cerr << "Index out of bounds" << std::endl; 
            exit(1); 
        }
        // Return the pointer to the row
        return adjMatrix[index]; 
    }

    // Destructor
    ~Graph()
    { 
        for (int i = 0; i < numVertices; i++)
        { 
            delete[] adjMatrix[i]; 
        }
        delete[] adjMatrix; 
    }
};
