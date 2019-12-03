#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define FALSE 0
#define TRUE 1

short int visited[10];
char nodes[10];
int** make2DArray(int rows,int cols)
{
	int **g;
	g=(int **)malloc(rows*sizeof(int*));
	for(int i=0;i<rows;i++)
		g[i]=(int*)malloc(cols*sizeof(int));
	return g;
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

int checkvalidity(char seq[],int **graph)
{
	int i,j;
	int exists = 0;
	for(i=0;i<strlen(seq);i++){
		exists = 0;
		for(j=0;j<strlen(nodes);j++)
			if(seq[i] == nodes[j]){
				exists = 1;
				break;
			}
	if(exists == 0)
		return 0;
	}
	
	//check for adjacency
	for(i = 0;i<strlen(seq)-1;i++)
		if(graph[abs(nodes[0] - seq[i])][abs(nodes[0] - seq[i+1])] != 1)
		{
			printf("\n%c and %c are not Adjacent",seq[i],seq[i+1]);
			return 0;
		}
	return 1;
}
int edgeRepeat(char seq[])	// to check the sequence for repeated edges
{
	char edges[20][4];

	int i,j;
	char edge[3];

	for(i=0;i<strlen(seq)-1;i++)
	{

		if(seq[i]<seq[i+1])
		{

			edge[0] = seq[i];
			edge[1] = seq[i+1];
		}
		else
		{
			edge[0] = seq[i+1];
			edge[1] = seq[i];
		}
		edge[2] = '\0';
		strcpy(edges[i],edge);
	}
	for(i = 0;i<strlen(seq)-1;i++)
		printf("\n edge %s",edges[i]);
	for(i=0;i<strlen(seq)-1;i++)
		for(j=0;j<strlen(seq)-1;j++)
			if(i!=j)
				if(!strcmp(edges[i],edges[j]))
					return 1;
	return 0;
}
int vertexRepeat(char seq[])
{
	int i;
	int count[10] = {0};
	if(seq[0] == seq[strlen(seq)-1])
		for(i=1;i<strlen(seq);i++)
			count[seq[i] - nodes[0]]++;
	else
		for(i=0;i<strlen(seq);i++)
			count[seq[i] - nodes[0]]++;
	for(i=0;i<10;i++)
	{
		//printf("%d",count[i]);
		if(count[i]>1)
			return 1;
	}
	return 0;
}

void natureOfWalk(char seq[])
{
	int eRepeat=edgeRepeat(seq);
	int vRepeat=vertexRepeat(seq);
	if(seq[0]!=seq[strlen(seq)-1])	// first vertex == last vertex ?
	{
		if(eRepeat)	// do the edges repeat ?
		{
			printf("\nOpen Walk which is not a trail\n");		
			return;
		}
		if(eRepeat == 0 && vRepeat == 1)
		{
			printf("\nTrail which is not a path\n");
			return;
		}
		if(eRepeat == 0 && vRepeat == 0)
		{
			printf("\nPath\n");
			return;
		}
	}
	else
	{
		
		if(eRepeat)
		{
			printf("\nClosed walk which is not a circuit\n");
			return;
		}
		if(eRepeat == 0 && vRepeat == 1)
		{
			printf("\nClosed walk which is a circuit\n");
			return;
		}
		if(eRepeat == 0 && vRepeat == 0)
		{
			printf("\nClosed walk which is a cycle\n");
			return;
		}

	}
}
void createAdjMatrix(int **g,int n)
{
	char av;
	for(int i=0;i<n;i++)
	{
		printf("Enter the vertices adjacent to vertex %c\nEnter (.) to go to next vertex:",nodes[i]);
		for(;;)
		{
			scanf("%c",&av);
			if(av=='.')
				break;
			g[i][av-nodes[0]]=1;
		}
	}
}

int main()
{
	char seq[30];
	/*int g[7][7]={{0,1,1,0,0,0,0},
		{1,0,1,0,1,0,0},
		{1,1,0,1,0,0,0},
		{0,0,1,0,1,0,0},
		{0,1,0,1,0,1,1},
		{0,0,0,0,1,0,1},
		{0,0,0,0,1,1,0}};
	*/
	int **g;
	int n;
	printf("Enter the number of vertices in the graph:");
	scanf("%d",&n);
	g=make2DArray(n,n);
	printf("Enter the vertices in sorted order:");
	scanf("%s",nodes);
	createAdjMatrix(g,n);
	/*printf("Enter the adjacency matrix:");
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			scanf("%d",&g[i][j]);*/
	printMatrix(g,n);
	printf("Enter the sequence:");
	scanf("%s",seq);
	if(checkvalidity(seq,g))
		natureOfWalk(seq);
	else
		printf("\nThe given sequence is invalid\n");

	return 0;
}
