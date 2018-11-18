//this program merge two linked list to one sorted linked list

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

typedef struct node{
  int data;
  struct node *next;
}node;

int flag=0;
node *globalRoot;
//random linked list generate 

node *randomlinkedlist(node *root, int length){
  flag++;
  printf("fonksiyon cagrildi %d uzunluk %d flag",length,flag);

  node *iter=root;
  for(int i=1; i<length; i++){
    node *temp=(node*)malloc(sizeof(node));
    temp->data=rand()%30;
    iter->next=temp;
    iter=iter->next;
    temp->next=NULL;
  }

  return root;
}

void print(node *iter){
  while(iter!=NULL){
    printf("%d\n",iter->data);
    iter=iter->next;
  }
}

node *sortinglinkedlist(node *root, int data){
  if(root==NULL){
    root=(node*)malloc(sizeof(node));
    root->data=data; root->next=NULL;
    return root;
  }
  else{
    node *temp=(node*)malloc(sizeof(node));
    if(root->data>data){
      temp->next=root; temp->data=data;
      return temp;
    }
    node *iter=root;
    while(iter->next->data<data && iter->next!=NULL){
      iter=iter->next;
    }
    if(iter->next==NULL){
      iter->next=temp; temp->next=NULL; temp->data=data;
      return root;
    }
    temp->next=iter->next;
    iter->next=temp; temp->data=data;
    return root;
  }
}

void deleteList(node *root){
  node *current=root,*next;
  while(current!=NULL){
    next=current->next;
    free(current);
    current=next;
  }
  
  root=NULL;
}


void *okuyan(node *root){
  node *iter=root;
  int counter=0;
  while(iter!=NULL){
    counter++;
    iter=iter->next;
  }
  
  iter=root;
  for(int i=0; i<counter; i++){
    globalRoot=sortinglinkedlist(globalRoot, iter->data);
    iter=iter->next;
  }

  deleteList(root);
}



int main(){
  srand(time(NULL));

  node *firstListRoot=(node*)malloc(sizeof(node));
  int length1=rand()%20+1; firstListRoot->data=rand()%1000;
  firstListRoot=randomlinkedlist(firstListRoot, length1);
  printf("\nFirst Linked list before merge\n");
  print(firstListRoot); //generate randomize linked list and print list

  node *secondListRoot=(node*)malloc(sizeof(node));
  int length2=rand()%20+1; secondListRoot->data=rand()%1000;
  secondListRoot=randomlinkedlist(secondListRoot, length2);
  printf("\nSecond Linked list before merge\n");
  print(secondListRoot); //samethings

  printf("\nAction Phase\n");
  okuyan(firstListRoot);
  okuyan(secondListRoot);
  print(globalRoot);
  
  return 0;
}