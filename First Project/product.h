#pragma once
#include "graph.h"
class ProductionStages
{
private:
    // Number of production stages
    int N;   
    // Vector to store the names of production stages
    std::vector<std::string> names;   

public:
    std::unordered_map<std::string, int> name_to_index;   
    std::vector<std::string> index_to_name;   
public:

    // Constructor to initialize Production_stages object with the given number of stages and their names
    ProductionStages(int _N, const std::vector<std::string> _names) : N(_N), names(_names)
    {
        // Resize index_to_name vector to hold N elements
        index_to_name.resize(N);
        
        // Populate name_to_index and index_to_name mappings
        for (int i = 0; i < N; ++i)
        {
            // Map name to index
            name_to_index[names[i]] = i;  
            // Store name at corresponding index 
            index_to_name[i] = names[i];   
        }

    }
};
