#include <iostream>
#include <queue>
#include <limits>

using namespace std;

const int INF = numeric_limits<int>::max();
const int MAX_NODES = 6;  // Adjust according to your graph's size

struct Node {
    int vertex, weight;
    Node(int v, int w) : vertex(v), weight(w) {}
};

struct Compare {
    bool operator()(Node const& a, Node const& b) {
        return a.weight > b.weight;
    }
};

void dijkstra(int start, Node* graph[MAX_NODES][MAX_NODES], int n) {
    int dist[MAX_NODES];
    bool visited[MAX_NODES] = {false};

    // Initialize distances as infinity
    for (int i = 0; i < n; i++) {
        dist[i] = INF;
    }
    dist[start] = 0;

    priority_queue<Node, deque<Node>, Compare> pq;
    pq.push(Node(start, 0));

    while (!pq.empty()) {
        int u = pq.top().vertex;
        int currDist = pq.top().weight;
        pq.pop();

        // Skip nodes that are already visited
        if (visited[u]) continue;
        visited[u] = true;

        // Update distances to adjacent nodes
        for (int v = 0; v < n; v++) {
            if (graph[u][v] != NULL) {  // Use NULL instead of nullptr
                int weight = graph[u][v]->weight;
                if (dist[u] + weight < dist[v]) {
                    dist[v] = dist[u] + weight;
                    pq.push(Node(v, dist[v]));
                }
            }
        }
    }

    // Print minimum distances from the starting node
    cout << "Minimum distances from node " << char(start + 'A') << ":\n";
    for (int i = 0; i < n; ++i) {
        cout << char(i + 'A') << ": ";
        if (dist[i] == INF) {
            cout << "Unreachable\n";
        } else {
            cout << dist[i] << "\n";
        }
    }
}

int main() {
    int n = MAX_NODES;

    // Initialize the adjacency matrix
    Node* graph[MAX_NODES][MAX_NODES] = {NULL};  // Use NULL instead of nullptr

    // Add edges with weights (using dynamic allocation for simplicity)
    graph[0][1] = new Node(1, 4);  // A -> B (4)
    graph[0][2] = new Node(2, 5);  // A -> C (5)
    graph[1][2] = new Node(2, 11); // B -> C (11)
    graph[1][3] = new Node(3, 9);  // B -> D (9)
    graph[1][4] = new Node(4, 7);  // B -> E (7)
    graph[2][4] = new Node(4, 3);  // C -> E (3)
    graph[3][4] = new Node(4, 13); // D -> E (13)
    graph[3][5] = new Node(5, 2);  // D -> F (2)
    graph[4][5] = new Node(5, 6);  // E -> F (6)

    dijkstra(0, graph, n);

    // Clean up dynamically allocated memory
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            delete graph[i][j];
        }
    }

    return 0;
}

