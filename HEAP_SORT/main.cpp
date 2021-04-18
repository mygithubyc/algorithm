#include <stdio.h>

//define index of left,right
#define index_left(i) 2*i+1
#define index_right(i) 2*i+2

/*****************************************************
 *
 * function max_heapify();
 *
 * args
 *  A inttype array of a heap elements
 *  i inttype index of A
 *  heap_szie the real length of input elements of A
 *            but heap_size=length-1,because of index
 *            from 0 to n-1
 *
 * ***************************************************/
void max_heapify(int A[],int i,int heap_size){

    int l,r,largest,temp;

    //calculate index of left and right child
    l=index_left(i);
    r=index_right(i);


    //index l,r compare with the  heap_size of A
    if((l<=heap_size)&&(A[l]>A[i]))
        largest=l;
    else
        largest=i;

    // right child
    if((r<=heap_size)&&(A[r]>A[largest]))
        largest=r;

    if(largest!=i){
        //exchange A[i] with A[largest]
        temp=A[i];
        A[i]=A[largest];
        A[largest]=temp;

        //use max_heapify()
        max_heapify(A,largest,heap_size);
    }
}

/*******************************************
 *
 * function build_max_heap();
 *
 * args
 *   A inttype array of heap elements
 *   heap_size inttype the length-1 of A
 *
 * ****************************************/
void build_max_heap(int A[],int heap_size){

    int i,len;

    len=heap_size;
    //heap_size=len-1;
    len=len/2;

    // index i=floor(n/2) to 0 decarese
    for(i=len;i>=0;i--)
        max_heapify(A,i,heap_size);
}

/****************************************
 *
 * function heap_sort();
 *
 * args
 *   A intype array of heap elements
 *   heap_size inttype length of A,but
 *   heap_size=A.length-1
 *
 * return *pa pointer of A[0]
 *
 * *************************************/
int* heap_sort(int A[],int heap_size){

    int i,len,temp;
    int *pa;

    build_max_heap(A,heap_size);
    len=heap_size;

    for(i=len;i>=1;i--){

        /*first element exchange with A[i]
         * to make sure the largest value of
         * child node on the parent node
         * */
        temp=A[0];
        A[0]=A[i];
        A[i]=temp;

        //decarese heap_size to move index of A
        heap_size--;

        // adjust max value to parent node
        max_heapify(A,0,heap_size);
    }

    pa=A;
    return pa;
}

int main()
{
    int i,len,A[10],heap_size=0;
    int* pa;

    char c;

    while(1){
        scanf("%d",&A[heap_size]);
        c=getchar();
        if(c=='\n')
            break;
        heap_size++;
    }

    //use heap_sort()
    pa=heap_sort(A,heap_size);

    // output A after sorted
    len=sizeof(A)/sizeof(int);
    for(i=0;i<len;i++)
        printf("%d ",*(pa+i));

    return 0;
}

/*************************************
 *
 * input A[]={16,14,10,8,7,9,3,2,4,1}
 *
 * output A[]={1,2,3,4,7,8,9,10,14,16}
 *
 * ***********************************/
