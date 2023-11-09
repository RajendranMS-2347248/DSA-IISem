#include <stdio.h>


// We are taking the data of smartphone sales and performing the said operations on the 2 matrices
// Structure to represent a matrix
struct Matrix {
    int rows;
    int cols;
    int data[3][3]; // Assuming a 3x3 matrix
};

// Function to insert data into a matrix
void insertData(struct Matrix *matrix) {
    printf("Enter %dx%d matrix data:\n", matrix->rows, matrix->cols);
    for (int i = 0; i < matrix->rows; i++) {
        for (int j = 0; j < matrix->cols; j++) {
            printf("Enter element at row %d, column %d: ", i + 1, j + 1);
            scanf("%d", &matrix->data[i][j]);
        }
    }
}

// Function to delete data from a matrix
void deleteData(struct Matrix *matrix, int row, int col) {
    if (row >= 1 && row <= matrix->rows && col >= 1 && col <= matrix->cols) {
        matrix->data[row - 1][col - 1] = 0;
        printf("Data at row %d, column %d has been deleted.\n", row, col);
    } else {
        printf("Invalid row or column.\n");
    }
}

// Function to perform linear search for a given value
void linearSearch(struct Matrix *matrix, int value) {
    int found = 0;
    for (int i = 0; i < matrix->rows; i++) {
        for (int j = 0; j < matrix->cols; j++) {
            if (matrix->data[i][j] == value) {
                printf("Value %d found at row %d, column %d.\n", value, i + 1, j + 1);
                found = 1;
            }
        }
    }
    if (!found) {
        printf("Value %d not found in the matrix.\n", value);
    }
}

// Function to perform matrix addition
void matrixAddition(struct Matrix *matrix1, struct Matrix *matrix2, struct Matrix *result) {
    if (matrix1->rows != matrix2->rows || matrix1->cols != matrix2->cols) {
        printf("Matrix dimensions are not compatible for addition.\n");
        return;
    }

    result->rows = matrix1->rows;
    result->cols = matrix1->cols;

    for (int i = 0; i < result->rows; i++) {
        for (int j = 0; j < result->cols; j++) {
            result->data[i][j] = matrix1->data[i][j] + matrix2->data[i][j];
        }
    }
}

// Function to perform matrix multiplication
void matrixMultiplication(struct Matrix *matrix1, struct Matrix *matrix2, struct Matrix *result) {
    if (matrix1->cols != matrix2->rows) {
        printf("Matrix dimensions are not compatible for multiplication.\n");
        return;
    }

    result->rows = matrix1->rows;
    result->cols = matrix2->cols;

    for (int i = 0; i < result->rows; i++) {
        for (int j = 0; j < result->cols; j++) {
            result->data[i][j] = 0;
            for (int k = 0; k < matrix1->cols; k++) {
                result->data[i][j] += matrix1->data[i][k] * matrix2->data[k][j];
            }
        }
    }
}

// Function to display a matrix
void displayMatrix(struct Matrix *matrix) {
    for (int i = 0; i < matrix->rows; i++) {
        for (int j = 0; j < matrix->cols; j++) {
            printf("%d\t", matrix->data[i][j]);
        }
        printf("\n");
    }
}

int main() {
    struct Matrix matrixA;
    struct Matrix matrixB;
    struct Matrix resultMatrix;

    matrixA.rows = 3;
    matrixA.cols = 3;

    matrixB.rows = 3;
    matrixB.cols = 3;

    resultMatrix.rows = 3;
    resultMatrix.cols = 3;

    // Insert data into two matrices
    insertData(&matrixA);
    insertData(&matrixB);

    printf("\nMatrix A:\n");
    displayMatrix(&matrixA);
    printf("\nMatrix B:\n");
    displayMatrix(&matrixB);

    // Perform matrix addition
    matrixAddition(&matrixA, &matrixB, &resultMatrix);
    printf("\nMatrix Addition (A + B):\n");
    displayMatrix(&resultMatrix);

    // Perform matrix multiplication
    matrixMultiplication(&matrixA, &matrixB, &resultMatrix);
    printf("\nMatrix Multiplication (A * B):\n");
    displayMatrix(&resultMatrix);

    // Delete data from Matrix A
    int row, col;
    printf("\nEnter the row and column to delete data from Matrix A: ");
    scanf("%d %d", &row, &col);
    deleteData(&matrixA, row, col);
    printf("\nUpdated Matrix A:\n");
    displayMatrix(&matrixA);

    // Linear search
    int valueToSearch;
    printf("\nEnter a value to search in the matrices: ");
    scanf("%d", &valueToSearch);
    linearSearch(&matrixA, valueToSearch);
    linearSearch(&matrixB, valueToSearch);

    return 0;
}
