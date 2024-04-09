#include "product.h"   
#include "graph.h"     
#include "invert.h"     
#include "kosaraju.h"   
#include "linear.h"     

int main()
{
    // Variables to store the number of stages and edges
    int N, M; 

    // Input the number of production stages
    std::cin >> N;   
    
    // Vector to store the names of production stages
    std::vector<std::string> vec;   
    
    // Temporary string to store each stage's name
    std::string a;   
    for (int i = 0; i < N; ++i)
    {
        std::cin >> a;  
        // Store the stage name in the vector
        vec.push_back(a);   
    }

    ProductionStages our_production(N, vec);   
    // Input the number of directed edges in the graph
    std::cin >> M;   
    // Variables to store the start and end vertices of each edge
    int from, to;   
    // Create a graph with N vertices
    Graph g(N);   
    for (int i = 0; i < M; ++i)
    {
        // Input the start and end vertices of each edge
        std::cin >> from >> to;   
        // Add the edge to the graph
        g.addEdge(from, to);   
    }

    std::cout << std::endl;  

    StronglyConnectedComponents scc(N, g);  

    // Find strongly connected components in the graph
    std::vector<std::vector<int>> components = scc.findSCC();
    
    // Vector to store irreversible stages
    std::vector<int> my_vec;   

    // Find irreversible stages
    for (std::vector<int> el : components)
    {   
        // Counter for checking if a stage has incoming edges
        int count = 0;   
        for (int i = el[0] - 1; i > 0; --i)
        {
            if (g[el[0]][i])
            {
                // Increment count if an incoming edge is found
                count++;   
            }
        }
        if (count == 0)
        {
            // If no incoming edges are found, add the stage to the list of irreversible stages
            my_vec.push_back(el[0]);   
        }
    }

    // Output the number of irreversible stages
    std::cout << "The number of <irreversible> stages is " << my_vec.size() << ". Those are" << std::endl;
    // Sort the list of irreversible stages
    std::sort(my_vec.begin(), my_vec.end());   

    // Output the irreversible stages along with their names
    for (int element : my_vec)
    {
        std::cout << element << "-" << our_production.index_to_name[element] << std::endl;
    }

    // Output the stages from which we can go back to irreversible stages
    for (int i = 0; i < my_vec.size(); ++i)
    {
        std::cout << "We can go back to " << my_vec[i] << " from  ";
        for (int j = 0; j < N; ++j)
        {
            if (g[j][my_vec[i]])
            {
                std::cout << j << "-" << our_production.index_to_name[j] << " ";
            }
        }
        std::cout << "." << std::endl;
    }

    std::cout << std::endl;   

    LinearProcess LinearProcessChecker;   

    // Call the isLinear function from the LinearProcess class
    std::unordered_set<int> isLinearSet = LinearProcessChecker.isLinear(g, 0);

    // Output the result
    if (isLinearSet.size() == N)
    {
        std::cout << std::endl << "Yes. The process represented by the graph is linear." << std::endl;
        std::cout << "The process is linear because the production passes through all stages and passes ";
        for (int element : isLinearSet)
        {
            for (int el_of_vec : my_vec)
            {
                if (element == el_of_vec)
                {
                    std::cout << element << " ";
                }
            }
        }
    }
    else
    {
        std::cout << std::endl << "No. The process represented by the graph is not linear." << std::endl;
    }
return 0;
}