#include <stdio.h>
#include<conio.h>
/*----------
 *INSERT_SORT
 *
 * args
 * A[] int[],the number of A arrary
 * len int ,A length
 *
------------*/
void insert_sort(int A[],int len){

    int i,j,key;

    //printf("A length %d\n",len);  //output arrary length
    for(j=1;j<len;j++){

        key=A[j];
        i=j-1;
        while (i>-1&&A[i]>key) {    //i from 0 to 5,so i>-1
            A[i+1]=A[i];
            i=i-1;
            A[i+1]=key;
        }
    }

    //output A arrary
    for(i=0;i<len;i++)
        printf("%d ",A[i]);
}
int main()
{
    int A[10];
    int i=0;
    char c;
    while(1){
        scanf("%d",&A[i]); //input unmbers
        c=getchar();
        if(c=='\n')
            break;
        i++;
    }
    //printf("%d %d %d %d %d %d %d %d\n",A[0],A[1],A[2],A[3],A[4],A[5],A[6],A[7]);
    //use insert_sort
    insert_sort(A,i+1); //A length is i+1
    return 0;
}

/*---test------------
 * input 5 2 4 6 1 3
 *
 * output 1 2 3 4 5 6
 * ------------------*/
