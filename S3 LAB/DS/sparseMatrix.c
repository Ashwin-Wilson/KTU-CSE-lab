#include<stdio.h>
int sparseMat[20][3];
int r,c,sr=0;
void createSparseMat(int mat[r][c]){
	int i,j;
	for(i=0;i<r;i++){
  		for(j=0;j<c;j++){
  			if(mat[i][j] != 0){
  				sr++;
  				sparseMat[sr][0] = i;
  				sparseMat[sr][1] = j;
  				sparseMat[sr][2] = mat[i][j];
  			}
  		}
  	}
  	sparseMat[0][0] = r;
  	sparseMat[0][1] = c;
  	sparseMat[0][2] = sr;
}
void main(){
  	int i,j;
  	printf("Enter number of row and column: ");
  	scanf("%d %d",&r,&c);
  	int mat[r][c];
  	for(i=0;i<r;i++){
  		for(j=0;j<c;j++){
  			scanf("%d",&mat[i][j]);
  		}
  	}
  	
  	printf("\nEntered mat:\n");
	for(i=0;i<r;i++){
  		for(j=0;j<c;j++){
  			printf("%d\t",mat[i][j]);
  		}
  		printf("\n");
  	}
  	
  	createSparseMat(mat);
  	
  	printf("\nrow\tcolumn\telement\n");
  	for(i=0;i<=sr;i++){
  		for(j=0;j<3;j++){
  			printf("%d\t",sparseMat[i][j]);
  		}
  		printf("\n");
  	}
}
