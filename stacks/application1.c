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

stack hecadamiltobinary(int var){
    stack tempStack;

    int remaing;
    while(var > 0){
      remaing = var % 2;
      tempStack = push(remaing, tempStack);
      var = var / 2;
    }

    return tempStack;
}

void display(stack tempStack){
  while(tempStack.index >= 0){
    printf("%d", pop(tempStack));
    tempStack.index--;
  }
}

int main(){
  stack newStack = hecadamiltobinary(28);
  display(newStack);

  return 0;
}
