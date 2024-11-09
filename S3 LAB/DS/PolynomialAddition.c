#include <stdio.h>
int n1,n2;
typedef struct{
	float coeff;
	int expo;
}poly;  
void add(poly p1[n1],poly p2[n2]){
	int i = 0,j = 0, k = 0;
	poly p3[20];
	while(i<n1 && j<n2){
		if(p1[i].expo == p2[j].expo){
			p3[k].coeff = p1[i].coeff + p2[j].coeff;
			p3[k].expo = p1[i].expo;
			i++;j++;k++;
		}else if(p1[i].expo > p2[j].expo){
			p3[k].coeff = p1[i].coeff;
			p3[k].expo = p1[i].expo;
			i++;k++;
		}else{
			p3[k].coeff = p2[j].coeff;
			p3[k].expo = p2[j].expo;
			j++;k++;
		}
	}
	while(i<n1){
		p3[k].coeff = p1[i].coeff;
		p3[k].expo = p1[i].expo;
		i++;k++;
	}
	while(j<n2){
		p3[k].coeff = p2[j].coeff;
		p3[k].expo = p1[j].expo;
		j++;k++;
	}
	for(int i = 0;i<k;i++){
		printf(" %fx^%d +",p3[i].coeff,p3[i].expo);
	}
	printf("\n");
}
void main(){
	printf("Enter the number of terms  in polynomial1 :");
	scanf("%d", &n1);
	printf("Enter the number of terms  in polynomial2 :");
	scanf("%d", &n2);
	poly p1[n1], p2[n2];
	for(int i = 0;i<n1;i++){
		printf("coefficent :");
		scanf("%f",&p1[i].coeff);
		printf("exponential :");
		scanf("%d",&p1[i].expo);
	}
	printf("Second polynomial\n\n");
	for(int i = 0;i<n2;i++){
		printf("coefficent :");
		scanf("%f",&p2[i].coeff);
		printf("exponential :");
		scanf("%d",&p2[i].expo);
	}
	add(p1,p2);
}
