#include<stdio.h>

int main()
{
    int  m,n,p1=1,p2=1;
    float evalu;
    unsigned short i;

    printf("\nEnter the Value of M & N:-");
    scanf("%d",&m);
    scanf("%d",&n);
    for(i=m;i>1;i--)
    {
        p1=p1*i;
    }
    for(i=n;i>1;i--)
    {
        p2=p2*i;
    }
   evalu = (p1+p2)/p2;
   
        
    printf("\nYour Answer:-%.2f",sqrt(evalu));

   return(0);
}
