#include <stdio.h>

struct frame{
	int no;
	int freq;
	int time;
};

int rlimit, flimit;

int isPageExist(int pageNo, struct frame *f){
	int i;
	for(i=0;i<flimit;i++){
		if(f[i].no == pageNo){
			return i;
		}
	}
	return -1;
}


int findLFUindex(struct frame *f){
	
	int lfuindex = 0,i;
	for(i=1;i<flimit;i++){
		if(f[i].freq < f[lfuindex].freq || (f[i].freq == f[lfuindex].freq && f[i].time < f[lfuindex].time)){
			lfuindex = i;
		}
	}
	return lfuindex;
}

void main(){
	
	int i, j, pageFault=0, time=0;

	printf("\nEnter the number of reference string : ");
	scanf("%d",&rlimit);
	
	int p[rlimit];
	
	printf("\nEnter the reference string : ");
	for(i=0;i<rlimit;i++){
		scanf("%d",&p[i]);
	}
	
	printf("\nEnter the number of frames : ");
	scanf("%d",&flimit);
	
	struct frame f[flimit];
	
	for(i=0;i<flimit;i++){
		f[i].no = -1;
		f[i].freq = 0;
		f[i].time = 0;
	}
	
	for(i=0;i<rlimit;i++){
		
		int isExist = isPageExist(p[i], f);
		
		if(isExist != -1){
			f[isExist].freq++;
		}else{
			pageFault++;
			int lfuindex = findLFUindex(f);
			f[lfuindex].no = p[i];
			f[lfuindex].freq = 1;
			f[lfuindex].time = time;
			
		}
		time++;
		
		printf("\n");
		for(j=0;j<flimit;j++){
			printf("%d\t", f[j].no);
		}
		
	}
	
	printf("%d\t", pageFault);
	
	
	
}
