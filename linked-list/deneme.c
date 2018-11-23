#include<stdio.h>
#include<stdlib.h>

typedef struct node{
  int data1;
  int data2;
  int data3;
  int data4;
  struct node *next;
}node;

int main(){
  FILE *fp=fopen("deneme.txt","r");
  
  while(!feof(fp)){
    node *temp=(node*)malloc(sizeof(node));

    fscanf(fp, "%d", &temp->data1);
    fscanf(fp, "%d", &temp->data2);
    fscanf(fp, "%d", &temp->data3);
    fscanf(fp, "%d", &temp->data4);

    printf("%d,%d\n",temp->data1,temp->data4);
    

  }

  fclose(fp);

  return 0;
}