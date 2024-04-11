#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// 행렬을 출력하는 함수
void print_matrix(int *matrix[], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%8d\t", matrix[i][j]);
        }
        printf("\n");
    }
}

// A행렬+B행렬 addition 함수
int** addition_matrix(int *A[], int *B[], int rows, int cols) {
    int **C = (int **)malloc(rows * sizeof(int *));
    for (int i = 0; i < rows; i++) {
        C[i] = (int *)malloc(cols * sizeof(int));
    }

    // A+B를 C에 저장
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            C[i][j] = A[i][j] + B[i][j];
        }
    }

    return C;
}


// A행렬-B행렬 subtraction 함수
int** subtraction_matrix(int *A[], int *B[], int rows, int cols) {
    int **C = (int **)malloc(rows * sizeof(int *));
    for (int i = 0; i < rows; i++) {
        C[i] = (int *)malloc(cols * sizeof(int));
    }

    // A-B를 C에 저장
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            C[i][j] = A[i][j] - B[i][j];
        }
    }

    return C;
}


// A의 전치행렬을 구하는 transpose_matrix 함수
int** transpose_matrix(int *A[], int rows, int cols) {
    int **T = (int **)malloc(cols * sizeof(int *));
    for (int i = 0; i < cols; i++) {
        T[i] = (int *)malloc(rows * sizeof(int));
    }

    // A의 열과 행이 바뀐값을 T에 저장
    for (int i = 0; i < cols; i++) {
        for (int j = 0; j < rows; j++) {
            T[i][j] = A[j][i];
        }
    }

    return T;
}


// A행렬*B행렬 multiply 함수
int** multiply_matrix(int *A[], int *B[], int rows, int cols) {
    int **M = (int **)malloc(rows * sizeof(int *));
    for (int i = 0; i < rows; i++) {
        M[i] = (int *)malloc(cols * sizeof(int));
    }

    // A*B를 C에 저장
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            M[i][j] = A[i][j] * B[i][j];
        }
    }

    return M;
}


//메모리 해제 함수
free_matrix(int **matrix, int rows) {
    for (int i = 0; i < rows; i++) {
        free(matrix[i]);
    }
    free(matrix);
}



int main() {
    int **A, **B, **C, **D, **T, **M;
    int row_A, column_A, row_B, column_B;

    // 랜덤 시드 초기화
    srand(time(NULL));

    // A의 row 입력
    printf("A의 row 입력: ");
    scanf("%d", &row_A);

    // A의 column 입력
    printf("A의 column 입력: ");
    scanf("%d", &column_A);

    // B의 row 입력
    printf("B의 row 입력: ");
    scanf("%d", &row_B);

    // B의 column 입력
    printf("B의 column 입력: ");
    scanf("%d", &column_B);

    // A에 동적 메모리 할당
    A = (int **)malloc(row_A * sizeof(int *));
    // B에 동적 메모리 할당
    B = (int **)malloc(row_B * sizeof(int *));


    // A를 랜덤 값으로 채우기
    for (int i = 0; i < row_A; i++) {
        A[i] = (int *)malloc(column_A * sizeof(int));
        for (int j = 0; j < column_A; j++) {
            A[i][j] = rand() % 10000;
        }
    }

    // B를 랜덤 값으로 채우기
    for (int i = 0; i < row_B; i++) {
        B[i] = (int *)malloc(column_B * sizeof(int));
        for (int j = 0; j < column_B; j++) {
            B[i][j] = rand() % 10000;
        }
    }




    // 행렬 A 출력
    printf("A 행렬:\n");
    print_matrix(A, row_A, column_A);

    // 행렬 B 출력
    printf("B 행렬:\n");
    print_matrix(B, row_B, column_B);



    if (row_A == row_B && column_A == column_B) { //row와 column이 같을 경우만 수행
        C = addition_matrix(A, B, row_A, column_A);
        D = subtraction_matrix(A, B, row_A, column_A);
        M = multiply_matrix(A, B, row_A, column_A);

        // A+B출력(**C)
        printf("A + B 행렬:\n");
        print_matrix(C, row_A, column_A);

        // A-B출력(**D)
        printf("A - B 행렬:\n");
        print_matrix(D, row_A, column_A);

        // A*B출력(**M)
        printf("A * B 행렬:\n");
        print_matrix(M, row_A, column_A);


        // 메모리 해제
        free_matrix(C, row_A);
        free_matrix(D, row_A);
        free_matrix(M, row_A);
    }



    // A의 전치행렬
    T = transpose_matrix(A, row_A, column_A);
    printf("A의 전치행렬:\n");
    print_matrix(T, column_A, row_A);


    printf("[----- 강태광 2021041098 -----]");

    return 0;



    // 메모리 해제
    free_matrix(A, row_A);
    free_matrix(B, row_B);
    free_matrix(T, column_A);
}