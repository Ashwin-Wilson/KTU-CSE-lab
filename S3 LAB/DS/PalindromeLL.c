#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

struct Node {
    char data;
    struct Node *next;
    struct Node *prev;
};

int main() {
    char inputString[100];
    printf("Enter a string: ");
    scanf("%s", inputString);

    struct Node *head = NULL;
    struct Node *tail = NULL;

    // Create the doubly linked list
    for (int i = 0; inputString[i] != '\0'; i++) {
        struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
        if (newNode == NULL) {
            printf("Memory allocation failed.\n");
            exit(1);
        }
        newNode->data = inputString[i];
        newNode->next = NULL;

        if (head == NULL) {
            newNode->prev = NULL;
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    bool isPalindrome = true;

    // Check for palindrome
    struct Node *front = head;
    struct Node *end = tail;

    while (front != NULL && end != NULL) {
        if (tolower(front->data) != tolower(end->data)) {
            isPalindrome = false;
            break;
        }
        front = front->next;
        end = end->prev;
    }

    // Display result
    if (isPalindrome) {
        printf("The given string is a palindrome.\n");
    } else {
        printf("The given string is not a palindrome.\n");
    }

    // Free memory
    struct Node *temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}
