#include <stdio.h>


/***************
* function bubble_sort()
*
* A int type of arrary
* len int type of A length
*
****************/

void bubble_sort(int A[],int len){

    int i,j,temp;

    // element from first to last-1
    for(i=0;i<len-1;i++){

        //element from last to first+1
        for(j=len-1;j>i;j--){

            //exchange A[j] A[j-1]
            if(A[j]<A[j-1]){
                temp=A[j];
                A[j]=A[j-1];
                A[j-1]=temp;
            }
        }
    }
}
int main()
{
    int A[10],i=0,len;
    char c;

    while (1) {

        scanf("%d",&A[i]);
        c=getchar();
        if(c=='\n')
            break;
        i++;
    }

    //use bubble_sort()
    len=i+1;
    bubble_sort(A,len);

    //output has sorted of A
    for(i=0;i<len;i++)
        printf("%d ",A[i]);
    return 0;
}

/**************************************
 *
 * input 5 2 4 7 1 3 2 6 9 8
 *
 * output 1 2 2 3 4 5 6 7 8 9
***************************************/
