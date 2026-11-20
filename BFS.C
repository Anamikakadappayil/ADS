 1 #include <stdio.h>
 2 int main() {
 3 int n, graph[10][10], visited[10] = {0};
 4 int queue[10], front = 0, rear = -1;
 5 printf("Enter number of nodes: ");
 6 scanf("%d", &n);
 7 printf("Enter adjacency matrix:\n");
 8 for (int i = 0; i < n; i++)
 9 for (int j = 0; j < n; j++)
10 scanf("%d", &graph[i][j]);
11 int start;
12 printf("Enter starting node: ");
13 scanf("%d", &start);
14 visited[start] = 1;
15 queue[++rear] = start;
16 printf("BFS order: ");
17 while (front <= rear) {
18 int node = queue[front++];
19 printf("%d ", node);
20 for (int i = 0; i < n; i++) {
21 if (graph[node][i] == 1 && visited[i] == 0) {
22 visited[i] = 1;
23 queue[++rear] = i;
24 }
15 }
26 }
27 return 0;
28}

OUTPUT

Enter number of nodes: 2
Enter adjacency matrix:
0 1
1 0
Enter starting node: 0
BFS order: 0 1 