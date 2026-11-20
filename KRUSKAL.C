  1 #include <stdio.h>
  2 int main() {
  3  int n;
  4  printf("Enter number of vertices: ");
  5  scanf("%d", &n);
  6  int cost[10][10], parent[10];
  7  int a, b, u, v, min, edges = 0, total = 0;
  8  printf("Enter cost adjacency matrix (0 = no edge):\n");
  9  for (int i = 0; i < n; i++)
 10   for (int j = 0; j < n; j++)
 11      scanf("%d", &cost[i][j]);
 12   for (int i = 0; i < n; i++)
 13   parent[i] = i;
 14   printf("\nEdges selected:\n");
 15   while (edges < n - 1) {
 16   min = 9999;
 17   for (int i = 0; i < n; i++)
 18   for (int j = 0; j < n; j++)
 19   if (cost[i][j] != 0 && cost[i][j] < min) {
 20   min = cost[i][j];
 21   a = i;
 22   b = j;
 23  }
 24  u = a;
 25  while (parent[u] != u) u = parent[u];
 26  v = b;
 27  while (parent[v] != v) v = parent[v];
 28  if (u != v) {
 29  printf("%d => %d (cost = %d)\n", a, b, min);
 30  parent[u] = v;
 31  total += min;
 32  edges++;
 33  }
 34  cost[a][b] = cost[b][a] = 9999;
 35  }
 36  printf("\nTotal minimum cost = %d\n", total);
 37  return 0;
 38 }

OUTPUT
Enter number of vertices: 3
Enter cost adjacency matrix (0 = no edge):
2 4 5 
3 6 0
9 0 2

Edges selected:
1 => 0 (cost = 3)
0 => 2 (cost = 5)

Total minimum cost = 8
