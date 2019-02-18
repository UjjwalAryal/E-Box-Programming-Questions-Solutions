#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
// a structure to represent a weighted edge in graph
struct Edge{
    int src, dest, weight;
};
 
// a structure to represent a connected, undirected and weighted graph
struct Graph
{
    // V-> Number of vertices, E-> Number of edges
    int V, E;
    
    // graph is represented as an array of edges. Since the graph is
    // undirected, the edge from src to dest is also edge from dest
    // to src. Both are counted as 1 edge here.
    struct Edge* edge;
};
 
// Creates a graph with V vertices and E edges
struct Graph* createGraph(int V, int E)
{
    struct Graph* graph = (struct Graph*) malloc( sizeof(struct Graph) );
    graph->V = V;
    graph->E = E;
 
    graph->edge = (struct Edge*) malloc( graph->E * sizeof( struct Edge ) );
 
    return graph;
}
 
// A structure to represent a subset for union-find
struct subset
{
    int parent;
    int rank;
};
 
// A utility function to find set of an element i
// (uses path compression technique)
int find(struct subset subsets[], int i)
{
    // find root and make root as parent of i (path compression)
    if (subsets[i].parent != i)
        subsets[i].parent = find(subsets, subsets[i].parent);
 
    return subsets[i].parent;
}
 
// A function that does union of two sets of x and y
// (uses union by rank)
void Union(struct subset subsets[], int x, int y)
{
    int xroot = find(subsets, x);
    int yroot = find(subsets, y);
 
    // Attach smaller rank tree under root of high rank tree
    // (Union by Rank)
    if (subsets[xroot].rank < subsets[yroot].rank)
        subsets[xroot].parent = yroot;
    else if (subsets[xroot].rank > subsets[yroot].rank)
        subsets[yroot].parent = xroot;
 
    // If ranks are same, then make one as root and increment
    // its rank by one
    else
    {
        subsets[yroot].parent = xroot;
        subsets[xroot].rank++;
    }
}
 
// Compare two edges according to their weights.
// Used in qsort() for sorting an array of edges
int myComp(const void* a, const void* b)
{
    struct Edge* a1 = (struct Edge*)a;
    struct Edge* b1 = (struct Edge*)b;
    return a1->weight > b1->weight;
}
 
// The main function to construct MST using Kruskal's algorithm
void KruskalMST(struct Graph* graph)
{
    qsort(graph->edge, graph->E, sizeof(graph->edge[0]), myComp);
    int i;
    // for(i=0;i<graph->E; i++)
    //     printf("%d %d %d\n", graph->edge[i].src, graph->edge[i].dest, graph->edge[i].weight);
    
    struct subset subsets[graph->V];
    
    for(i=0;i<graph->V;i++)
        subsets[i].parent = i, subsets[i].rank = 1;
    printf("Following are the edges in the constructed MST\n");
    for( i = 0; i < graph->E; i++){
        if(find(subsets, graph->edge[i].src) != find(subsets, graph->edge[i].dest)){
            Union(subsets, graph->edge[i].src, graph->edge[i].dest);
            printf("Edge %d and Edge %d with distance %d\n",graph->edge[i].src, graph->edge[i].dest, graph->edge[i].weight);
        }
        
    }
    
    
    
    // // print the contents of result[] to display the built MST
    // 
    // for (i = 0; i < e; ++i)
    //     printf("Edge %d and Edge %d with distance %d\n", result[i].src, result[i].dest, result[i].weight);
    // return;
}
 
// Driver program to test above functions
int main()
{
    int V;
    int E;
    int i;
    printf("Enter the number of vertices\n");
	scanf("%d",&V);
	printf("Enter the number of edges\n");
	scanf("%d",&E);
    struct Graph* graph = createGraph(V, E);
 
	for(i=0;i<E;i++){
		printf("Enter source, destination and weight of edge %d\n",i+1);
		scanf("%d",&(graph->edge[i].src));
		scanf("%d",&(graph->edge[i].dest));
		scanf("%d",&(graph->edge[i].weight));
	}
	
    KruskalMST(graph);
    return 0;
}
