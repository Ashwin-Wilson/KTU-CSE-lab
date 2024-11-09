#include <stdio.h>
#include <stdlib.h>

struct Node {
    int coeff;
    int exp;
    struct Node* next;
};

struct Node* insert(struct Node* poly, int coeff, int exp) {
    struct Node* newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->coeff = coeff;
    newNode->exp = exp;
    newNode->next = NULL;
    if (poly == NULL) {
        poly = newNode;
    } else {
        struct Node* current = poly;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
    }
    return poly;
}

void display(struct Node* poly) {
    while (poly != NULL) {
       if (poly->exp == 1)
            printf("%dx ", poly->coeff);
        else if (poly->exp == 0)
            printf("%d ", poly->coeff);
        else
            printf("%dx^%d ", poly->coeff, poly->exp);
        if (poly->next != NULL)
        {
            printf("+ ");
        }
        poly = poly->next;
    }
    printf("\n");
}

struct Node* multiplyPolynomials(struct Node* poly1, struct Node* poly2) {
    struct Node* result = NULL;
    struct Node* current1 = poly1;
    while (current1 != NULL) {
        struct Node* current2 = poly2;
        while (current2 != NULL) {
            int coeff = current1->coeff * current2->coeff;
            int exp = current1->exp + current2->exp;

            // Check if the exponent exists in the result polynomial
            struct Node* temp = result;
            while (temp != NULL) {
                if (temp->exp == exp) {
                    temp->coeff += coeff; // Add coefficients if exponents match
                    break;
                }
                temp = temp->next;
            }

            // If the exponent doesn't exist, create a new term
            if (temp == NULL) {
                result = insert(result, coeff, exp);
            }
            current2 = current2->next;
        }
        current1 = current1->next;
    }
    return result;
}

void freePoly(struct Node* poly)
{
    struct Node *temp;
    while (poly != NULL)
    {
        temp = poly;
        poly = poly->next;
        free(temp);
    }
}

int main() {
    struct Node* poly1 = NULL;
    struct Node* poly2 = NULL;

    int n, coeff, exp;
    printf("Enter the number of terms for polynomial 1: ");
    scanf("%d", &n);
    printf("Enter the coefficients and exponents for polynomial 1:\n");
    for (int i = 0; i < n; ++i) {
        scanf("%d %d", &coeff, &exp);
        poly1 = insert(poly1, coeff, exp);
    }

    printf("Enter the number of terms for polynomial 2: ");
    scanf("%d", &n);
    printf("Enter the coefficients and exponents for polynomial 2:\n");
    for (int i = 0; i < n; ++i) {
        scanf("%d %d", &coeff, &exp);
        poly2 = insert(poly2, coeff, exp);
    }

    printf("\nFirst polynomial: ");
    display(poly1);
    printf("Second polynomial: ");
    display(poly2);

    struct Node* resultPoly = multiplyPolynomials(poly1, poly2);
    printf("\nResultant polynomial after multiplication: ");
    display(resultPoly);

    // Free memory
    freePoly(poly1);
    freePoly(poly2);
    freePoly(resultPoly);

    return 0;
}
