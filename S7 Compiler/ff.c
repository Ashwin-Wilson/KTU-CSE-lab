#include<stdio.h>
#include<string.h>

int ister(char);
void first(char);
void follow(char);
char grammar[20][20]={"E->TX","X->+TX","X->i","T->FY","Y->*FY","Y->i","F->(E)","F->i"};
char ter[]={'+','*','(',')','i'};
char nonter[]={'E','X','T','Y','F'};
char FIRST[10],FOLLOW[10];
int fi,fo;
int main()
{
    int i,j;
    printf("\n\n\n\t\t\tGRAMMAR\n\t\t\t-------\n");
    printf("\n\t\t\tE->TX\n\t\t\tX->+TX\n\t\t\tX->i\n\t\t\tT->FY\n\t\t\tY->*FY\n\t\t\tY->i\n\t\t\tF->(E)\n\t\t\tF->i");
    printf("\n\n\t\t\tFIRST\n\t\t\t-----\n");
    for(i=0;i<5;i++)
    {
        fi=0;
        for(j=0;j<10;j++)
            FIRST[j]='\0';
        printf("\n\t\t\tFIRST(%c)={",nonter[i]);
        first(nonter[i]);
        for(j=0;j<strlen(FIRST);j++)
            printf("%c,",FIRST[j]);
        printf("\b}");
    }
    printf("\n\n\t\t\tFOLLOW\n\t\t\t------\n");
    for(i=0;i<5;i++)
    {
        fo=0;
        for(j=0;j<10;j++)
            FOLLOW[j]='\0';
        printf("\n\t\t\tFOLLOW(%c)={",nonter[i]);
        follow(nonter[i]);
        for(j=0;j<strlen(FOLLOW);j++)
            printf("%c,",FOLLOW[j]);
        printf("\b}");
    }
    return 0;
}
void first(char x)
{
    int i;
    if(ister(x))
    {
        FIRST[fi++]=x;
    }
    else
        for(i=0;i<8;i++)
            if(grammar[i][0]==x)

if(grammar[i][3]=='i')
{
    FIRST[fi++]='i';
}
else
{
    first(grammar[i][3]);
}
}

void follow(char x)
{
    int i, j, k;
    if(x == 'E')  
    {
        int exists = 0;
        for(k=0; k<fo; k++)
            if(FOLLOW[k] == '$')
                exists = 1;
        if(!exists) FOLLOW[fo++] = '$';
    }

    for(i = 0; i < 8; i++) 
    {
        for(j = 3; grammar[i][j] != '\0'; j++) 
        {
            if(grammar[i][j] == x)
            {
                if(grammar[i][j+1] != '\0')
                {
                    fi = 0;
                    first(grammar[i][j+1]);

                    for(k = 0; k < fi; k++)
                    {
                        if(FIRST[k] != '!')
                        {
                            int exists = 0;
                            for(int m=0; m<fo; m++)
                                if(FOLLOW[m] == FIRST[k]) exists = 1;
                            if(!exists)
                                FOLLOW[fo++] = FIRST[k];
                        }
                        else
                        {
                            follow(grammar[i][0]);
                        }
                    }
                }
                
                else if(grammar[i][j+1] == '\0' && grammar[i][0] != x)
                {
                    follow(grammar[i][0]);
                }
            }
        }
    }
}


int ister(char a)
{
    for(int i=0;i<5;i++)
        if(ter[i]==a)
            return 1;
    return 0;
}
