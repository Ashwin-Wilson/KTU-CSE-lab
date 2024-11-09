#include <stdio.h>
#include<stdlib.h>
#include <limits.h>

int main() {

  int n, head, min_mov, i, head_mov = 0;
  int disk_queue[25],min_idx;
  printf("ENTER THE SIZE OF DISK QUEUE: ");
  scanf("%d", &n);
  printf("ENTER THE DISK QUEUE: ");
  for (i = 0; i < n; i++) 
    scanf("%d", &disk_queue[i]);
  printf("ENTER THE INITIAL HEAD POSITION: ");
  scanf("%d", &head);

  printf("\nSEEK SEQUENCE IN SSTF: %d ",head);
  for (i = 0; i < n; i++) {  
    min_mov = INT_MAX;
    for (int j = 0; j < n; j++) 
      if (disk_queue[j] != -1 && abs(disk_queue[j] - head) < min_mov) {
        min_mov = abs(disk_queue[j] - head);
        min_idx = j;
      }
    
    printf("%d ",disk_queue[min_idx]);
    head_mov += min_mov;
    head = disk_queue[min_idx];
    disk_queue[min_idx] = -1;
  }
  printf("\nTOTAL HEAD MOVEMENTS: %d\n", head_mov);
  return 0;
}
