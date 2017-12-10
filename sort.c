
void print(int a[], int len)
{
	int i;
	printf("the resualt is:");
	for(i=0; i<len; i++){
		printf("%d ", a[i]);
	}
}

static int partition(int a[], int low, int high)
{
	int pivot = a[low];
	while(low < high){
		while( (low < high) && (a[high] > pivot)) 
			high--;
		a[low] = a[high];
		while( (low < high) && (a[low] <= pivot)) 
			low++;
		a[high] = a[low]; 
	}
	a[low] = pivot;

	return low;
}

void quick_sort(int a[], int low, int high)
{
	int loc = 0;
	if(low < high){
		loc =  partition(a, low, high);
		quick_sort(a, low, loc-1);
		quick_sort(a, loc+1, high);
	}
}

void insert_sort(int a[], int len)
{
	int i;
	for(i=0; i<len; i++){
		int temp = a[i];
		int j=i;
		while(j>0 && a[j-1] > temp){
			a[j]=a[j-1];
			j--;
		}
		a[j]=temp;
	}
}


/* buble sort*/
void buble_sort(int a[], int len)
{
	int i,j,k;
	for(j=0;j<len;j++){
		for(i=0;i<len-j-1;i++){
			if(a[i]>a[i+1]){
				k=a[i];
				a[i]=a[i+1];
				a[i+1]=k;		
			}
		}
	}
}





