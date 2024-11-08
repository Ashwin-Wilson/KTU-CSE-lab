#include <stdio.h>

void main(){
	
	int start=0, end, limit, i, j, direction, initial, hmove = 0;
	
	printf("\nEnter the number of limit: ");
	scanf("%d",&limit);
	
	int rq[limit];
	
	printf("\nEnter the request sequence : ");
	for(i=0;i<limit;i++){
		scanf("%d", &rq[i]);
	}
	
	int temp;
	for(i=limit-1;i>0;i--){
		for(j=0;j<i;j++){
			if(rq[j] > rq[j+1]){
				temp = rq[j];
				rq[j] = rq[j+1];
				rq[j+1] = temp;
			}
		}
	}
	
	printf("\nSorted req: \n");
	for(j=0;j<limit;j++){
			printf("%d\t",rq[j]);
	}
	
	printf("\nEnter the direction \n0 for low \n1 for high: ");
	scanf("%d", &direction);
	
	printf("\nEnter initial head position : ");
	scanf("%d", &initial);
	
	printf("\nEnter disk size : ");
	scanf("%d", &end);
	end--;
	
		
	
	
	
	if(direction == 0){
		hmove = initial;
		if(rq[limit-1] >= initial){
			hmove += (rq[limit-1]);
		}
	}else{
		hmove = end - initial;
		if(rq[0] <= initial){
			hmove =  (end - rq[0]) + hmove;
		}
	}
	printf("\nHead movement  : %d", hmove);
	
	
	
}
