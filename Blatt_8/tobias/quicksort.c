#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//befolgt nicht die Aufgabenstellung


int * randomarray(int size)
{
    int * array=(malloc(sizeof(int)*size));
    for(int i=0; i<size; i++)
    {
        array[i]=rand();
    }
    return array; 
}

void printarray(int * array, int size)
{
    for(int i=0; i<size; i++)
    {
        printf("%i\t", array[i]);
    }    
    return;
}

void ordnungsstichprobe(int * array, int size)
{
    int geordnet=1;

    for (int i=0; i<size-1; i++)
    {
        if (array[i]>=array[i+1])
        {
            geordnet=0;
        }
    }
    
    if (geordnet==1)
    {
        printf("\nist geordnet\n");
        return;
    }
    if (geordnet==0)
    {
        printf("\nist ungeordnet\n");
        return;
    }
}

void quick(int * array, int length)
{
    int l, r, pivot;
    pivot=length-1;
    l=0;
    r=pivot-1;
    int temp=0;
    while(l<r)
    {

        while(array[pivot]<array[r]&&r>=0)
        {
            r--;
        }
        while(array[pivot]>array[l]&&r<pivot)
        {
            l++;
        }

        if(l<r)
        {
            temp=array[l];
            array[l]=array[r];
            array[r]=temp;
        }   

    }

    if(array[l]>array[pivot]){
    temp=array[l];
    array[l]=array[pivot];
    array[pivot]=temp;
    }

    int length_l=r+1, length_r=length-l-1;

    if (length_r>1)
    {
        //quick(array+((l+1)*sizeof(int)), length_r); // hier die halben einfügen
        quick((array+l+1), length_r);
    }

    if (length_l>1)
    {
        quick(array, length_l);         
    }


    return;
}


int main()
{
    srand(time(NULL));

    int * array1=randomarray(1000);
    //printarray(array1, 1000);
    ordnungsstichprobe(array1, 1000);
    quick(array1,1000);


//    printarray(array1, 1000);

    ordnungsstichprobe(array1, 1000);  

    return 0;
}
