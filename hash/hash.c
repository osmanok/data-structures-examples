#include <stdio.h>
#include <stdlib.h>
//#define MAX_ROW 10;

typedef struct node{
    int data;
    int index;
    struct node *next;
}node;

node* table[10];

int hash_func(int data){
    return data%10;
}

void init_table(){
    for(int i=0; i<10; i++){
        table[i]->index=-1;
        table[i]->next=NULL;
    }
}

void insert(int data){
    int index_row=hash_func(data);
    if(table[index_row]->index==-1){
        table[index_row]->data=data;
        table[index_row]->index++;
    }
    //if collision its happen
    else{
        node *temp=(node*)malloc(sizeof(node));
        temp->data=data; temp->next=NULL;
        node *iter=table[index_row];
        while(iter->next!=NULL) iter=iter->next;
        iter->next=temp; temp->index=iter->index+1;
    }
}

void search(int data){
    printf("deneme");
    int index_row=hash_func(data);
    if(table[index_row]->data==data){
        printf("data find first element in hash table");
    }
    else{
        node *iter=table[index_row];
        while(iter!=NULL){
            if(iter->data==data){
                printf("data find %d element in hash table", iter->index);
                break;
            }
            iter=iter->next;
        }
    }
}

int main(){
    printf("deneme");
    init_table();
    printf("deneme");
    insert(22); insert(32); insert(12); insert(35);
    printf("deneme");
    search(22); search(12);

    printf("deneme");

    return  0;
}