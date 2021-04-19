#include <stdio.h>

#define NAGE_INFINIT -99999

#define parent(i) i/2
#define left(i) 2*i+1
#define right(i) 2*i+2

//get array of A first element
int heap_maximum(int A[]){ return A[0];}


/***********************************************
 *
 * function max_heapify();
 *
 * args
 *  A[] inttype save elements of heap
 *  i index of A
 *  heap_size real length of A
 *
 * ********************************************/
void max_heapify(int A[],int i,int heap_size){

    int l,r,largest,temp;

    l=left(i);
    r=right(i);

    if((l<=heap_size)&&(A[l]>A[i]))
        largest=l;
    else
        largest=i;
    if((r<=heap_size)&&(A[r]>A[largest]))
        largest=r;

    if(largest!=i){
        temp=A[i];
        A[i]=A[largest];
        A[largest]=temp;

        max_heapify(A,largest,heap_size);
    }
}

/*********************************************
 *
 * function heap_extract_max()
 *
 * args
 *  A[] inttype save elements of heap
 *  heap_size inttype the real length of A
 *
 * return max the parent node value
 *
 * ******************************************/
int heap_extract_max(int A[],int heap_size){

    int max;
    if(heap_size<0)
        return -1;  //heap underflow

    max=A[0];   //parent node the max value of element
    A[0]=A[heap_size];
    heap_size--;

    /**************************************
     * dajust binary heap(or tree) to make
     * sure heap fo A true every times
     *
     * ************************************/
    max_heapify(A,0,heap_size);

    return max;

}

/***********************************************
 *
 * function heap_increase_key();
 *
 * args
 *  A[] inttype save elemnts of heap
 *  i index of A
 *  key inserted element
 *
 * *********************************************/
void heap_increase_key(int A[],int i,int key){

    int temp;

    if(key<A[i]){
        printf("new key is smaller than current key\n");
        return;     //over programming
    }

    A[i]=key;
    //p=parent(i);
    while ((i>0)&&(A[parent(i)]<A[i])) {
        temp=A[i];
        A[i]=A[parent(i)];
        A[parent(i)]=temp;

        i=parent(i); //update index of A
        //p=parent(i);
    }

}

/***************************************************
 *
 * function max_heap_insert();
 *
 * args
 *  A[] inttype save elements of A
 *  key inserted element to A
 *  heap_size real length of A
 *
 * **************************************************/
void max_heap_insert(int A[],int key,int heap_size){

    heap_size+=1;
    A[heap_size]=NAGE_INFINIT;

    heap_increase_key(A,heap_size,key);
}

int main()
{

    int heap_max,max,i,key;
    int A[11],Temp[11];
    int heap_size=0;
    char c;

    while (1) {

        scanf("%d",&A[heap_size]);
        c=getchar();
        if(c=='\n')
            break;
        heap_size++;
    }

    //copy A to Temp
    for(i=0;i<=heap_size;i++)
        Temp[i]=A[i];

    //get heap maximum element
    heap_max=heap_maximum(A);
    printf("heap of A maximum element: %d\n",heap_max);

    //copy Temp to A
    for(i=0;i<=heap_size;i++)
        A[i]=Temp[i];
    /*--extract maximum element--*/
    max=heap_extract_max(A,heap_size);
    printf("extract element: %d \n",max);
    printf("new heap of A after extract maximum node\n");
    for(i=0;i<heap_size;i++)
        printf("%d ",A[i]);
    printf("\n");   //next line

    //copy Temp to A
    for(i=0;i<=heap_size;i++)
        A[i]=Temp[i];
    /*--increase from A[i] to key--*/
    printf("input i key ");
    scanf("%d %d",&i,&key);
    heap_increase_key(A,i,key);
    for(i=0;i<=heap_size;i++)
        printf("%d ",A[i]);
    printf("\n");

    //copy Temp to A
    for(i=0;i<=heap_size;i++)
        A[i]=Temp[i];
    /*--insert queueu--*/
    key=0;  //init key;
    printf("input key: ");
    scanf("%d",&key);
    max_heap_insert(A,key,heap_size);
    for(i=0;i<=heap_size+1;i++)
        printf("%d ",A[i]);
    printf("\n");


    return 0;
}

/****************************************
 *
 * input 16 14 10 8 7 9 3 2 4 1
 *       i: 8
 *       key: 15
 *
 * output in function main()
 * **************************************/
