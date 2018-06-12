#include  <stdio.h>
#include <stdlib.h>
#include "sort.h"

void  main_print(void)
{
	printf("\n=================================\n");
	printf("     Please select sort algorithm:\n");
	printf("     1.  quick_sort\n");
	printf("     2.  insert_sort\n");
	printf("     3.  bubule_sort\n");
	printf("     0.  quit");
	printf("\n=================================\n");
}

int main()
{
	int n,i,num;
	int *a=NULL;

	printf("\nPlease input the number of sort:\n");
	scanf("%d",&n);
	a=(int *)malloc(sizeof(int)*n);

	printf("Please input the data:\n");
	for(i=0; i<n; i++){
		scanf("%d",&a[i]);
	}
	
  main_print();
  scanf("%d",&num);
	switch(num){
     case 1:
        quick_sort(a,0, n-1);
        break;
     case 2:
        insert_sort(a, n);
        break;
     case 3:
        buble_sort(a, n);
        break;
     case 0:
        return 1;
     default:
        return -1;
  }
  print(a, n);

	return 0;
	
}

