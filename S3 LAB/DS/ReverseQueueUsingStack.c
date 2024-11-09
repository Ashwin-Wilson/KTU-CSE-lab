#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

int stack[MAX_SIZE];
int top = -1;

int queue[MAX_SIZE];
int front = -1, rear = -1;

int isStackEmpty() {
    return top == -1;
}

int isStackFull() {
    return top == MAX_SIZE - 1;
}

void push(int value) {
    if (isStackFull()) {
        printf("Stack is full. Cannot push.\n");
    } else {
        top++;
        stack[top] = value;
    }
}

int pop() {
    if (isStackEmpty()) {
        printf("Stack is empty. Cannot pop.\n");
        return -1;
    } else {
        int value = stack[top];
        top--;
        return value;
    }
}

int isQueueEmpty() {
    return front == -1 && rear == -1;
}

int isQueueFull() {
    return rear == MAX_SIZE - 1;
}

void enqueue(int value) {
    if (isQueueFull()) {
        printf("Queue is full. Cannot enqueue.\n");
    } else {
        if (front == -1) {
            front = 0;
        }
        rear++;
        queue[rear] = value;
    }
}

int dequeue() {
    if (isQueueEmpty()) {
        printf("Queue is empty. Cannot dequeue.\n");
        return -1;
    } else {
        int value = queue[front];
        if (front == rear) {
            front = rear = -1;
        } else {
            front++;
        }
        return value;
    }
}

void reverseQueue() {
    while (!isQueueEmpty()) {
        push(dequeue());
    }
    while (!isStackEmpty()) {
        enqueue(pop());
    }
}

void display() {
    if (isQueueEmpty()) {
        printf("Queue is empty.\n");
    } else {
        printf("Queue elements: ");
        for (int i = front; i <= rear; i++) {
            printf("%d ", queue[i]);
        }
        printf("\n");
    }
}

int main() {
    int element, numElements;

    printf("Enter the number of elements to enqueue: ");
    scanf("%d", &numElements);

    for (int i = 0; i < numElements; i++) {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &element);
        enqueue(element);
    }

    printf("Original Queue: ");
    display();

    reverseQueue();

    printf("Reversed Queue: ");
    display();

    return 0;
}
