#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int globalcounter=0;

int *randomarr();
void printarr(int *arr);
void swap(int *x, int *y);
int *selectionsort(int *arr);
int *bubblesort1(int *arr);
int *bubblesort2(int *arr);
int *bubblesort3(int *arr, int length);
int *recursivebubblesort(int *arr, int length);
int *insertionsort(int *arr, int length);
void insertionSortRecursive(int *arr, int length);

int main(){
  int *array;
  array=randomarr();
  insertionSortRecursive(array, 100);
  printarr(array);

  printf("\n");

  return 0;
}

int *randomarr(){
  int *arr=(int*)malloc(sizeof(int)*100);
  srand(time(NULL));
  for(int i=0; i<100; i++){
    *(arr+i)=rand()%100;
  }
  return arr;
}

void printarr(int *arr){
  for(int i=0; i<100; i++){
    printf("%d ",*(arr+i));
  }
  printf("\n");
}

void swap(int *x, int *y){
  int temp;

  temp=*x;
  *x=*y;
  *y=temp;
}

int *selectionsort(int *arr){
  int min,temp;

  for(int i=0; i<99; i++){
    min=i;
    for(int j=i+1; j<100; j++){
      if(arr[min]>arr[j]){
        min=j;
      }
    }
    swap(&arr[i], &arr[min]);
  }

  return arr;
}

int *bubblesort1(int *arr){
  int counter=0,flag=1;
  while(flag){
    flag=0;
    for(int i=0; i<99; i++){
      if(arr[i]>arr[i+1]){
        swap(&arr[i], &arr[i+1]);
        flag=1;
        counter++;
      }
    }
  }
  printf("buble sort 1=%d",counter);
  return arr;
}

int *bubblesort2(int *arr){
  int flag=1,counter=0;
  for(int i=0; i<99; i++){
    flag=0;
    for(int j=0; j<99; j++){
      if(arr[j]>arr[j+1]){
        swap(&arr[j],&arr[j+1]);
        counter++;
        flag=1;
      }
    }
    if(flag==0){
      printf("bubble sort 2=%d",counter);
      break;
    }
  }

  return arr;
}

int *bubblesort3(int *arr, int length){
  int flag=1,counter=0;
  for(int i=0; i<length-1; i++){
    flag=0;
    for(int j=0; j<length-1; j++){
      if(arr[j]>arr[j+1]){
        swap(&arr[j],&arr[j+1]);
        globalcounter++;
        flag=1;
      }
    }
    if(flag==0){
      break;
    }
    length--;
  }

  return arr;
}

int *recursivebubblesort(int *arr, int length){
  if(length==1) return arr;
  for(int i=0; i<length-1; i++){
    if(arr[i]>arr[i+1]){
      swap(&arr[i], &arr[i+1]);
    }

    return recursivebubblesort(arr, length-1);
  }
}

int *insertionsort(int *arr, int length){
  int key,i,j;
  for(i=1; i<length; i++){
    key=arr[i];
    j=j-1;

    while(j>=0 && arr[j]>key){
      arr[j+1]=arr[j];
      j=j-1;
    }

    arr[j+1]=key;
  }

  return arr;
}

void insertionSortRecursive(int *arr, int length){
  if(length<=1) return;

  insertionSortRecursive(arr, length-1);

  int last=arr[length-1];
  int j=length-2;

  while(j>=0 && arr[j]>last){
    arr[j+1]=arr[j];
    j--;
  }
  arr[j+1]=last;
}