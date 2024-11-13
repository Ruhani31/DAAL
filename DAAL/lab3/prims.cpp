#include <iostream>
#include <vector>
#include <climits>

class Graph
{
public:
    Graph(int V) : V(V)
    {
        // Initialize adjacency matrix with INT_MAX (representing no edge)
        adj = std::vector<std::vector<int> >(V, std::vector<int>(V, INT_MAX));
    }

    // Add edge with weight
    void addEdge(int v, int w, int weight)
    {
        adj[v][w] = weight;
        adj[w][v] = weight;  // If the graph is undirected
    }

    void printGraph()
    {
        for (int v = 0; v < V; ++v)
        {
            std::cout << "\nAdjacency list of vertex " << v << "\n head ";
            for (int u = 0; u < V; ++u)
            {
                if (adj[v][u] != INT_MAX)
                    std::cout << " -> " << u << "(weight: " << adj[v][u] << ")";
            }
            std::cout << std::endl;
        }
    }

    void prims_traversal()
    {
        std::vector<bool> visited(V, false);
        std::vector<int> parent(V, -1);
        std::vector<int> key(V, INT_MAX);

        key[0] = 0;

        for (int i = 0; i < V - 1; i++)
        {
            int u = minKey(key, visited);
            visited[u] = true;

            for (int v = 0; v < V; v++)
            {
                if (adj[u][v] != INT_MAX && !visited[v] && adj[u][v] < key[v])
                {
                    parent[v] = u;
                    key[v] = adj[u][v];
                }
            }
        }

        // Print the Minimum Spanning Tree
        std::cout << "Edge \tWeight\n";
        for (int i = 1; i < V; i++)
            std::cout << parent[i] << " - " << i << " \t" << adj[i][parent[i]] << " \n";
    }

    int minKey(const std::vector<int>& key, const std::vector<bool>& visited)
    {
        int min = INT_MAX, min_index;

        for (int v = 0; v < V; v++)
        {
            if (!visited[v] && key[v] < min)
            {
                min = key[v];
                min_index = v;
            }
        }

        return min_index;
    }

private:
    int V;
    std::vector<std::vector<int> > adj;
};

int main()
{
    Graph g(4);
    g.addEdge(0, 1, 10);
    g.addEdge(0, 2, 6);
    g.addEdge(0, 3, 5);
    g.addEdge(1, 3, 15);
    g.addEdge(2, 3, 4);

    g.printGraph();
    g.prims_traversal();

    return 0;
}
