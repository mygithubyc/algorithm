#include <stdio.h>
#include<stdlib.h>
#define NEGA_INFINIT -999999;


/***************************************
 *
 *function find_max_crossing_subarray()
 *
 * args:
 *
 * A inttype array
 * low the lower index of A
 * mid the middle index of A
 * high the higher index of A
 *
 * return
 * *max_suba
 *
****************************************/

int * find_max_crossing_subarray(int A[],int low,int mid,int high){

    int i,j,sum;
    int left_sum,right_sum;
    int max_left,max_right;
    int *max_suba;

    max_suba=(int*)malloc(sizeof(int *)*3);
    left_sum=NEGA_INFINIT;
    sum=0;

    //index decrease from mid to low of left A subarray
    for(i=mid;i>=low;i--){
        sum=sum+A[i];
        if(sum>left_sum){
            left_sum=sum;
            max_left=i;
            max_suba[0]=max_left;
        }
    }

    right_sum=NEGA_INFINIT;
    sum=0;

    //index from mid+1 to high of right A subarray
    for(j=mid+1;j<=high;j++){
        sum=sum+A[j];
        if(sum>right_sum){
            right_sum=sum;
            max_right=j;
            max_suba[1]=max_right;
        }
    }

    max_suba[2]=(left_sum+right_sum);
    return max_suba;
}


/**********************************
 *
 * function find_maximum_subarray()
 *
 * args
 * A[] inttype array
 * low inttype the lower index of A
 * hihg inttype the high index of A
 *
 * return (int*) pointer
 * *pl
 * *pr
 * *pc
 * *max_suba
 *
*************************************/

int * find_maximum_subarray(int A[],int low,int high){

    int mid;
    int left_sum;
    int right_sum;
    int cross_sum;
    int *pl,*pr,*pc;
    int *max_suba;

    pl=(int*)malloc(sizeof(int*)*3);
    pr=(int*)malloc(sizeof(int*)*3);
    pc=(int*)malloc(sizeof(int*)*3);
    max_suba=(int*)malloc(sizeof(int*)*3);


    if(high==low){
        max_suba[0]=low;
        max_suba[1]=high;
        max_suba[2]=A[low];

        return max_suba;
    }
    else {
        mid=(low+high)/2;

        //left subarray of A
        pl=find_maximum_subarray(A,low,mid);
        left_sum=*(pl+2);

        //right subarray of A
        pr=find_maximum_subarray(A,mid+1,high);
        right_sum=*(pr+2);


        //crossing mid subarray of A
        pc=find_max_crossing_subarray(A,low,mid,high);

        cross_sum=*(pc+2);

        //left subarray of A
        if((left_sum>=right_sum)&&(left_sum>=cross_sum))
            return pl;
        else if((right_sum>=left_sum)&&(right_sum>=cross_sum))
            return pr;
        else
            return pc;
    }
}


int main()
{

    int A[16];
    int low=0,high=0;
    int *max_suba;
    char c;

    while (1) {
        scanf("%d",&A[high]);
        c=getchar();
        if(c=='\n')
            break;
        high++;
    }

    //use find_maximum_subarray()
    max_suba=find_maximum_subarray(A,low,high);
    printf("low: %d high: %d sum: %d\n",*max_suba,*(max_suba+1),*(max_suba+2));
    return 0;
}

/************************************************************
 *
 * input 13 -3 -25 20 -3 -16 -23 18 20 -7  12 -5 -22 15 -4 7
 *
 * output 18 20 -7 12 =======> low: 7 high: 10 sum: 43
 *
*************************************************************/
