#include <stdio.h>
#include <stdlib.h>

struct Term {
    int coeff;
    int exp;
    struct Term *next;
};

struct Term *createTerm(int coeff, int exp) {
    struct Term *newTerm = (struct Term *)malloc(sizeof(struct Term));
    if (newTerm == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    newTerm->coeff = coeff;
    newTerm->exp = exp;
    newTerm->next = NULL;
    return newTerm;
}

void insertTerm(struct Term **poly, int coeff, int exp) {
    struct Term *newTerm = createTerm(coeff, exp);
    if (*poly == NULL) {
        *poly = newTerm;
    } else {
        struct Term *temp = *poly;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newTerm;
    }
}

void displayPoly(struct Term *poly) {
    while (poly != NULL) {
        printf("%dx^%d ", poly->coeff, poly->exp);
        if (poly->next != NULL) {
            printf("+ ");
        }
        poly = poly->next;
    }
    printf("\n");
}

struct Term *addPolynomials(struct Term *poly1, struct Term *poly2) {
    struct Term *result = NULL;

    while (poly1 != NULL && poly2 != NULL) {
        if (poly1->exp > poly2->exp) {
            insertTerm(&result, poly1->coeff, poly1->exp);
            poly1 = poly1->next;
        } else if (poly1->exp < poly2->exp) {
            insertTerm(&result, poly2->coeff, poly2->exp);
            poly2 = poly2->next;
        } else {
            insertTerm(&result, poly1->coeff + poly2->coeff, poly1->exp);
            poly1 = poly1->next;
            poly2 = poly2->next;
        }
    }

    while (poly1 != NULL) {
        insertTerm(&result, poly1->coeff, poly1->exp);
        poly1 = poly1->next;
    }

    while (poly2 != NULL) {
        insertTerm(&result, poly2->coeff, poly2->exp);
        poly2 = poly2->next;
    }

    return result;
}

void freePoly(struct Term *poly) {
    struct Term *temp;
    while (poly != NULL) {
        temp = poly;
        poly = poly->next;
        free(temp);
    }
}

int main() {
    struct Term *poly1 = NULL;
    struct Term *poly2 = NULL;
    struct Term *result = NULL;
    int numTerms1, numTerms2;
    int coeff, exp;

    printf("Enter the number of terms in the first polynomial: ");
    scanf("%d", &numTerms1);
    printf("Enter the coefficients and exponents of the first polynomial:\n");
    for (int i = 0; i < numTerms1; i++) {
        scanf("%d %d", &coeff, &exp);
        insertTerm(&poly1, coeff, exp);
    }

    printf("Enter the number of terms in the second polynomial: ");
    scanf("%d", &numTerms2);
    printf("Enter the coefficients and exponents of the second polynomial:\n");
    for (int i = 0; i < numTerms2; i++) {
        scanf("%d %d", &coeff, &exp);
        insertTerm(&poly2, coeff, exp);
    }

    printf("\nFirst polynomial:\t");
    displayPoly(poly1);
    printf("Second polynomial:\t");
    displayPoly(poly2);

    result = addPolynomials(poly1, poly2);
    printf("Sum of the polynomials:\t");
    displayPoly(result);

    // Free memory
    freePoly(poly1);
    freePoly(poly2);
    freePoly(result);

    return 0;
}
