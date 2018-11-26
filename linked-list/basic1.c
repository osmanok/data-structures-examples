#include<stdio.h>
#include<stdlib.h>

typedef struct node{
  int num;  
  struct node *prev;
  struct node *next;
}node;

node *root=NULL,*end=NULL;

node *getData(){
  node *data=(node*)malloc(sizeof(node));
  printf("enter number:"); scanf("%d",&data->num);
  return data;
}

void insertionadd(node *data){
  if(root==NULL){
    root=data; root->prev=NULL;
    end=data; root->next=NULL;
  }
  else{
    if(root->num>data->num){
      data->next=root;
      root->prev=data;

      root=data;
    }

    else{
      node *iter=root;
      while(iter->num<data->num && iter!=end) iter=iter->next;

      if(iter==end){
        iter->next=data; data->prev=iter; data->next=NULL; end=data;
      }
      else{
        iter->prev->next=data;
        data->prev=iter->prev;
        iter->prev=data;
        data->next=iter;
      }
    }
  }
}

void print(node *root, node *end){
  node *iter=root;
  while(iter!=end){
    printf("%d\t",iter->num);
    iter=iter->next;
  }
  printf("%d\n",end->num);
}

node *search(int searchingNum){
  node *iter=root;
  while(iter!=NULL){
    if(iter->num==searchingNum) return iter;
    iter=iter->next;
  }
  return NULL;
}

void delete(int deletingNum){
  node *temp=search(deletingNum);
  if(temp=NULL) printf("\nThere is no wanted number in linked list.\n");
  else{
    if(temp==root){
      if(root==end){
        root=NULL; end=NULL;
      }
      else{
        root=root->next;
        root->prev=NULL;
      }
    }
    else{
      if(temp==end){
        end=end->prev;
        end->prev=NULL;
      }
      else{
        temp->prev->next=temp->next;
        temp->next->prev=temp->prev;
      }
    }
    free(temp);
  } 
}

int main(){
  
  return 0;
}