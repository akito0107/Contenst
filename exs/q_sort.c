#include <stdio.h>
#include <stdlib.h>

#define LENGTH 200;

void q_sort(int* arr, int length);
void q_sort(int* arr, int start, int end);

int main(){

    int arr[10] = {9,5,6,3,2,7,8,1,0,11};

    int i = 0;
    for(i=0; i<10; i++)
        printf("%d,",arr[i]);

    q_sort(arr, 10);
}

void q_sort(int* arr, int length){

    if(length == 0) return;

    q_sort(arr, 0, length-1);
}

void q_sort(int* arr, int start, int end){

    if(end - start <= 0 ) return;

    int pivot = arr[(end+start)/2];

    int l = start;
    int r = end;
    
    int tmp;
    while(1){
        while(1){
            if(arr[l] > pivot){
                tmp = arr[l];
                break;
            }
            l++;
        }

        while(1){
            if(arr[r] <= pivot){

            }
        }
    }
}
