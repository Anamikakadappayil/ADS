1  #include <stdio.h>
2  #define INF 9999
3  int main() {
4   int n;
5   printf("Enter number of nodes: ");
6   scanf("%d", &n);
7   int cost[10][10], visited[10] = {0};
8   printf("Enter the adjacency matrix:\n");
9   for (int i = 0; i < n; i++)
10   for (int j = 0; j < n; j++)
11   scanf("%d", &cost[i][j]);
12   visited[0] = 1;
13   int edges = 0;
14   printf("Edges in MST:\n");
15   while (edges < n - 1) {
16   int min = INF, a = -1, b = -1;
17   for (int i = 0; i < n; i++) {
18   if (visited[i]) {
19   for (int j = 0; j < n; j++) {
20   if (!visited[j] && cost[i][j] != 0 && cost[i][j] < min) {
21   min = cost[i][j];
22   a = i;
23   b = j;
24   }
25   }
26   }
27   }
28   printf("%d -- %d (weight = %d)\n", a, b, min);
29   visited[b] = 1;
30   edges++;
31   }
32   return 0;
33  }

OUTPUT

Enter number of nodes: 3
Enter the adjacency matrix:
0 2 4
5 6 0
9 0 1
Edges in MST:
0 -- 1 (weight = 2)
0 -- 2 (weight = 4)
