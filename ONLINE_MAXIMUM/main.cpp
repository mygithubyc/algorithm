#include <stdio.h>

#define NEGA_INFINITY -999999 //negative infinity

/***********************************************
 *
 * function online_maximum()
 *
 * args
 * socre inttype array of candidates ability
 * k inttype index of socre[] from 0 to n,[0,n)
 * n number of candidates
 *
 * return i inttype index of hired candidate
 *
 * ********************************************/
int online_maximum(int socre[],int k,int n){

    int bestsocre=NEGA_INFINITY;
    int i;

    //find candidates from 0 to k,[0,k]
    for(i=0;i<=k;i++)
        if(socre[i]>bestsocre)
            bestsocre=socre[i];

    //compare candidates from k+1 to n with bestsocre
    for(i=k+1;i<n;i++)
        if(socre[i]>bestsocre)
            return i;

    //return last index of candidate
    return n-1;
}


int main()
{

    // socre is randomize numbers of array
    int socre[10]={1,2,7,8,5,6,9,4,10,3};
    int i,n,k=4;

    n=sizeof(socre)/sizeof(int);
    i=online_maximum(socre,k,n);

    // use online_maximun()
    printf("hired candidate index: %d \n",i);

    return 0;
}
