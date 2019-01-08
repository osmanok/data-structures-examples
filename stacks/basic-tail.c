#include<stdio.h>

#define length 100

typedef struct tails{
  int last;
  int arr[length];
}tail;

tail newTail;

void push(int var){
  newTail.last++;
  newTail.arr[newTail.last] = var;
}

int pop(){
  int pop_elm = newTail.arr[0];
  for(int i=1; i<=newTail.last; i++){
    newTail.arr[i-1] = newTail.arr[i];
  }
  newTail.last--;
  return pop_elm;
}

int main(int argc, char const *argv[]) {
  newTail.last = -1;

  return 0;
}
