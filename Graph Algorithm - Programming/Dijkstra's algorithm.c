#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

// A utility function to find the vertex with minimum distance value, from
// the set of vertices not yet included in shortest path tree
int minDistance(int dist[], int sptSet[], int V)
{
   // Initialize min value
   int min = INT_MAX, min_index, v;
 
   for (v = 0; v < V; v++)
     if (sptSet[v] == 0 && dist[v] <= min)
         min = dist[v], min_index = v;
 
   return min_index;
}
 
// A utility function to print the constructed distance array
void printSolution(int *dist, int V)
{
	int i;
   printf("Vertex   Distance from Source\n");
   for (i = 0; i < V; i++)
      printf("%d          %d\n", i, dist[i]);
}
 
 int min(int x, int y){
     return x<y ? x : y;
 }
// Funtion that implements Dijkstra's single source shortest path algorithm
// for a graph represented using adjacency matrix representation
int allVisited(int n, int *visited){
    int i, res = 1;
    for(i = 0; i < n; i++)
        res &= visited[i];
    return res;
}


void dijkstra(int **graph, int src, int V){

    int *dist = (int*)malloc(V * sizeof(int));
    int *visited = (int*)malloc(V * sizeof(int));
    // memset(dist, INT_MAX, V * sizeof(int));
    // memset(visited, 0, V * sizeof(int));
    int i;
    
    for(i=0;i<V;i++)  dist[i] = 99999, visited[i] = 0;
    
    dist[src] = 0;

    // for(i=0;i<V;i++){
    //     for(v=0;v<V;v++)
    //         printf("%d ",graph[i][v]);
    //     printf("\n");
    // }

    while(!allVisited(V, visited)){
        visited[src] = 1;
        for(i = 0; i < V; i++){
            if(!visited[i] && graph[src][i]){
                dist[i] = min(dist[i], graph[src][i] + dist[src]);
                // printf("%d, %d + %d\n",dist[i],graph[src][i], dist[src]);
            }
        }
        src = minDistance(dist, visited, V);
    }


     // print the constructed distance array
     printSolution(dist, V);
}
 
// driver program to test above function
int main()
{
	int **graph;
	int V,src,i,edges,snode,enode,weight;
	printf("Enter the number of nodes in the graph\n");
	scanf("%d",&V);

	printf("Enter the number of edges in the graph\n");
	scanf("%d",&edges);
	graph = (int **)malloc(V * sizeof(int *));
	for(i=0;i<V;i++)
		*(graph+i) = (int *) calloc(V,sizeof(int));
	
	for(i = 0;i<edges;i++)
	{
		printf("Enter the start node, end node and weight of edge no %d\n",i);
		scanf("%d%d%d",&snode,&enode,&weight);
		*(*(graph+snode)+enode) = weight;
		*(*(graph+enode)+snode) = weight;
	}
	printf("Enter the source matrix:\n");
	scanf("%d",&src);
        dijkstra(graph, src, V);
        return 0;
}
