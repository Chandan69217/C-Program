#include<stdio.h>
#include<conio.h>
#define size 7
int main(){
 int num1[size];
 for(int i =0 ;i<=size;i++){
    printf("\nEnter a value:-");
    scanf("%d",&num1[i]);
 }

 for (int i = 0; i <= size; i++)
 {
    printf("\nvalue:-" ,num1[i]);
    
 }
}