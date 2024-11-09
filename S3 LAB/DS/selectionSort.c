#include<stdio.h>
void main(){
	int n, a[20],i,j,l=0,m=0;
	printf("\nEntered size : ");
	scanf("%d",&n);
	printf("\nEntered elements : \n");
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	
	for(i=0;i<n;i++){
		m=a[i];
		l=i;

		for(j=i+1;j<n;j++){
			if(a[j]<m){
				m=a[j];
				l=j;
			}
		}
		if(l != i){
			a[l] = a[i];
			a[i] = m;
		}
		
	}
	printf("\nSorted elements : ");
	for(i=0;i<n;i++){
		printf("%d\t",a[i]);
	}
	printf("\n");
}
