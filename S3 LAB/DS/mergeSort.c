#include<stdio.h>
void megre(int arr[], int low, int mid, int high){
	int i=low ,k=low, j=mid+1, b[20];
	while(i<=mid && j<= high){
		if(arr[i]<=arr[j]){
			b[k] = arr[i];
			i++;
			k++;
		}
		else{
			b[k] = arr[j];
			j++;
			k++;
		}
	}
	while(i<=mid){
		b[k++] = arr[i++];
	}
	while(j<=high){
		b[k++] = arr[j++];
	}
	for(i=low;i<=high;i++){
		arr[i] = b[i];
	}
}
void mergeSort(int arr[], int low, int high){
	int mid;
	if(low<high){
		mid = (low+high)/2;
		mergeSort(arr,low,mid);
		mergeSort(arr,mid+1,high);
		megre(arr,low,mid,high);
	}
}
void main(){
	int arr[20],n,i;
	printf("\nEnter the size : ");
	scanf("%d",&n);
	printf("\nEnter %d elements : \n",n);
	for(i=0;i<n;i++){
		scanf("%d",&arr[i]);
	}
	
	mergeSort(arr,0,n-1);
	
	printf("Sorted array: \t");
	for(i=0;i<n;i++){
		printf("%d\t",arr[i]);
	}
	printf("\n");
	
}
