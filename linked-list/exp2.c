//greatest common sivisor algorithm optimization

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int counter;

int randomint(){
  srand(time(NULL));
  return rand()%1000+1;
}

int * primalnumber(int number){
  int *primenumbersptr;
  
  for(int i=2; i<=number; i++){
    
  }
}

int cda(int x, int y){
  int min,flag=0;;
  if(x>y){
    min=y/2;
    counter=0;
    for(int i=min; i>=2; i++){
      counter++;
      if(x%i==0 && y%i==0){
        return counter;
      }
      if(flag==0){
        return 0;
      }
    }
  }
  if(y>x){
    min=x/2;
    counter=0;
    for(int i=min; i>=2; i++){
      counter++;
      if(x%i==0 && y%i==0){
        return counter;
      }
    }
  }
}

int main(){
  int number1,number2;

}