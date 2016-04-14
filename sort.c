


void print(int a[], int len)
{
	int i;
	printf("the reasult is:\n");
	for(i=0; i<len; i++)
	{
		printf("%d ", a[i]);
	}
}




static int partition(int a[], int low, int high)
{
	int pivot = a[low];
	while(low < high)
	{
		while( (low < high) && (a[high] > pivot)) high--;
		a[low] = a[high];
		while( (low < high) && (a[high] <= pivot)) low++;
		a[high] = a[low]; 
	}
	a[low] = pivot;

	return low;
}

void quick_sort(int a[], int low, int high)
{
	int loc = 0;
	if(low < high)
	{
		loc =  partition(a, low, high);
		quick_sort(a, low, loc-1);
		quick_sort(a, loc+1, high);
	}
}





