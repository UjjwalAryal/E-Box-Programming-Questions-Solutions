//Graph --- Adjacency matrix and Adjacency list representation

//Function for DFS and BFS 
//https://del.dog/epezivehay.pl


#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct node ** convmattolist(int **,int,char *);
void printlist(struct node **,int);
void printadjmatrix(int **,int);

struct node
{
	int nodeno;
	int edgeweight;
	struct node *link;
};


int main()
{
	int **A;
	int rows,edges,snode,enode,weight;
	int i;
	char directed[4];

	struct node **list;


	printf("Please enter the number of nodes in the graph\n");
	scanf("%d",&rows);

	printf("Please enter the number of edges in the graph\n");
	scanf("%d",&edges);

	printf("Is the graph directed\n");
	scanf("%s",directed);

	A = (int **)malloc(rows * sizeof(int *));
	for(i=0;i<rows;i++)
		*(A+i) = (int *) calloc(rows,sizeof(int));

	// Read the graph information and construct the adjacency matrix
	printf("Enter the start node, end node and weight of edge no %d\n",i);

	list = convmattolist(A,rows,directed);
	printadjmatrix(A,rows);
	printlist(list,rows);
        return 0;

}


struct node ** convmattolist(int **A,int rows,char *dir)
{
	//Fill in the code here
}

void printadjmatrix(int **A,int rows)
{
	printf("Adjacency Matrix Representation:\n");
	//Fill in the code here
}


void printlist(struct node **list,int rows)
{
	printf("Adjacency List Representation:\n");
	//Fill in the code here

}
