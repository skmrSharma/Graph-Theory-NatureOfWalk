#include<stdio.h>
#include<stdlib.h>
#define FALSE 0
#define TRUE 1
short int visited[10];
char nodes[10]={'A','B','C','D','E','F','G','H','I','J'};
int** make2DArray(int rows,int cols)
{
	int **g;
	g=(int **)malloc(rows*sizeof(int*));
	for(int i=0;i<rows;i++)
		g[i]=(int*)malloc(cols*sizeof(int));
	return g;
}
void dfs(int **g,int i,int n)
{
	visited[i]=TRUE;
	printf("%c\n",nodes[i]);	// to print all nodes in dfs order
	for(int j=0;j<n;j++)
		if(g[i][j]==1 && visited[j]==FALSE)
			dfs(g,j,n);
}
void DFS(int **g,int n)
{
	int comp=0;
	for(int i=0;i<n;i++)
		visited[i]=FALSE;
	for(int i=0;i<n;i++)
		if(visited[i]==FALSE)
		{
			comp++;		// to count the number of partitions of the graph
			if(comp > 1)
				printf("New Component\n");	// to separate each partition if exists
			dfs(g,i,n);
		}
}
void printAdjNodes(int **g,int n)
{
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			if(g[i][j] == 1)
				printf("%c is adjacent to %c\n",nodes[j],nodes[i]);
}
void printMatrix(int **g,int n)
{
	printf("The adjacency matrix is\n");
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
			printf("%d ",g[i][j]);
		printf("\n");
	}
}
int[][7] theGraph()
{
	int g[7][7]={{0,1,1,0,0,0,0},
		{1,0,1,0,1,0,0},
		{1,1,0,1,0,0,0},
		{0,0,1,0,1,0,0},
		{0,1,0,1,0,0,0},
		{0,0,0,0,1,0,1},
		{0,0,0,0,1,1,0}};
	return g;
}
	
main()
{
	int **g;
	int n;
	printf("Enter the number of vertices in the graph:");
	scanf("%d",&n);
	// g=make2DArray(n,n);
	/* printf("Enter the binary values for the adjacency matrix:");
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			scanf("%d",&g[i][j]);*/
	g=theGraph();
	printMatrix(g,n);
	printf("The adjacent nodes are\n");
	printAdjNodes(g,n);
	printf("The dfs traversal:\n");
	DFS(g,n);
}
