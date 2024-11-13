#include <stdio.h>
 #include <stdlib.h>
 #define MAX 100
 #define INF 999
 int parent[MAX];
 int find(int i) {
 while (parent[i] != i)
 i = parent[i];
 return i;
 }
 void union1(int i, int j) {
 int a = find(i);
 int b = find(j);
 parent[a] = b;
 }
 void kruskal(int n, int cost[MAX][MAX]) {
 int mincost = 0, edge_count = 0;
 for (int i = 0; i < n; i++)
 parent[i] = i;
 while (edge_count < n- 1) {
 int min = INF, a =-1, b =-1;
for (int i = 0; i < n; i++) {
 for (int j = 0; j < n; j++) {
 if (find(i) != find(j) && cost[i][j] < min) {
 min =cost[i][j];
 a =i;
 b =j;
 }
 }
 }
 union1(a, b);
 printf("Edge %d:(%d, %d) cost:%d\n", edge_count++, a, b,
 min);
 mincost += min;
 }
 printf("Minimum cost = %d\n", mincost);
 }
 int main() {
 int n;
 int cost[MAX][MAX];
 printf("Enter the number of vertices: ");
 scanf("%d", &n);
 printf("Enter the cost adjacency matrix:\n");
 for (int i = 0; i < n; i++)
 for (int j = 0; j < n; j++)
 scanf("%d", &cost[i][j]);
 kruskal(n, cost);
 return 0;
 }