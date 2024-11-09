#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

char infixStack[MAX_SIZE];
int infixTop = -1;

char postfixStack[MAX_SIZE];
int postfixTop = -1;

void pushInfix(char item) {
    if (infixTop == MAX_SIZE - 1) {
        printf("Stack Overflow\n");
    }
    infixStack[++infixTop] = item;
}

char popInfix() {
    if (infixTop == -1) {
        printf("Stack Underflow\n");
    }
    return infixStack[infixTop--];
}

void pushPostfix(char item) {
    if (postfixTop == MAX_SIZE - 1) {
        printf("Stack Overflow\n");
    }
    postfixStack[++postfixTop] = item;
}

char popPostfix() {
    if (postfixTop == -1) {
        printf("Stack Underflow\n");
    }
    return postfixStack[postfixTop--];
}

int precedence(char operator) {
    switch (operator) {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        default:
            return 0;
    }
}

void infixToPostfix(char infix[]) {
    char symbol, popped;

    for (int i = 0; infix[i] != '\0'; ++i) {
        symbol = infix[i];

        if (symbol >= '0' && symbol <= '9') {
            pushPostfix(symbol);
        } else if (symbol == '(') {
            pushInfix(symbol);
        } else if (symbol == ')') {
            while ((popped = popInfix()) != '(') {
                pushPostfix(popped);
            }
        } else {
            while (precedence(infixStack[infixTop]) >= precedence(symbol)) {
                popped = popInfix();
                pushPostfix(popped);
            }
            pushInfix(symbol);
        }
    }
    while (infixTop != -1) {
        popped = popInfix();
        pushPostfix(popped);
    }
    postfixStack[++postfixTop] = '\0';
}

int evaluatePostfix(char postfix[]) {
    int operand, operand1, operand2;
    char symbol;

    for (int i = 0; postfix[i] != '\0'; ++i) {
        symbol = postfix[i];

        if (symbol >= '0' && symbol <= '9') {
            operand = symbol - '0';
            pushPostfix(operand);
        } else {
            operand2 = popPostfix();
            operand1 = popPostfix();

            switch (symbol) {
                case '+':
                    pushPostfix(operand1 + operand2);
                    break;
                case '-':
                    pushPostfix(operand1 - operand2);
                    break;
                case '*':
                    pushPostfix(operand1 * operand2);
                    break;
                case '/':
                    pushPostfix(operand1 / operand2);
                    break;
                default:
                    printf("Invalid operator in postfix expression\n");
            }
        }
    }
    return postfixStack[postfixTop];
}

void main() {
    char infixExpression[MAX_SIZE];
    printf("Enter infix expression: ");
    scanf("%s", infixExpression);

    infixToPostfix(infixExpression);
    printf("Postfix expression: %s\n", postfixStack);

    int result = evaluatePostfix(postfixStack);
    printf("Result of expression: %d\n", result);

}



