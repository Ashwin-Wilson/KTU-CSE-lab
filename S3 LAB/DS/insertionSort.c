#include<stdio.h>
void main(){
	int n,k, a[20],i,j,l=0,m=0;
	printf("\nEntered size : ");
	scanf("%d",&n);
	printf("\nEntered elements : ");
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	for(i=0;i<n;i++){
		k=a[i];
		j = i-1;
		while(j>=0 &&a[j]>k){
			a[j+1]= a[j];
			j= j-1;
		}
		a[j+1]= k;
	}
	printf("\nSorted elements : ");
	for(i=0;i<n;i++){
		printf("%d\t",a[i]);
	}
			
	
}
