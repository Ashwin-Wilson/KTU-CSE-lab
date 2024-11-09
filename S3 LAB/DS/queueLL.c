
#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node *rear = NULL;
struct node *front = NULL;
void printQueue()
{
    if (front == NULL)
    {
        printf("\nQueue is empty..!!\n");
    }
    else
    {
        struct node *temp = front;
        printf("Queue is: ");
        while (temp->next != NULL)
        {
            printf("%d\t", temp->data);
            temp = temp->next;
        }
        printf("%d\t", temp->data);
    }
}
void enqueue()
{
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    printf("\nEnter value: ");
    scanf("%d", &newNode->data);
    newNode->next = NULL;
    if (front == NULL)
    {
        front = newNode;
        rear = newNode;
    }
    else
    {
        rear->next = newNode;
        rear = newNode;
    }
    printQueue();
}
void dequeue()
{
    if (front == NULL)
    {
        front = NULL;
        rear = NULL;
        printf("\nQueue is empty...!!\n");
    }
    else
    {
        front = front->next;
    }
    printQueue();
}
void main()
{
    int ch;
    while (1)
    {
        printf("\nEnter the operation:\n");
        printf("1.enqueue\n2.dequeue\n3.Display\n4.Exit\n");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            enqueue();
            break;
        case 2:
            dequeue();
            break;
        case 3:
            printQueue();
            break;
        case 4:
            exit(0);
        default:
            printf("\ninvalid choice..!!\n");
        }
    }
}