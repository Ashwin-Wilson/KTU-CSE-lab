#include <stdio.h>

#define MAX_SIZE 100

int dequeue[MAX_SIZE];
int front = -1;
int rear = -1;
int isEmpty() {
    return front == -1;
}
int isFull() {
    return (front == 0 && rear == MAX_SIZE - 1) || front == rear + 1;
}

void display() {
    if (isEmpty()) {
        printf("DEQUEUE is empty.\n");
    } else {
        printf("DEQUEUE elements: ");
        int i = front;
        while (1) {
            printf("%d ", dequeue[i]);
            if (i == rear) {
                break;
            }
            if (i == MAX_SIZE - 1) {
                i = 0;
            } else {
                i++;
            }
        }
        printf("\n");
    }
}



void insertFront(int value) {
    if (isFull()) {
        printf("DEQUEUE is full, cannot insert at front.\n");
    } else {
        if (front == -1) {
            front = 0;
            rear = 0;
        } else if (front == 0) {
            front = MAX_SIZE - 1;
        } else {
            front--;
        }
        dequeue[front] = value;
        display();
    }
}

void insertRear(int value) {
    if (isFull()) {
        printf("DEQUEUE is full, cannot insert at rear.\n");
    } else {
        if (front == -1) {
            front = 0;
            rear = 0;
        } else if (rear == MAX_SIZE - 1) {
            rear = 0;
        } else {
            rear++;
        }
        dequeue[rear] = value;
        display();
    }
}

int deleteFront() {
    int item;
    if (isEmpty()) {
        printf("DEQUEUE is empty, cannot delete from front.\n");
        return -1;
    } else {
        item = dequeue[front];
        if (front == rear) {
            front = rear = -1;
        } else {
            if (front == MAX_SIZE - 1) {
                front = 0;
            } else {
                front++;
            }
        }
         display();
        return item;
       
    }
}

int deleteRear() {
    int item;
    if (isEmpty()) {
        printf("DEQUEUE is empty, cannot delete from rear.\n");
        return -1;
    } else {
        item = dequeue[rear];
        if (front == rear) {
            front = rear = -1;
        } else {
            if (rear == 0) {
                rear = MAX_SIZE - 1;
            } else {
                rear--;
            }
        }
         display();	
        return item;
       
    }
}



int main() {
    int choice, value;

    do {
        printf("\nDouble-Ended Queue (DEQUEUE) Operations:\n");
        printf("1. Insert at Front\n");
        printf("2. Insert at Rear\n");
        printf("3. Delete from Front\n");
        printf("4. Delete from Rear\n");
        printf("5. Display DEQUEUE\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert at front: ");
                scanf("%d", &value);
                insertFront(value);
                break;
            case 2:
                printf("Enter value to insert at rear: ");
                scanf("%d", &value);
                insertRear(value);
                break;
            case 3:
                printf("Deleted element from front: %d\n", deleteFront());
                break;
            case 4:
                printf("Deleted element from rear: %d\n", deleteRear());
                break;
            case 5:
                display();
                break;
            case 6:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }
    } while (choice != 6);

    return 0;
}
