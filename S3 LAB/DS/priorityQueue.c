// PRIORITY QUEUE
#include <stdio.h>
#define MAX_SIZE 100
struct Element {
 int data;
 int priority;
};
struct PriorityQueue {
 struct Element elements[MAX_SIZE];
 int size;
};
void initializeQueue(struct PriorityQueue *pq) {
 pq->size = 0;
}
int isFull(struct PriorityQueue *pq) {
 return (pq->size == MAX_SIZE);
}
int isEmpty(struct PriorityQueue *pq) {
 return (pq->size == 0);
}
void insert(struct PriorityQueue *pq, int data, int priority) {
 if (isFull(pq)) {
 printf("Queue Overflow\n");
 return;
 }
 int i;
 for (i = pq->size - 1; i >= 0; i--) {
 if (priority > pq->elements[i].priority) {
 pq->elements[i + 1].data = pq->elements[i].data;
 pq->elements[i + 1].priority = pq->elements[i].priority;
 } else {
 break;
 }
 }
 pq->elements[i + 1].data = data;
 pq->elements[i + 1].priority = priority;
 pq->size++;
 printf("Element %d with priority %d inserted into the Priority Queue\n", data, priority);
}
void delete(struct PriorityQueue *pq) {
 if (isEmpty(pq)) {
 printf("Queue Underflow\n");
 return;
 }
 printf("Element %d with priority %d deleted from the Priority Queue\n", pq->elements[0].data, pq-
>elements[0].priority);
 for (int i = 0; i < pq->size - 1; i++) {
 pq->elements[i].data = pq->elements[i + 1].data;
 pq->elements[i].priority = pq->elements[i + 1].priority;
 }
 pq->size--;
}
void display(struct PriorityQueue *pq) {
 if (isEmpty(pq)) {
 printf("Priority Queue is empty\n");
 return;
 }
 printf("Priority Queue elements: \n");
 for (int i = 0; i < pq->size; i++) {
 printf("Data: %d, Priority: %d\n", pq->elements[i].data, pq->elements[i].priority);
 }
 printf("\n");
}
int main() {
 struct PriorityQueue pq;
 initializeQueue(&pq);
 int choice, data, priority;
 do {
 printf("Priority Queue Menu:\n");
 printf("1. Insert element\n");
 printf("2. Delete element\n");
 printf("3. Display elements\n");
 printf("4. Exit\n");
 printf("Enter your choice: ");
 scanf("%d", &choice);
 switch (choice) {
 case 1:
 printf("Enter data: ");
 scanf("%d", &data);
 printf("Enter priority: ");
 scanf("%d", &priority);
 insert(&pq, data, priority);
 break;
 case 2:
 delete(&pq);
 break;
 case 3:
 display(&pq);
 break;
 case 4:
 printf("Exiting the program...\n");
 break;
 default:
 printf("Invalid choice\n");
 }
 } while (choice != 4);
 return 0;
}
