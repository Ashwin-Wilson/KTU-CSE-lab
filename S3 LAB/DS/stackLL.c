#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *rlink, *llink;
};
struct node *top;
struct node *head = NULL;

void printStack()
{
    if (head == NULL)
    {
        printf("\nStack is empty..!!\n");
    }
    else
    {
        struct node *temp = top;
        printf("\nStack is:");

        while (temp->llink != NULL)
        {
            printf("%d\t", temp->data);
            temp = temp->llink;

            printf("%d\t", head->data);
        }
    }
}
void push()
{

    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    printf("\nEnter value to push: ");
    scanf("%d", &newNode->data);
    newNode->rlink = NULL;
    if (head == NULL)
    {
        head = newNode;
        newNode->llink = NULL;
        top = newNode;
    }
    else
    {
        newNode->llink = top;
        top->rlink = newNode;
        top = newNode;
    }
    printStack();
}
void pop()
{
    if (head == NULL)
    {
        printf("\nUnderFlow\n");
    }
    else
    {
        struct node *temp = top;
        if (top->llink == NULL)
        {
            head = NULL;
            free(top);
            printStack();
        }
        else
        {
            top = top->llink;
            top->rlink = NULL;
            free(temp);
            printStack();
        }
    }
}
int main()
{
    int ch;
    while (1)
    {
        printf("\nEnter the operation:\n");
        printf("1.Push\n2.Pop\n3.Display\n4.Exit\n");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            push();
            break;
        case 2:
            pop();
            break;
        case 3:
            printStack();
            break;
        case 4:
            exit(0);
        default:
            printf("\ninvalid choice..!!\n");
        }
    }

    return 0;
}