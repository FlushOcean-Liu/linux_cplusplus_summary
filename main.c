#include  <stdio.h>
#include <stdlib.h>
#include "sort.h"

void  main_print(void)
{
	printf("\n=================================\n");
	printf("     Please select sort algorithm:\n");
	printf("     1.  quick_sort\n");
	printf("     2.  insert_sort\n");
	printf("     3.  bubble_sort\n");
	printf("     4.  shell_sort\n");
	printf("     0.  quit");
	printf("\n=================================\n");
}

int main()
{
	int n,num;
	int *a=NULL;
	
	int test_a[]={1,56,32,45,8,67,12,89,321,456,32,90,93,8,9,33,68,457,129,7};
	n=sizeof(test_a)/sizeof(test_a[0]);
	
	/*
	printf("\nPlease input the number of sort:\n");
	scanf("%d",&n);
	a=(int *)malloc(sizeof(int)*n);
	if(a==NULL){
		printf("malloc failed!");
		exit(-1);
	}
	
	printf("Please input the data:\n");
	for(i=0; i<n; i++){
		scanf("%d",&a[i]);
	}
	*/
	a=&test_a[0];
	printf("test data:\n");
	print(a, n);
	main_print();
	printf("select option:");
	scanf("%d",&num);
	if(num<0 || num >10){
		printf("unkonwn options \n");
		exit(-1);
	}
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
		case 4:
			shell_sort(a, n);
			break;
		case 0:
			return 1;
		default:
			return -1;
	}
	
	printf("after sort result:\n");
	print(a, n);


	return 0;
	
}

