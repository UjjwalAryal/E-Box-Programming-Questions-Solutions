#include<stdio.h>
#include<stdlib.h>

/* Define Infinite as a large enough value. This value will be used
  for vertices not connected to each other */
#define INF 99999

// A function to print the solution matrix
void printSolution(int **dist, int V);

int min(int x, int y){
    return x < y ? x : y;
}

// Solves the all-pairs shortest path problem using Floyd Warshall algorithm
void floydWarshell (int **graph, int V){
    int i, j, k;
    int **dist = (int **)malloc(V * sizeof(int*));
    for(i = 0; i < V; i++)
        dist[i] = (int *)malloc(V * sizeof(int));
        
    for(i = 0; i < V; i++){
        for(j = 0; j < V; j++){
            dist[i][j] = (graph[i][j] || i==j) ? graph[i][j] : INF; 
        }
    }    
    
    for(i = 0; i < V; i++){
        for(j = 0; j < V; j++){
            for(k = 0; k < V; k++){
                dist[j][k] = min(dist[j][k], dist[j][i] + dist[i][k]); 
            }
        }
    }
    

    printSolution(dist,V);
}

/* A utility function to print solution */
void printSolution(int **dist, int V)
{
	int i,j;
    printf ("Following matrix shows the shortest distances"
            " between every pair of vertices \n");
    for (i = 0; i < V; i++)
    {
        for (j = 0; j < V; j++)
        {
            if (dist[i][j] == INF)
                printf("%7s", "INF");
            else
                printf ("%7d", dist[i][j]);
        }
        printf("\n");
    }
}

// driver program to test above function
int main()
{
	int **graph;
	int i,j,V,edges,snode,enode,weight;
	
	printf("Enter the number of nodes in the graph\n");
	scanf("%d",&V);

	printf("Enter the number of edges in the graph\n");
	scanf("%d",&edges);
	graph = (int **)malloc(V * sizeof(int *));
	for(i=0;i<V;i++)
		*(graph+i) = (int *) calloc(V,sizeof(int));
	
	for(i = 0;i<V;i++){
		for(j = 0;j<V;j++){
			*(*(graph+i)+j) = (i==j)?0:INF;
		}
	}
	for(i = 0;i<edges;i++)
	{
		printf("Enter the start node, end node and weight of edge no %d\n",i);
		scanf("%d%d%d",&snode,&enode,&weight);
		*(*(graph+snode)+enode) = weight;
	}

    floydWarshell(graph,V);
    return 0;
}
