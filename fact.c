#include<stdio.h>

int main()
{
    short n,p=1,i;
    printf("\nEnter no to Find Factorial:-");
    scanf("%u",&n);
    for(i=n;i>1;i--)
    {
        p = p*i;
    }
    printf("\nYour Answer:-%u",p);
    return(0);
}