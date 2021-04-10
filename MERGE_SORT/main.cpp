#include <stdio.h>

/**********************
 * function merge()
 *
 * A  numbers of a int type arrary
 * p  index begin int type
 * q  index mid int type
 * r  index end int type
 *
***********************/
void merge(int A[],int p,int q,int r){

    int n1,n2;
    n1=q-p+1;   //left length of A subarrary
    n2=r-q;     //right length of A subarrary

    //left and right subarrary of A
    int L[n1],R[n2];

    //temp index
    int i,j,k;

    for(i=0;i<n1;i++){
        L[i]=A[p+i];
        printf("%d ",L[i]);
    }
    printf("---------left------\n");

    for(j=0;j<n2;j++){
        /*because of repeat excute q=(p+r)/2 and j index begin 0,
        *so maybe cause p+i==q+j,the right subarrary of A,
        *R[] index is q+j+1 to void logic mistake
        **/
        R[j]=A[q+j+1];
        printf("%d ",R[j]);
    }
    printf("--------right--------\n");

    i=0;
    j=0;

    for(k=p;k<=r;k++){

        if(L[i]<=R[j]){

            A[k]=L[i];
            i++;
        }
        else {
            A[k]=R[j];
            j++;
        }

    }

}

/*********************************
* function merge_sort()
*
* A  numbers of a int type arrary
* p  index begin int type
* r  index end int type
*
* ********************************/
void merge_sort(int A[],int p,int r){

    int q;  //mid index of A

    if(p<r){
        q=(p+r)/2;
        merge_sort(A,p,q);  //left sub arrary
        merge_sort(A,q+1,r);//right sub arrary
        merge(A,p,q,r);
    }

}


int main()
{

    int p=0,r=0,A[10];
    char c;

    //input numer of A
    while (1) {
        scanf("%d",&A[r]);
        c=getchar();
        if(c=='\n')
            break;

        r++;
    }

    //use merge_sort()
    merge_sort(A,p,r);

    for(p=0;p<=r;p++)
        printf("%d ",A[p]);
    return 0;
}

/********************************
 *
 * input 5 2 4 7 1 3 2 6
 *
 * output 1 2 2 3 4 5 6 7
*********************************/
