#include <stdio.h>
#define MAX 20

int A[MAX][MAX];
int B[MAX][MAX];

int spA[MAX][3]; // to store the sparse matrix A
int spB[MAX][3]; // to store the sparse matrix B

int sum[MAX][3]; // to store the sum of the sparse matrices
int cA, cB;      // counter variables to store no. of non-zero elements

void sparse(int, int);
void sum_in_sparse();

void main()
{
        int i, j, row, col;
        printf("Enter the number of rows of the matrix\n");

        scanf("%d", &row);
        printf("Enter the number of columns of the matrix\n");
        scanf("%d", &col);
        printf("Enter the elements of Matrix A\n");
        for (i = 0; i < row; i++)
        {
                for (j = 0; j < col; j++)
                {
                        scanf("%d", &A[i][j]);
                }
        }
        printf("Enter the elements of Matrix B\n");
        for (i = 0; i < row; i++)
        {
                for (j = 0; j < col; j++)
                {
                        scanf("%d", &B[i][j]);
                }
        }
        printf("Entered Matrix A:\n");
        for (i = 0; i < row; i++)
        {
                for (j = 0; j < col; j++)
                {
                        printf("%d ", A[i][j]);
                }
                printf("\n");
        }
        printf("Entered Matrix B:\n");
        for (i = 0; i < row; i++)
        {
                for (j = 0; j < col; j++)
                {
                        printf("%d ", B[i][j]);
                }
                printf("\n");
        }
        sparse(row, col);
        sum_in_sparse();
}

void sparse(int row, int col)
{
        int i, j, n;

        // Converting MATRIX A to SPARSE MATRIX
        spA[0][0] = row;
        spA[0][1] = col;
        cA = 0; // counter used to find number of non-zero elements
        n = 1;  // row index of sparse matrix A
        for (i = 0; i < row; i++)
        {
                for (j = 0; j < col; j++)
                {
                        if (A[i][j] != 0) // checks if element is a non-zero element
                        {
                                spA[n][0] = i;
                                spA[n][1] = j;
                                spA[n][2] = A[i][j];
                                n++;
                                cA++;
                        }
                }
        }
        spA[0][2] = cA;
        printf("Sparse Matrix A: \n");
        for (i = 0; i < cA + 1; i++)
        {
                for (j = 0; j < 3; j++)
                {
                        printf("%d ", spA[i][j]);
                }
                printf("\n");
        }

        // Converting MATRIX B to SPARSE MATRIX
        spB[0][0] = row;
        spB[0][1] = col;
        cB = 0; // counter used to find number of non-zero elements
        n = 1;  // row index of sparse matrix B
        for (i = 0; i < row; i++)
        {
                for (j = 0; j < col; j++)
                {
                        if (B[i][j] != 0) // checks if element is a non-zero element
                        {
                                spB[n][0] = i;
                                spB[n][1] = j;
                                spB[n][2] = B[i][j];
                                n++;
                                cB++;
                        }
                }
        }
        spB[0][2] = cB;
        printf("Sparse Matrix B: \n");
        for (i = 0; i < cB + 1; i++)
        {
                for (j = 0; j < 3; j++)
                {
                        printf("%d ", spB[i][j]);
                }
                printf("\n");
        }
}

void sum_in_sparse()
{
        int i = 1, j = 1, s = 1, temp = 0, non = 0; // row index (s)
        sum[0][0] = spA[0][0];
        sum[0][1] = spA[0][1];
        while ((i <= spA[0][2]) && (j <= spB[0][2]))
        {
                if (spA[i][0] == spB[j][0])
                {
                        if (spA[i][1] == spB[j][1])
                        {
                                temp = spA[i][2] + spB[j][2];
                                if (temp != 0)
                                {
                                        sum[s][0] = spA[i][0];
                                        sum[s][1] = spA[i][1];
                                        sum[s][2] = temp;
                                        s++;
                                        i++;
                                        j++;
                                }
                        }
                        else if (spA[i][1] < spB[j][1])
                        {
                                sum[s][0] = spA[i][0];
                                sum[s][1] = spA[i][1];
                                sum[s][2] = spA[i][2];
                                s++;
                                i++;
                        }
                        else if (spA[i][1] > spB[j][1])
                        {
                                sum[s][0] = spB[j][0];
                                sum[s][1] = spB[j][1];
                                sum[s][2] = spB[j][2];
                                s++;
                                j++;
                        }
                }
                else if (spA[i][0] < spB[j][0])
                {
                        sum[s][0] = spA[i][0];
                        sum[s][1] = spA[i][1];
                        sum[s][2] = spA[i][2];
                        s++;
                        i++;
                }
                else if (spA[i][0] > spB[j][0])
                {
                        sum[s][0] = spB[j][0];
                        sum[s][1] = spB[j][1];
                        sum[s][2] = spB[j][2];
                        s++;
                        j++;
                }
        }
        while (i <= spA[0][2])
        {
                sum[s][0] = spA[i][0];
                sum[s][1] = spA[i][1];
                sum[s][2] = spA[i][2];
                s++;
                i++;
        }
        while (j <= spB[0][2])
        {
                sum[s][0] = spB[j][0];
                sum[s][1] = spB[j][1];
                sum[s][2] = spB[j][2];
                s++;
                j++;
        }
        sum[0][2] = s - 1;
        non = s - 1; // no. of rows of sum = non-zero elements in sum
        printf("Sum of two Sparse Matrix is:\n");
        for (i = 0; i <= non; i++)
        {
                for (j = 0; j < 3; j++)
                {
                        printf("%d ", sum[i][j]);
                }
                printf("\n");
        }
}
