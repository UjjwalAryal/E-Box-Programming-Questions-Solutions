#include <stdio.h>
#include <limits.h>
#include <stdlib.h> 
 
// A utility function to find the vertex with minimum key value, from
// the set of vertices not yet included in MST
int minKey(int key[], int mstSet[], int V)
{
   // Initialize min value
   int min = INT_MAX, min_index;
	int v;
   for (v = 0; v < V; v++)
     if (mstSet[v] == 0 && key[v] < min && key[v])
         min = key[v], min_index = v;
 
   return min_index;
}

int allVisited(int n, int *visited){
    int i, res = 1;
    for(i = 0; i < n; i++)
        res &= visited[i];
    return res;
}

// A utility function to print the constructed MST stored in parent[]
void printMST(int parent[], int V, int **graph)
{
	int i;
   for (i = 1; i < V; i++)
      printf("%d - %d  %d\n", parent[i], i, graph[i][parent[i]]);
}

int min(int x, int y){
    return x < y ? x : y;
}
 
// Function to construct and print MST for a graph represented using adjacency
// matrix representation
void primMST(int **graph, int V){

    int i, src = 0;
    int *parent = (int*)malloc(V * sizeof(int));
    int *visited = (int*)calloc(V, sizeof(int));
    int *dist = (int*)malloc(V * sizeof(int));
    
    for(i = 0; i < V; i++)
        dist[i] = 9999;
    
    dist[src] = 0;
    
    while(!allVisited(V, visited)){
        visited[src] = 1;

        for(i = 0; i < V; i++){
            if(dist[i] > graph[src][i] && !visited[i] && graph[src][i]){
                dist[i] = graph[src][i];
                parent[i] = src;
            }
        }
        src = minKey(dist, visited, V);
    }    
 
     // print the constructed MST
     printMST(parent, V, graph);
}
 
 
// driver program to test above function
int main()
{
	int V,i,j;
	printf("Enter the number of vertices in the graph\n");
	scanf("%d",&V);
	int **graph;
	graph = (int **) malloc(sizeof(int*)*V);
	for(i=0;i<V;i++){
		*(graph+i) = (int *)malloc(sizeof(int)*V);
	}
	printf("Enter the distance matrix of the graph\n");
	for(i=0;i<V;i++){
		for(j=0;j<V;j++){
			scanf("%d",&graph[i][j]);
		}
	}
    // Print the solution
    printf("\nThe edges are picked in the following order\n");
    primMST(graph,V);
 
    return 0;
}
