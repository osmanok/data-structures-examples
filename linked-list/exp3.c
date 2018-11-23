#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct academician{
  int registerNo;
  char *name;
  char *surname;
  int titleId;
  int titleYear;
  struct academician *next;
}academician;

//void initialsequetialinsertion();
void print(academician *root);

int main(){
  FILE *fp=fopen("exp3.txt","r");

  academician *root=NULL;

  while(!feof(fp)){
    academician *temp=(academician*)malloc(sizeof(academician));
    fscanf(fp, "%d", &temp->registerNo);
    fscanf(fp, "%s",  temp->name);
    fscanf(fp, "%s",  temp->surname);
    fscanf(fp, "%d", &temp->titleId);
    fscanf(fp, "%d", &temp->titleYear);

    printf("%d",temp->registerNo);

    //printf("%d",temp->registerNo);

    if(root==NULL){
      root=temp; root->next=NULL;
      printf("%d",root->titleId);
    }
    else{
      academician *iter=root;
      while(iter->next!=NULL) iter=iter->next;
      iter->next=temp;
      temp->next=NULL;
    }





    /*
    else{
      academician *iter=root;
      while(temp->titleId>iter->titleId && iter->next!=NULL){
        iter=iter->next;
      }

      if(root->titleId>temp->titleId){
        temp->next=root;
        root=temp;   
      }
      else if(iter->next==NULL){
        iter->next=temp; temp->next=NULL;
      }
      else{
        temp->next=iter->next;
        iter->next=temp;
      }
    }
    */
  }
  fclose(fp);

  return 0;
}

void print(academician *root){
  academician *iter=root;
  while(iter!=NULL){
    printf("%d\t",iter->titleId);
    iter=iter->next;
  }
}