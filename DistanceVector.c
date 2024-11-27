#include <stdio.h>
void main(){
	int n, s, nn[10], delay[10], m, rt[20][30], i, j, min, node;
	printf("\n Enter number of nodes in a network: ");
	scanf("%d", &n);
	printf("\n Enter node number(A-0, B-1,..., H-7, I-8, J-9, K-10) to update routing table: ");
	scanf("%d", &s);
	printf("\n Enter number of neighbours for %c: ", s+65);
	scanf("%d", &m);
	
	for(i=0; i<m; i++){
		printf("\n Enter the neighbouring node number: ");
		scanf("%d", &nn[i]);
		printf("\n Enter delay from %c to neighbour %c: ", s+65, nn[i]+65);
		scanf("%d", &delay[i]);
	}
	
	printf("\n Enter the routing table of all %d neighbours: ", m);
	
	for( i=0; i<m; i++){
		for(j=0; j<n; j++){
			scanf("%d", &rt[i][j]);
			rt[i][j]+= delay[i];
		}
	}
	printf("\n The updated routing of %c is: \n", s+65);
	printf("\n To|Delay|Line");
	for(i=0; i<n; i++){
		min= 32767;
		for(j=0; j<m; j++){
			
			if(rt[j][i]< min){
				min=rt[j][i];
				node= nn[j];
			}
		}
		if(s!=i)
			printf("\n %c|%d|%c|", i+65, min, node+65);
		else
			printf("\n %c|0|-|", s+65);
	}

}
