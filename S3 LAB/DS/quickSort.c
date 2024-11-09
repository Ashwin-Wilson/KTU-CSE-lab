#include<stdio.h>
int quickSort(int arr[],int low,int high){
	if(low<high){
		int l=low,h=high,temp ,p=low;
		while(l<h){
			while(arr[l]<=arr[p] && l<h){
				l++;
			}
			while(arr[h]>arr[p] ){
				h--;
			}
			if(l<h){
				temp = arr[l];
				arr[l] = arr[h];
				arr[h] = temp;  
			}
			temp = arr[h];
			arr[h] = arr[p];
			arr[p] = temp;
			
			quickSort(arr,0,h-1);
			quickSort(arr,h+1,high);
		}
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
	
	quickSort(arr,0,n-1);
	
	printf("Sorted array: \t");
	for(i=0;i<n;i++){
		printf("%d\t",arr[i]);
	}
	printf("\n");
	
}
