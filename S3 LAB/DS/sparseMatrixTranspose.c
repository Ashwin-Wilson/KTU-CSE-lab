#include <stdio.h>
int sparseMat[20][3];
int r, c;

void createSparseMat(int mat[r][c])
{
    int i, j;
    (sparseMat[0][2]) = 0;

    for (i = 0; i < r; i++)
    {
        for (j = 0; j < c; j++)
        {
            if (mat[i][j] != 0)
            {
                (sparseMat[0][2]) = ((sparseMat[0][2])) + 1;
                sparseMat[(sparseMat[0][2])][0] = i;
                sparseMat[(sparseMat[0][2])][1] = j;
                sparseMat[(sparseMat[0][2])][2] = mat[i][j];
            }
        }
    }
    (sparseMat[0][0]) = r;
    sparseMat[0][1] = c;
   
}
void transpose(int mat[(sparseMat[0][2])][3])
{
    int temp, i, j, row = 0;
    for (i = 0; i < (sparseMat[0][2]); i++)
    {
        row++;
        temp = mat[row][0];
        mat[row][0] = mat[row][1];
        mat[row][1] = temp;
    }
    printf("\nTransposed:\n");
    printf("\nrow\tcolumn\telement\n");
    for (i = 0; i <= row; i++)
    {
        for (j = 0; j < 3; j++)
        {
            printf("%d\t", mat[i][j]);
        }
        printf("\n");
    }
}
void main()
{
    int i, j;
    printf("Enter number of row and column: ");
    scanf("%d %d", &r, &c);
    int mat[r][c];
    for (i = 0; i < r; i++)
    {
        for (j = 0; j < c; j++)
        {
            scanf("%d", &mat[i][j]);
        }
    }

    printf("\nEntered mat:\n");
    for (i = 0; i < r; i++)
    {
        for (j = 0; j < 3; j++)
        {
            printf("%d\t", mat[i][j]);
        }
        printf("\n");
    }

    createSparseMat(mat);

    printf("\nrow\tcolumn\telement\n");
    for (i = 0; i <= (sparseMat[0][2]); i++)
    {
        for (j = 0; j < 3; j++)
        {
            printf("%d\t", sparseMat[i][j]);
        }
        printf("\n");
    }

    transpose(sparseMat);
}
