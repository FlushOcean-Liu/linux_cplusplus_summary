#include <math.h>
#include <stdio.h>
/* 打印数组内容 */
void print(int a[], int len)
{
	int i;
	for(i=0; i<len; i++){
		printf("%d ", a[i]);
	}
	printf("\n");
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

/* 快速排序算法 */
void quick_sort(int a[], int low, int high)
{
	int loc = 0;
	if(low < high){
		loc =  partition(a, low, high);
		quick_sort(a, low, loc-1);
		quick_sort(a, loc+1, high);
	}
}


/* 插入排序算法 */
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


/* 冒泡排序算法 buble sort*/
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


void shell_sort(int a[], int len)
{
	int temp,gap = 1;
	int i,j;
	
	while(gap < len / 3){
		gap = gap * 3 + 1;
	}
	
	for(; gap > 0; gap = floor(gap / 3)){
		for(i = gap; i < len; i++){
			temp = a[i];
			for(j = i-gap; j>0 && a[j] > temp; j-=gap){
				a[j + gap] = a[j];
			}
			a[j + gap] = temp;
		}
	}
			
	return ;		
}


