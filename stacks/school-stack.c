#include<stdio.h>

#define stackLentgh 100

typedef struct Stacks{
  int index;
  int elemants[stackLentgh];
}stack;


stack push(int var, stack newStack) {
  if(newStack.index == stackLentgh - 1){
    printf("Stack is full\n");
  }
  else{
    newStack.elemants[++newStack.index] = var;
    return newStack;
  }
}

int pop(stack newStack){
  if(newStack.index == -1){
    printf("Stack is empty\n");
  }
  else{
    return newStack.elemants[newStack.index];
  }
}

int main(){
  stack newStack;
  newStack.index=-1;

  newStack=push(10, newStack);
  newStack=push(20, newStack);
  newStack=push(30, newStack);

  printf("%d\n",pop(newStack));
  newStack.index--;
  printf("%d\n",pop(newStack));
  newStack.index--;
  printf("%d\n",pop(newStack));
}
