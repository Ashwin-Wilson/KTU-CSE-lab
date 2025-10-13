#include <stdio.h>
#include <stdlib.h>
// #include<conio.h>
#include <math.h>
#include <ctype.h>
#include <string.h>
char in[25], post[25], stack[25], st[25][25], three[10][10], u[5];
int i, s, p, r, item, top, b, th = 0, tr = 0;
int pre(char t)
{
    int r;
    if ((t == '+') || (t == '-'))
        r = 1;
    if ((t == '*') || (t == '/'))
        r = 2;
    if (t == '^')
        r = 3;
    if ((t == '(') || (t == ')'))
        r = 0;
    return (r);
}
int main()
{
    int j, k, p, q, a, b;
    char *buff;
    // clrscr();
    r = 1;
    printf("\t\tOUTPUT\n");
    printf("****************************************\n");
    printf("Enter the expression:\n");
    scanf("%s", in);
    s = 1;
    p = 0;
    stack[0] = '(';
    for (i = 2; in[i] != '\0'; i++)
    {
        if ((in[i] != '+') && (in[i] != '-') && (in[i] != '*') && (in[i] != '/') && (in[i] != '^') && (in[i] != '(') && (in[i] != ')'))
        {
            post[p] = in[i];
            p++;
        }
        else
        {
            if (in[i] == '(')
            {
                stack[s] = in[i];
                s++;
            }
            else
            {
                if (in[i] == ')')
                {
                    while (stack[s - 1] != '(')
                    {
                        post[p] = stack[s - 1];
                        stack[s - 1] = ' ';
                        s--;
                        p++;
                    }
                    stack[s - 1] = ' ';
                    s--;
                }
                else
                {
                    a = pre(in[i]);
                    b = pre(stack[s - 1]);
                    j = p;
                    while (a <= b)
                    {
                        post[j] = stack[s - 1];
                        stack[s - 1] = ' ';
                        s--;
                        j++;
                        p = j;
                        b = pre(stack[s - 1]);
                    }
                    stack[s] = in[i];
                    s++;
                }
            }
        }
    }
    for (i = s - 1; i > 0; i--)
        if (stack[i] != '(')
        {
            post[p] = stack[i];
            p++;
        }
    printf("\n\nThe postfix notation for the given expression:\n\n");
    for (p = 0; post[p] != '\0'; p++)
        printf("%c", post[p]);
    printf("\n\nThree address code\n\n");
    top = 0;
    for (p = 0; post[p] != '\0'; p++)
    {
        if ((post[p] != '+') && (post[p] != '-') && (post[p] != '*') && (post[p] != '/') && (post[p] != '^'))
        {
            st[top][0] = post[p];
            st[top][1] = '\0';
            top++;
        }
        else
        {
            printf("t%d=%s%c%s\n", tr, st[top - 2], post[p], st[top - 1]);

            top--;
            top--;
            snprintf(u, sizeof(u), "%d", tr);
            // itoa(tr,u,10);
            strcpy(st[top], "t");
            strcat(st[top], u);
            tr++;
            top++;
        }
    }
    printf("%c=%s", in[0], st[0]);
    // getch();
}
