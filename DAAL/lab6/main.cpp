#include <iostream>
#include <climits>
using namespace std;

#define INF INT_MAX
#define N 4  // Define the size of the graph

void printMatrix(int matrix[N][N]) {
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            if (matrix[i][j] == INF)
                cout << "INF ";
            else
                cout << matrix[i][j] << "   ";
        }
        cout << endl;
    }
    cout << endl;
}

void floydWarshall(int graph[N][N]) {
    int dist[N][N];

    // Initialize distance matrix with input graph matrix
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            dist[i][j] = graph[i][j];
        }
    }

    // Floyd-Warshall algorithm
    for (int k = 0; k < N; ++k) {
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                if (dist[i][k] != INF && dist[k][j] != INF) {
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }
        cout << "Matrix after considering vertex " << k + 1 << " as intermediate:\n";
        printMatrix(dist);
    }

    cout << "Final shortest distance matrix:\n";
    printMatrix(dist);
}

int main() {
    int graph[N][N] = {
        {0, 3, INF, 7},
        {8, 0, 2, INF},
        {5, INF, 0, 1},
        {2, INF, INF, 0}
    };
    
    floydWarshall(graph);
    return 0;
}
