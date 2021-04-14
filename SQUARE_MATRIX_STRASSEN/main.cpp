#include <stdio.h>
#include<stdlib.h>

/********************************
 *
 * function init_matrix()
 *
 * arg
 * n inttype the matrix size n*n
 *
*********************************/
int** init_matrix(int n){

    int i,j;

    // temp rows;
    int **temp=(int**) malloc(n*sizeof(int*));

    //temp columns
    for(i=0;i<n;i++)
        temp[i]=(int*)malloc(n*sizeof(int));

    if(temp!=NULL){
        for(i=0;i<n;i++)
            for(j=0;j<n;j++)
                temp[i][j]=0;
    }

    return temp;
}

/******************************************
 *
 * function add_matrix()
 *
 * args sub_M1,sub_M2 inttype **pointers
 * n the size of sub_M1 sub_M2 n*n
 *
 * return matrix **inttype
 *
 * *****************************************/
int** add_matrix(int** sub_ma1, int** sub_ma2, int n) {
    int** temp = init_matrix(n);
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            temp[i][j] = sub_ma1[i][j] + sub_ma2[i][j];
    return temp;
}

/******************************************
 *
 * function subtract_matrix()
 *
 * args sub_M1,sub_M2 inttype **pointers
 * n the size of sub_M1 sub_M2 n*n
 *
 * return matrix **inttype
 *
 * *****************************************/
int** subtract_matrix(int** sub_ma1, int** sub_ma2, int n) {
    int** temp = init_matrix(n);
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            temp[i][j] = sub_ma1[i][j] - sub_ma2[i][j];
    return temp;
}



/**********************************************
 *
 * function square_matrix_mutiply_recursive()
 *
 * args
 * A,B, inttype ** pointer
 * n inttype matrix size n*n
 *
 * return C inttype array
 *
************************************************/
int** square_matrix_strassen_mutiply(int **A,int **B,int n){

    int i,j;


    //only one element
    if (n == 1) {
        int** C = init_matrix(1);
        C[0][0] = A[0][0] * B[0][0];
        return C;
    }
    else{

        //init C,A,B
        int** C = init_matrix(n);
        int k = n/2;

        int** A11 = init_matrix(k);
        int** A12 = init_matrix(k);
        int** A21 = init_matrix(k);
        int** A22 = init_matrix(k);
        int** B11 = init_matrix(k);
        int** B12 = init_matrix(k);
        int** B21 = init_matrix(k);
        int** B22 = init_matrix(k);

        //resolve A,B matrixs to A11...A22,B11...B22
        for(i=0; i<k; i++)
            for(j=0; j<k; j++) {
                A11[i][j] = A[i][j];
                A12[i][j] = A[i][k+j];
                A21[i][j] = A[k+i][j];
                A22[i][j] = A[k+i][k+j];
                B11[i][j] = B[i][j];
                B12[i][j] = B[i][k+j];
                B21[i][j] = B[k+i][j];
                B22[i][j] = B[k+i][k+j];
            }

        //calculate P[1-7]
        int** P1 = square_matrix_strassen_mutiply(A11, subtract_matrix(B12, B22, k), k);
        int** P2 = square_matrix_strassen_mutiply(add_matrix(A11, A12, k), B22, k);
        int** P3 = square_matrix_strassen_mutiply(add_matrix(A21, A22, k), B11, k);
        int** P4 = square_matrix_strassen_mutiply(A22, subtract_matrix(B21, B11, k), k);
        int** P5 = square_matrix_strassen_mutiply(add_matrix(A11, A22, k), add_matrix(B11, B22, k), k);
        int** P6 = square_matrix_strassen_mutiply(subtract_matrix(A12, A22, k), add_matrix(B21, B22, k), k);
        int** P7 = square_matrix_strassen_mutiply(subtract_matrix(A11, A21, k), add_matrix(B11, B12, k), k);

        //calculate C11.....C22
        int** C11 = subtract_matrix(add_matrix(add_matrix(P5, P4, k), P6, k), P2, k);
        int** C12 = add_matrix(P1, P2, k);
        int** C21 = add_matrix(P3, P4, k);
        int** C22 = subtract_matrix(subtract_matrix(add_matrix(P5, P1, k), P3, k), P7, k);

        //copy C11,C12,C13,C14 to C
        for(i=0; i<k; i++)
            for(j=0; j<k; j++) {
                C[i][j] = C11[i][j];
                C[i][j+k] = C12[i][j];
                C[k+i][j] = C21[i][j];
                C[k+i][k+j] = C22[i][j];
            }

        //free memory
        for(i=0;i<k;i++){

            // free subarrays of A,B
            free(A11[i]);
            free(A12[i]);
            free(A21[i]);
            free(A22[i]);
            free(B11[i]);
            free(B12[i]);
            free(B21[i]);
            free(B22[i]);

            //free subarray of P
            free(P1[i]);
            free(P2[i]);
            free(P3[i]);
            free(P4[i]);
            free(P5[i]);
            free(P6[i]);
            free(P7[i]);

            //free subarray of C
            free(C11[i]);
            free(C12[i]);
            free(C21[i]);
            free(C22[i]);
        }

        //free rows of A,B
        free(A11);
        free(A12);
        free(A21);
        free(A22);
        free(B11);
        free(B12);
        free(B21);
        free(B22);

        //free rows of P
        free(P1);
        free(P2);
        free(P3);
        free(P4);
        free(P5);
        free(P6);
        free(P7);

        //free rows of C
        free(C11);
        free(C12);
        free(C21);
        free(C22);

        //make NULL
        A11=NULL;
        A12=NULL;
        A21=NULL;
        A22=NULL;
        B11=NULL;
        B12=NULL;
        B21=NULL;
        B22=NULL;
        P1=NULL;
        P2=NULL;
        P3=NULL;
        P4=NULL;
        P5=NULL;
        P6=NULL;
        P7=NULL;
        C11=NULL;
        C12=NULL;
        C21=NULL;
        C22=NULL;

        return C;
    }
}

int main()
{
    int n=2;
    int i,j;

    // init A,B
    int**A=init_matrix(2);
    int**B=init_matrix(2);
    A[0][0]=1;
    A[0][1]=3;
    A[1][0]=7;
    A[1][1]=5;

    B[0][0]=6;
    B[0][1]=8;
    B[1][0]=4;
    B[1][1]=2;


    //use square_matrix_strassen_mutiply()
    int **C=square_matrix_strassen_mutiply(A,B,n);

    //output C
    printf("the result of C is:\n");
    for(i=0;i<n;i++){
        for(j=0;j<n;j++)
            printf("%d ",*(*(C+i)+j));
        printf("\n"); //next line
    }

    return 0;
}

/****************************************
 *
 * input A={{1,3},{7,5}} B={{6,8},{4,2}}
 *
 * output C={{18,14},{62,66}};
 *
 * **************************************/
