#include<stdio.h>

void main(){
	int arr[50],i,j,limit,num,beg=0,mid,end,flag=0,temp;
	printf("How many elements do you have: ");
	scanf("%d",&limit);
	end = limit-1;
	mid = (beg+end)/2;
	
	printf("\nEnter %d values: \n",limit);
	for(i=0;i<limit;i++){
		scanf("%d",&arr[i]);
	}
	
	for(i=limit-1;i>=0;i--){
		for(j=0;j<i;j++){
			if(arr[j]>arr[j+1]){
				temp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = temp;
			}
		}
	}
	
	printf("Sorted array: \n");
	for(i=0;i<limit;i++){
		printf("%d \t",arr[i]);
	}
	
	printf("\nEnter the value to search: ");
	scanf("%d",&num);
	
	
	while(beg<=end){
		if(num == arr[mid]){
			printf("\n %d found at position: %d",num,mid+1);
			flag = 1;
			break;
		}	
		else if(num>arr[mid]){
			beg = mid+1;
			mid = (beg+end)/2;
		}
		else{
			end = mid-1;	
			mid = (beg+end)/2;
		}
	}
	if(flag == 0){
		printf("%d not found",num);
	}
	
}
