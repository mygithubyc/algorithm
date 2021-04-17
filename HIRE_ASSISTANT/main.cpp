#include <stdio.h>
#include<stdlib.h>

/**********************************
 *
 * function range_rand()
 *
 * arg
 *  i inttype randomize num lower
 *  n inttype randomize num upper
 *
 * return rand num
 *
 * ********************************/
int range_rand(int i,int n){

    int k;

    k=rand(); //rand num [0,n-1]
    k=k%n;
    //notice k=i maybe into a loop always and programing will exited by expition
    if(k<i)
        range_rand(i,n);
    return k;
}


/***************************************
 *
 * function randomize_in_place()
 *
 * args
 * A inttype array
 * n lenth of A
 *
 * return random A
 * *************************************/
int* randomize_in_place(int A[],int n){

    int i,k,temp;
    int *pa;

    //set pa pointer memory
    pa=(int*)malloc(n*sizeof(int));

    for(i=0;i<n;i++){

        //generate k is A's index range[i,n)
        k=range_rand(i,n);

        //swap A[i],A[K] to generate a list of A of candidate
        temp=A[i];
        A[i]=A[k];
        A[k]=temp;

    }

    pa=A;
    return pa;
}

/*****************************************************
 *
 * function randomize_hire_assistant();
 *
 * args
 *  Candidate inttype array
 *  n Candidate length
 *
 * ***************************************************/
void randomize_hire_assistant(int Candidate[],int n){

    int i,best=0; //candidate 0 is  at least-qulified
    int* pc=(int*)malloc(n*sizeof(int));

    pc=randomize_in_place(Candidate,n);
    //interview candidate i
    for(i=0;i<n;i++){
        //if candidate i is better than best
        if((*(pc+i))>best)
            best=*(pc+i);
    }

    //output all candidates
    for(i=0;i<n;i++)
        printf("%d ",*(pc+i));
    printf("\nthe best candidate is %d\n",best);
    free(pc);
    pc=NULL;

}


int main()
{
    int Can[10]={1,2,3,4,5,6,7,8,9,10};
    int n=sizeof(Can)/sizeof(int);
    //printf("n: %d\n",n);
    randomize_hire_assistant(Can,n);
    return 0;
}

/***************************************
 *
 * input Can[10]={1,2,3,4,5,6,7,8,9,10}
 *
 * output:
 *  randomize sequence Can[]
 *  best
 *
 * **************************************/
