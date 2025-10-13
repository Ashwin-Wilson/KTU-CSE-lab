#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char ip_sym[15], stack[15];
int ip_ptr = 0, st_ptr = 0, len;

void check();

int main() {
    printf("\n\t\tSHIFT REDUCE PARSER\n");
    printf("\nGRAMMAR\n");
    printf("\n E-> E+E\n E-> E/E");
    printf("\n E-> E*E\n E-> a/b");
    printf("\nEnter the input symbol:\t");
    scanf("%s", ip_sym);

    len = strlen(ip_sym);
    printf("\n\tStack Implementation Table");
    printf("\nStack\t\tInput Symbol\t\tAction");
    printf("\n$ \t\t%s$\t\t\t--", ip_sym);

    while (ip_ptr < len) {

        stack[st_ptr++] = ip_sym[ip_ptr];
        stack[st_ptr] = '\0';

        ip_sym[ip_ptr] = ' ';
        ip_ptr++;

        printf("\n$%s\t\t%s$\t\t\tshift %c", stack, ip_sym, stack[st_ptr - 1]);

        check();
    }

   
    check();

    return 0;
}

void check() {
    int flag = 0;
    int top_len = strlen(stack);


    for (int i = 0; i < top_len; i++) {
        if (stack[i] == 'a' || stack[i] == 'b') {
            stack[i] = 'E';
            printf("\n$%s\t\t%s$\t\t\tE->%c", stack, ip_sym, stack[i]);
            flag = 1;
            top_len = strlen(stack);  
        }
    }

  
    while (top_len >= 3) {
        int reduced = 0;
        for (int i = 0; i < top_len - 2; i++) {
            if (stack[i] == 'E' && (stack[i + 1] == '+' || stack[i + 1] == '/' || stack[i + 1] == '*') && stack[i + 2] == 'E') {
            
                for (int j = i + 3; j <= top_len; j++) {
                    stack[i + 1 + (j - (i + 3))] = stack[j];
                }
                stack[i] = 'E';
                st_ptr = strlen(stack);
                top_len = strlen(stack);
                printf("\n$%s\t\t%s$\t\t\tE->E%cE", stack, ip_sym, stack[i + 1]);
                flag = 1;
                reduced = 1;
                break; 
            }
        }
        if (!reduced)
            break;
    }

 
    if (ip_ptr == len && strcmp(stack, "E") == 0) {
        printf("\n$%s\t\t%s\t\t\tACCEPT\n", stack, ip_sym);
        exit(0);
    }

    if (flag == 0 && ip_ptr == len) {
      
        printf("\n$%s\t\t%s\t\t\treject\n", stack, ip_sym);
        exit(0);
    }
}

