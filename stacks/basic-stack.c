#include<stdio.h>

int MAXSIZE = 2;
int stack[2];
int top = 0;

void push(int data){
  stack[top++] = data;
}

int pop(){
  return stack[--top];
}

int main(){
  push(5);
  push(10);
  push(15);
  push(20);
  printf("%d\n", pop());
  printf("%d\n", pop());
  printf("%d\n", pop());
  printf("%d\n", pop());



  return 0;
}
