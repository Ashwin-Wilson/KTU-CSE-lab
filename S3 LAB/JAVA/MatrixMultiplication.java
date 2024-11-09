import java.util.*;

class MatrixMultiplication {
	public static void main(String arr[]) {

		int i, j, k, temp = 0;
		int row2,column2 ;
		int mat1[][] = new int[20][20];
		int mat2[][] = new int[20][20];
		int result[][] = new int[20][20];
		Scanner sc = new Scanner(System.in);

		System.out.println("Enter Matrix 1 size: (row1/column1)");
		int row1 = sc.nextInt();
		int column1 = sc.nextInt();

		System.out.println("Enter the matrix 1 values:");
		for (i = 0; i < row1; i++) {
			for (j = 0; j < column1; j++) {
				mat1[i][j] = sc.nextInt();
			}
		}
		do {
			System.out.println("Enter Matrix 2 size: (row2/column2)");
			row2 = sc.nextInt();
			column2 = sc.nextInt();
		} while (row2 != column1);

		System.out.println("Enter the matrix 2 values:");
		for (i = 0; i < row2; i++) {
			for (j = 0; j < column2
			; j++) {
				mat2[i][j] = sc.nextInt();
			}
		}

		for (i = 0; i < row1; i++) {
			for (j = 0; j < column2; j++) {
				for (k = 0; k < column1; k++) {
					temp = temp + (mat1[i][k] * mat2[k][j]);

				}
				result[i][j] = temp;
				temp = 0;
			}
		}

		System.out.println("Result :");
		for (i = 0; i < row1; i++) {
			for (j = 0; j < column2; j++) {
				System.out.print(result[i][j] + "\t");
			}
			System.out.println("\n");
		}
	}
}
