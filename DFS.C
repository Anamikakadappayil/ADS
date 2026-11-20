 1  #include <stdio.h>
 2  int graph[10][10], visited[10], n;
 3  void DFS(int v) {
 4  visited[v] = 1;
 5  printf("%d ", v);
 6   for (int i = 1; i <= n; i++) {
 7  if (graph[v][i] == 1 && !visited[i]) {
 8  DFS(i);
 9  }
10   }
11  }
12  int main() {
13   int i, j, start;
14   printf("Enter number of vertices: ");
15   scanf("%d", &n);
16   printf("Enter adjacency matrix:\n");
17   for (i = 1; i <= n; i++) {
18   for (j = 1; j <= n; j++) {
19   scanf("%d", &graph[i][j]);
20   }
12   }
22   for (i = 1; i <= n; i++)
23   visited[i] = 0;
24   printf("Enter starting vertex: ");
25   scanf("%d", &start);
26   printf("DFS Traversal: ");
27   DFS(start);
28  return 0;
29  }

OUTPUT

Enter number of vertices: 3
Enter adjacency matrix:
0 1 1
1 0 1
1 0 0
Enter starting vertex: 1
DFS Traversal: 1 2 3 