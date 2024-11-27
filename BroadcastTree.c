#include <stdio.h>

void main(){
	int a[100][100], i, j, n, k, l, v[100], min=32765, c;
	
	printf("Enter how many nodes in subnet \n");
	scanf("%d", &n);
	printf("Enter adjacency matrix values( -1 for no link)\n");
	for(i=0; i<n; i++)
	{
		v[i]= 0;
		for(j=0; j<n; j++)
		{
			scanf("%d", &a[i][j]);
			if(a[i][j] != -1 && min > a[i][j])
			{
				min= a[i][j];
				k=i;
				l=j;
			}
		}
	}
	
	printf("The links of broadcast tree are\n");
	printf("%c - %c with delay %d \n", k+65, l+65, min);
	v[k]=v[l]=1;
	c=1;
	while(c<= n-2)
	{
		min=32765;
		for(i=0; i<n; i++)
		{
			if(v[i]==1)
			{
				for(j=0; j<n; j++)
				{
					if(a[i][j] != -1 && v[j]==0 && min > a[i][j])
					{
						min= a[i][j];
						k=i;
						l=j;
					}
				}
			}
		}
		v[l]= 1;
		printf("%c - %c with delay %d \n", k+65, l+65, min);
		c++;
	}
}
