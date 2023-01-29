#include"stdio.h"

void  print(int a){
  printf("\nValue:-%d",a);
  if(a==5){
    return;
  }
  print(++a);
}

int main(){
    print(1);
    return;
}