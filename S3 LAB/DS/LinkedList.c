#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

void printList(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void insertAtBeginning(struct Node** head, int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = *head;
    *head = newNode;
}

void insertAtEnd(struct Node** head, int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
        return;
    }

    struct Node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = newNode;
}

void insertAtPosition(struct Node** head, int value, int key) {
 	if(head == NULL){
		 return;
 	}
	struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
	newNode->data = value;
 	struct Node* temp = *head;
   
   	while((temp->data != key && temp->next != NULL)){
     		temp = temp->next;
    	 }
   	if(temp->data == key){
   		newNode->next = temp->next;
    		temp->next = newNode;
    		
  	}
    	else{
    		printf("Search failed\n");
    	}
    
}

void deleteAtBeginning(struct Node** head) {
    if (*head == NULL) {
        printf("List is empty, deletion not possible.\n");
        return;
    }

    struct Node* temp = *head;
    *head = temp->next;
    free(temp);
}

void deleteAtEnd(struct Node** head) {
    if (*head == NULL) {
        printf("List is empty, deletion not possible.\n");
        return;
    }
    if ((*head)->next == NULL) {
        free(*head);
        *head = NULL;
        return;
    }

    struct Node* temp = *head;
    while (temp->next->next != NULL) {
        temp = temp->next;
    }

    free(temp->next);
    temp->next = NULL;
}

void deleteAtPosition(struct Node** head, int key) {
  	if(head == NULL){
		 return;
 	}
 	struct Node* curr = *head;
 	struct Node* prev = *head;
   
   	while((curr->data != key && curr->next != NULL)){
	   	prev = curr;
	   	curr = curr->next;
    	 }
   	if(curr == NULL){
   		printf("Search failed\n");
  	}
    	else{
    		prev->next = curr->next;
    		curr->next = NULL;
    		 printList(*head);
    	}
}

int main() {
    struct Node* head = NULL;
    int choice, value, key;

    do {
        printf("\nMenu:\n");
        printf("1. Insert at beginning\n");
        printf("2. Insert at end\n");
        printf("3. Insert at any position\n");
        printf("4. Delete at beginning\n");
        printf("5. Delete at end\n");
        printf("6. Delete at any position\n");
        printf("7. Print list\n");
        printf("8. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Enter value to insert at beginning: ");
                scanf("%d", &value);
                insertAtBeginning(&head, value);
                break;
            case 2:
                printf("Enter value to insert at end: ");
                scanf("%d", &value);
                insertAtEnd(&head, value);
                break;
            case 3:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                printf("Enter after: ");
                scanf("%d", &key);
                insertAtPosition(&head, value, key);
                break;
            case 4:
                deleteAtBeginning(&head);
                break;
            case 5:
                deleteAtEnd(&head);
                break;
            case 6:
                printf("Enter value to delete: ");
                scanf("%d", &value);
                deleteAtPosition(&head, value);
                break;
            case 7:
                printf("Linked List: ");
                printList(head);
                break;
            case 8:
                printf("Exiting program. Thank you!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 8);
    return 0;
}
