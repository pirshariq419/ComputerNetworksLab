#include<stdio.h>
 #define INFINITY 9999
 #define MAX 10
 
 void dijikstra(int G[MAX][MAX], int n, int startnode);
 
 void main(){
 	int G[MAX][MAX], i, j, n, s;
 	printf("\n Enter the number of vertices: ");
 	scanf("%d", &n);
 	printf("Enter the adjacency matrix, -1 for no edge: \n");
 	for(i=0; i<n; i++){
 		for(j=0; j<n; j++){
 			scanf("%d", &G[i][j]);
 			if(G[i][j]== -1)
 				G[i][j]=INFINITY;
		 }
	 }
	 printf("\n Enter the starting node: ");
	 scanf("%d", &s);
	 dijikstra(G, n, s);
	 
 }
 
 void dijikstra(int G[MAX][MAX], int n, int startnode)
 {
 	int distance[MAX], pred[MAX];
 	int visited[MAX], count, mindistance, nextnode, i, j;
 	
 	for(i=0; i<n; i++)
	 {
 		distance[i]= G[startnode][i];
 		pred[i]=startnode;
 		visited[i]= 0;
	 }
	 distance[startnode]= 0;
	 visited[startnode]= 1;
	 count= 1;
	 while(count< n-1)
	 {
	 	mindistance= INFINITY;
	 	for(i=0; i<n; i++)
	 	{
	 		if(distance[i] < mindistance && (visited[i]==0))
			 {
				mindistance= distance[i];
				nextnode= i;
			 }	
		}
		visited[nextnode]= 1;
		
		for(i=0; i<n; i++)
		{
			if(visited[i]==0)
			{
				if(mindistance+ G[nextnode][i]< distance[i])
				{
					distance[i]= mindistance + G[nextnode][i];
					pred[i]= nextnode;
				}
			}
		}
		count++;
	 }
	 
	 for(i=0; i<n; i++)
	 {
	 	if(i !=startnode)
	 	{
	 		printf("\n Distance of %c = %d", i+65, distance[i])	;
	 		printf("\n Path = %c", i+65);
	 		j=i;
	 		do
	 		{
	 			j=pred[j];
	 			printf("<- %c", j+65);
			}
			while(j!= startnode);
		}
	 }	 
 }
