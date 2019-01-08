#include <stdio.h>
#include <stdlib.h>

typedef struct n{
    int data;
    struct n *sag,*sol;
}node;

void yazdir(node *root){
    if(root!=NULL){
        yazdir(root->sol);
        printf("%d ",root->data);
        yazdir(root->sag);
    }
}

node *ekle(node *agac, int sayi){
    if(agac==NULL){
        agac=(node*)malloc(sizeof(node));
        agac->data=sayi;
        agac->sag=NULL;
        agac->sol=NULL;
        return agac;
    }
    if(sayi > agac->data)
        agac->sag=ekle(agac->sag,sayi);
    else
        agac->sol=ekle(agac->sol,sayi);
    return agac;
}

int seviye_fark(int sayi1, int sayi2, node *agac){

  int seviye(int sayi, int cur_height, node *agac){
    if(agac->data == sayi){
      return cur_height;
    }
    if(agac->data > sayi){
      return seviye(sayi, cur_height+1, agac->sol);
    }
    if(agac->data < sayi){
      return seviye(sayi, cur_height+1, agac->sag);
    }
  }

  int seviye1, seviye2;
  seviye1 = seviye(sayi1, 0, agac);
  printf("%d\n", seviye1);
  seviye2 = seviye(sayi2, 0, agac);
  printf("%d\n", seviye2);
  return seviye1 - seviye2;
}

int main(int argc, char** argv) {
    node *agac=NULL;
    agac=ekle(agac,100);
    agac=ekle(agac,50);
    agac=ekle(agac,150);
    agac=ekle(agac,25);
    agac=ekle(agac,75);
    agac=ekle(agac,125);
    agac=ekle(agac,200);

    int deger;

    deger = seviye_fark(125, 100, agac);

    printf("%d\n", deger);

    return 0;
}
