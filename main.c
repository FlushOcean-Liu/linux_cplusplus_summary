#include  <stdio.h>
#include <stdlib.h>
#include "sort.h"

int main()
{
	int n,i;
	int *a=NULL;

	printf("Please input the number of sort:\n");
	scanf("%d",&n);

	a=(int *)malloc(sizeof(int)*n);

	printf("Please input the data:\n");
	for(i=0; i<n; i++)
	{
		scanf("%d",&a[i]);
	}


	quick_sort(a,0, n-1);
	
	print(a, n);
	printf("\n");
}

