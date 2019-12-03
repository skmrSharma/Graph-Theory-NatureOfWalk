#include<stdio.h>
#include<string.h>

int main()
{
	char edges[10][10];
	char seq[10];

	printf("Enter the sequence:");
	scanf("%s",seq);

	int i,j;
	char tostring[3];

	for(i=0;i<strlen(seq)-1;i++)
	{

		tostring[0] = seq[i];
		tostring[1] = seq[i+1];
		tostring[2] = '\0';

		strcpy(edges[i],tostring);
	}

	for(i = 0;i<strlen(seq)-1;i++)
		printf("\n edge %s",edges[i]);
	return 0;
}

